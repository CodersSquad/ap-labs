#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int DEBUG = 0;
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
void *playerMonitor(void *args);


int main(int argc, char **argv)
{
    DEBUG = argc > 1? 1 : 0;
    RUNNING = 1;

    printf("How many enemies do you want? ");
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
}