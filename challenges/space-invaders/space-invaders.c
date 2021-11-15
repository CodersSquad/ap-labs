#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> //time()
//this definintion ENEMY_QUANTITY in 80 
#define ENEMY_QUANTITY 80

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
