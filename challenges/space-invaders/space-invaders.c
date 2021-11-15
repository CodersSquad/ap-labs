#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <pthread.h>
#include <windows.h>
#include <time.h> //time()
//this definintion ENEMY_QUANTITY in 80 
#define ENEMY_QUANTITY 80
/*int DEBUG = 0;
int RUNNING;

int score = 0;
int lives = 10;
int enemies = 0;

int playerX = 17;
int board[31][12];

void initBoard();
void drawBoard();
void drawUI(int debug);
void *enemyBehaviour(void *args);
void *enemyBulletThread(void *args);
void *playerBulletThread(void *args);
void *playerMonitor(void *args); */

//this object is used to store the position of the a enemy and wheter it is alive or not
struct enemy
{
    int x;
    int y;
    int alive;
}def_enemy = {-1, -1, 1};

//this method will recieve a array of enemies and coordinates and return the enemy object from the enemy array
struct enemy *getEnemy(struct enemy *enemies, int x, int y)
    {
        //this variable is used to store the index of the enemy in the array
        int index = 0;
        //this variable is used to store the enemy object
        struct enemy *enemy = NULL;
        //this loop will iterate through the enemies array
        for (int i = 0; i < ENEMY_QUANTITY; i++)
        {
            //this if statement will check if the enemy is alive
            if (enemies[i].alive == 1)
            {
                //this if statement will check if the enemy is in the same position as the coordinates
                if (enemies[i].x == x && enemies[i].y == y)
                {
                    //this variable is used to store the index of the enemy in the array
                    index = i;
                    //this variable is used to store the enemy object
                    enemy = &enemies[index];
                    //this break statement will break the loop
                    break;
                }
            }
        }
        //this return statement will return the enemy object
        return enemy;
    }

//ths function will recieve a enemy and return a String with x and y of the enemy and wheter it is alive or not
//the function will return a string with the following format:
//"x:y:alive"
char* enemy_to_string(struct enemy e){
    char* str = (char*)malloc(sizeof(char)*10);
    sprintf(str, "%d:%d:%d", e.x, e.y, e.alive);
    return str;
}

