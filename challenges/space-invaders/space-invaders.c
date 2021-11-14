#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> //time()

int main()
{
    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = 'A';
    char playerLaser = '^';
    char enemy = 'M';
    char enemyShielded = 'O';
    char enemyLaser = 'U';
    char explosion = 'X';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

    srand(time(NULL));

    /*welcome screen*/
    printf("\n \n     Welcome soldier! \n \n \n \n");
    Sleep(1000);
    printf("  Brave the COMMAND PROMPT INVADERS and come back a hero. \n \n \n \n");
    Sleep(2500);
    printf("  Your operating system is depending upon you. \n \n \n \n");
    Sleep(2500);
    printf("               Good luck.");
    Sleep(1000);
    printf("\n \n \n \n Press any key to start.");
    getch();

    /*initialise world*/
    int totalEnemies = 0;
    //for each space
    for (x = 0; x < sizex; x ++) {
        for (y = 0; y < sizey; y ++) {
            //If y is not pair, y is less than 7, x is more than 4, x is less than sizex - 5 and x is pair. 
            //The space is limited to the world.
            if ((y+1) % 2 == 0 && y < 7 && x > 4
            && x < sizex - 5 && x % 2 ==0) {
                world[y][x] = enemy;
                totalEnemies ++;
            }
            else if ((y+1) % 2 == 0 && y >= 7 && y < 9 && x > 4
            && x < sizex - 5 && x % 2 ==0){
                world[y][x] = enemyShielded;
                totalEnemies = totalEnemies + 2;
            }
            else {
                world[y][x] = ' ';
            }
        }
    }
    world[sizey - 1][sizex / 2] = player;
    int i = 1;
    char direction = 'l';
    char keyPress;
    int currentEnemies = totalEnemies;
    while(currentEnemies > 0 && victory) {
        int drop = 0;
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady ++;

        /*display world*/
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

        /*laser time*/
        for (x = 0; x < sizex; x ++) {
            for (y = sizey-1; y >= 0; y --) {
                if (i%2 == 0 && world[y][x] == enemyLaser
                && (world[y+1][x] != enemy & world[y+1][x] != enemyShielded)){
                world[y+1][x] = enemyLaser;
                world[y][x] = ' ';
                }
                else if (i%2 == 0 && world[y][x] == enemyLaser
                && (world[y+1][x] == enemy | world[y+1][x] == enemyShielded)){
                    world[y][x] = ' ';
                }
            }
        }
        for (x = 0; x < sizex; x ++) {
            for (y = 0; y < sizey; y ++) {
                if ((i % 5) == 0 && (world[y][x] == enemyShielded
                | world[y][x] == enemy) && (rand() % 15) > 13
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