int main(){
    /*                                  Hice esto para dibujar el board por si sirve de algo :D y 
    DEBUG = argc > 1? 1 : 0;                                         y
    RUNNING = 1;

    printf("How many enemies do you want? ");    preguntarle al usuario sobre cuantos enemigos quiere
    scanf("%d", &enemies);

    pthread_t monitor;
    pthread_create(&monitor, NULL, playerMonitor, NULL);

    initBoard();
    while (RUNNING)
    {
        if (lives == 0){
            RUNNING = 0;
            printf("GAME OVER!\n");
            break;
        } else if(enemies == 0)
        {
            RUNNING = 0;
            printf("Congratulations, You won!\n");
            break;
        } else{
            usleep(50000);
            drawUI(DEBUG);
        }
    }
    

    return 0;
}


void initBoard()
{
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 12; j++)
            board[i][j] = 0;

    int spawner = enemies;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 31; j++)
            if (spawner > 0 && board[j][i] == 0)
            {
                pthread_t enemy;
                int pos[2] = {j, i};
                pthread_create(&enemy, NULL, enemyBehaviour, (void *)&pos);
                spawner--;
                usleep(10000);
            }


    board[playerX - 1][11] = 1;
}


void drawBoard()
{
    printf("\n\n|-------------------------------|\n");
    for (int j = 0; j < 12; j++)
    {
        printf("|");
        for (int i = 0; i < 31; i++)
            printf("%d", board[i][j]);
        printf("|\n");
    }
    printf("|-------------------------------|\n");
}


void drawUI(int debug)
{
    system("clear");
    printf("\n|-------------------------------|\n");
    printf("|         Space Invaders        |\n");
    printf("|-------------------------------|\n");
    printf("|Lives: %d\tScore: %d\t|\n", lives, score);
    printf("|-------------------------------|\n");
    for (int j = 0; j < 12; j++)
    {
        printf("|");
        for (int i = 0; i < 31; i++)
        {
            if (board[i][j] == 1)
                printf("^");
            else if (board[i][j] == 2)
                printf("T");
            else if (board[i][j] == 3)
                printf(".");
            else if (board[i][j] == 4)
                printf("|");
            else
                printf(" ");
        }
        printf("|\n");
    }
    printf("|-------------------------------|\n");
    if (debug)
        drawBoard();
} 

void *enemyBehaviour(void *args)
{
    float enemySpeed = 1.0;

    int *pos = (int *)args;
    int y = pos[1];
    int x = pos[0];

    int shoots = 3;

    board[x][y] = 2;
    while (y < 12)
    {
        int shoot = 0;

        if(shoots == 3){
            shoot = rand()%3;
            shoots = 0;
        }
        else
            shoots++;

        usleep(enemySpeed*1000000);

        if(board[x][y] != 2){
            score++;
            enemies--;
            board[x][y] = 0;
            break;
        }
        
        if(y == 11){
            y = pos[1];
            board[x][11] = 0;
            board[x][y] = 2;
        } else {
            board[x][y++] = 0;
            board[x][y] = 2;
        }

        

        if(shoot == 2 && y<11){
            pthread_t bullet;
            int bulletPos[2] = {x, y};
            pthread_create(&bullet, NULL, enemyBulletThread, (void *)&bulletPos);
        }
        
    }
    board[x][y] = 0;
    pthread_exit(NULL);
}


void *enemyBulletThread(void *args)
{
    int actual, next;

    float bulletSpeed = 0.5;

    int *pos = (int *)args;
    int y = pos[1] + 1;
    int x = pos[0];
    
    board[x][y] = 3;
    while (y < 11)
    {
        usleep(bulletSpeed*1000000);
        actual = board[x][y];
        next = board[x][y+1];

        if(next == 0){
            board[x][y+1] = 3;
        } else if(next == 1){
            lives--;
            if(lives == 0)
                board[x][y+1] = 0;
        } 

        if(actual == 3)
            board[x][y] = 0;

        
        if(next!=3){
            y++;
        }
    }

    usleep(bulletSpeed*1000000);
    if(next == 0){
        board[x][y] = 0;
    }

    pthread_exit(NULL);
}


void *playerBulletThread(void *args)
{
    float bulletSpeed = 0.25;

    int y = 10;
    int x = *(int *)args;

    while (y > -1)
    {  
        if (board[x][y] != 2)
        {
            board[x][y] = 4;
            usleep(bulletSpeed*1000000);

            if (board[x][y] == 2){
                score++;
                enemies--;
                board[x][y] = 0;
                break;
            }
            board[x][y] = 0;
            y--;
            if (y > 0)
                board[x][y] = 4;
        }
        
    }

    pthread_exit(NULL);
}

void *playerMonitor(void *args)
{
    while (RUNNING)
    {
        system("stty -icanon");
        char c = getchar();
        if (c == 'a' && playerX > 1)
        {
            if (board[playerX - 2][11] == 3)
            {
                if (lives > 1)
                    lives--;
                else
                {
                    lives--;
                    board[playerX - 1][11] = 0;
                }
            }
            //Free Place on board
            board[playerX - 1][11] = 0;
            playerX--;
            //Ocupied by User
            board[playerX - 1][11] = 1;
        }
        else if (c == 'd' && playerX < 31)
        {
            if (board[playerX][11] == 3)
            {
                if (lives > 1)
                    lives--;
                else
                {
                    lives--;
                    board[playerX - 1][11] = 0;
                }
            }
            //Free Place on board
            board[playerX - 1][11] = 0;
            playerX++;
            //Ocupied by User
            board[playerX - 1][11] = 1;
        }
        else if (c == ' ' && board[playerX - 1][10] != 3)
        {
            pthread_t bullet;
            int pos = playerX - 1;
            pthread_create(&bullet, NULL, playerBulletThread, (void *)&pos);
        }
        else if (c == 'c' && board[playerX - 1][1] != 3)
        {
            pthread_t bullet;
            int pos[2] = {16, 0};
            pthread_create(&bullet, NULL, enemyBulletThread, (void *)&pos);
        }
        system("stty cooked");
    }
    return NULL;
}*/

    //this variable is used to store enemys is an array.
    struct enemy enemies[ENEMY_QUANTITY];
    
    
    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex]; 
    char player = 'A'; //A is the player
    char playerLaser = '^'; //^ is the player's laser
    char enemy = 'M'; //M is the enemy
    char enemyShielded = 'O'; //O is the enemy's shielded
    char enemyLaser = 'U'; //U is the enemy's laser
    char explosion = 'X'; //X is the explosion
    int score = 0; 
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

    srand(time(NULL));

    /*welcome screen*/
    printf("\n \n     Welcome soldier! \n \n \n \n");
    Sleep(10);
    printf("  Brave the COMMAND PROMPT INVADERS and come back a hero. \n \n \n \n");
    Sleep(10);
    printf("  Your operating system is depending upon you. \n \n \n \n");
    Sleep(10);
    printf("               Good luck.");
    Sleep(10);
    printf("\n \n \n \n Press any key to start.");
    getch();

    /*initialise world*/
    int totalEnemies = 0; //Variable to store the total number of enemies. ****Currently obsolete****
    
    //initialise the enemys array with enemies with coordinates between sizex and sizey-10
    for (int i = 0; i < ENEMY_QUANTITY; i++)
    {
        enemies[i].x = rand() % (sizex) + 1;
        enemies[i].y = rand() % (sizey - 10) + 1;
        enemies[i].alive = 1;
        totalEnemies++;
    }
    //initialise the world with empty spaces
    for (y = 0; y < sizey; y++){
        for (x = 0; x < sizex; x++){
            world[y][x] = ' ';
        }
    }
    //iterate enemys array and write the enemies in the world else write a space
    for (int i = 0; i < ENEMY_QUANTITY; i++)
    {
        if (enemies[i].alive == 1)
        {
            world[enemies[i].y][enemies[i].x] = enemy;
        }
    }
    
    world[sizey - 1][sizex / 2] = player;
    int i = 1;                            //al chile no sé que es eso
    char direction = 'l';
    char keyPress;
    int currentEnemies = ENEMY_QUANTITY;
    while(currentEnemies > 0 && victory) {
        int drop = 0;
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady ++;

        //handling world, score and enemies
        system("cls");
        printf("SCORE:    %d", score);
        printf("\n");
            for (y = 0; y < sizey; y ++) {
            printf("|");
                for (x = 0; x < sizex; x ++) {
                    printf("%c",world[y][x]);
                }
            printf("|");
            printf("\n");
            }

        //handling enemy projectile
        for (x = 0; x < sizex; x ++) {
            for (y = sizey-1; y >= 0; y --) {
                //if there is no enemy or enemyShielded below the position of the enemy projectile
                //write the projectile below and erase the projectile below
                //else write a space
                if (world[y][x] == enemyLaser && (world[y+1][x] != enemy 
                & world[y+1][x] != enemyShielded)){
                    world[y+1][x] = enemyLaser;
                    world[y][x] = ' ';
                }
                //else projectile is erased
                else if (world[y][x] == enemyLaser && (world[y+1][x] == enemy 
                | world[y+1][x] == enemyShielded)){
                    world[y][x] = ' ';
                }
            }
        }
        //handling if enemy is ready
        for (x = 0; x < sizex; x ++) {
            for (y = 0; y < sizey; y ++) {
                //if there is an enemy or enemyShielded in the position and 
                //there is no a playerLaser below the position of the projectile
                if (
                (world[y][x] == enemyShielded | world[y][x] == enemy) 
                && (rand () % 11) > 9
                && world[y+1][x] != playerLaser) {
                    for (yi = y+1; yi < sizey; yi ++) {
                        if (world[yi][x] == enemy
                        | world[yi][x] == enemyShielded) {
                            enemyReady = 0;
                            break;
                        }
                        enemyReady = 1;
                    }
                    if (enemyReady) {
                        world[y+1][x] = enemyLaser;
                    }
                }
                if (world[y][x] == playerLaser && world[y-1][x] == enemy) {
                    world[y][x] = ' ';
                    world[y-1][x] = explosion;
                    currentEnemies --;
                    score = score + 50;
                }
                else if (world[y][x] == playerLaser
                && world[y-1][x] == enemyShielded) {
                    world[y][x] = ' ';
                    world[y-1][x] = enemy;
                    currentEnemies --;
                    score = score + 50;
                }
                else if (world[y][x] == playerLaser
                && world[y-1][x] == enemyLaser) {
                    world[y][x] = ' ';
                }
                else if (world[y][x] == explosion) {
                    world[y][x] = ' ';
                }
                else if ((i+1) % 2 == 0 && world[y][x] == enemyLaser
                && world[y+1][x] == player) {
                    world[y+1][x] = explosion;
                    world[y][x] = ' ';
                    victory = 0;
                }
                else if (world[y][x] == playerLaser
                && world[y-1][x] != enemyLaser) {
                        world[y][x] = ' ';
                        world[y-1][x] = playerLaser;
                }
            }
        }

        /*update enemy direction*/
        for (y = 0; y < sizey; y ++) {
            if (world[y][0] == enemy) {
                direction = 'r';
                drop = 1;
                break;
            }
            if (world[y][sizex-1] == enemy){
                direction = 'l';
                drop = 1;
                break;
            }
        }

        /*update board*/
        if (i % enemySpeed == 0) {
            if (direction == 'l') {
                for (x = 0; x < sizex - 1; x ++) {
                    for (y = 0; y < sizey; y ++) {
                        if (drop && (world[y-1][x+1] == enemy
                            || world[y-1][x+1] == enemyShielded)){
                            world[y][x] = world[y-1][x+1];
                            world[y-1][x+1] = ' ';
                        }
                        else if (!drop && (world[y][x+1] == enemy
                            || world[y][x+1] == enemyShielded)) {
                            world[y][x] = world[y][x+1];
                            world[y][x+1] = ' ';
                        }
                    }
                }
            }
            else {
                for (x = sizex; x > 0; x --) {
                    for (y = 0; y < sizey; y ++) {
                        if (drop && (world[y-1][x-1] == enemy
                            || world[y-1][x-1] == enemyShielded)) {
                            world[y][x] = world[y-1][x-1];
                            world[y-1][x-1] = ' ';
                        }
                        else if (!drop && (world[y][x-1] == enemy
                            || world[y][x-1] == enemyShielded)) {
                            world[y][x] = world[y][x-1];
                            world[y][x-1] = ' ';
                        }
                    }
                }
            }
            for (x = 0; x < sizex; x ++) {
                if (world[sizey - 1][x] == enemy) {
                    victory = 0;
                }
            }
        }

        /*control player*/
        if(kbhit()){
            keyPress = getch();
        }
        else {
            keyPress = ' ';
        }
        if (keyPress == 'a') {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[sizey-1][x+1] == player) {
                    world[sizey-1][x] = player;
                    world[sizey-1][x+1] = ' ';
                }
            }
        }

        if (keyPress == 'd') {
            for (x = sizex - 1; x > 0; x = x-1) {
                if ( world[sizey-1][x-1] == player) {
                    world[sizey-1][x] = player;
                    world[sizey-1][x-1] = ' ';
                }
            }
        }
        if (keyPress == 'm' && laserReady > 2) {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[sizey-1][x] == player) {
                    world[sizey - 2][x] = playerLaser;
                    laserReady = 0;
                }
            }
        }
        i ++;
        Sleep(50);
    }
    system("cls");
        printf("     SCORE:    %d", score);
        printf("\n");
            for (y = 0; y < sizey; y ++) {
            printf("|");
                for (x = 0; x < sizex; x ++) {
                    printf("%c",world[y][x]);
                }
            printf("|");
            printf("\n");
            }
    Sleep(1000);
    system("cls");
    if (victory != 0) {
        printf("\n \n \n \n \n \n               CONGRATULATIONS! \n \n \n \n \n");
        Sleep(1000);
        printf("\n \n               Score: %d", score);
        Sleep(1000);
        int bonus = totalEnemies*20 - i;
        printf("\n \n               Bonus: %d", bonus);
        Sleep(1000);
        printf("\n \n               Total Score: %d", score + bonus);
        printf("\n \n \n \n               Well done");
        Sleep(1000);
        printf(", Hero.");
        Sleep(1000);
        getch();
    }
    else {
        printf("\n \n \n \n \n \n               You have failed.");
        Sleep(1000);
        printf("\n \n \n \n \n \n               Windows is doomed.");
        Sleep(1000);
        printf("\n \n               Final Score: %d", score);
        getch();
    }
}
