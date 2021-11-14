
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> //time()

//this object is used to store the position of the a enemy and wheter it is alive or not
//have a default constructor initalizing x and y to 0 and alive to 1
struct enemy{
    int x;
    int y;
    int alive;
}def_enemy = {-1, -1, 2};

//ths function will recieve a enemy and return a String with x and y of the enemy and wheter it is alive or not
//the function will return a string with the following format:
//"x:y:alive"
char* enemy_to_string(struct enemy e){
    char* str = (char*)malloc(sizeof(char)*10);
    sprintf(str, "%d:%d:%d", e.x, e.y, e.alive);
    return str;
}

struct enemy *getEnemy(struct enemy *enemies, int x, int y){
        //this variable is used to store the index of the enemy in the array
        int index = 0;
        //this variable is used to store the enemy object
        struct enemy *enemy = NULL;
        //this loop will iterate through the enemies array
        for (int i = 0; i < 3; i++)
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

int main()
{
    //this method will recieve x and y coordinates and return the enemy object from the enemy array

    

    //this method will add two numbers and return the result
    int add(int a, int b){
        return a + b;
    }
    printf("%d\n", add(1, 2));
    //this variable will hold 3 enemies
    struct enemy enemies[3];
    enemies[0].x = 1;
    enemies[0].y = 1;
    enemies[0].alive = 1;
    enemies[1] = def_enemy;
    enemies[2] = *getEnemy(enemies,1, 1);
    //print enemies[0]
    printf("%s\n",enemy_to_string(enemies[0]));
    printf("%s\n",enemy_to_string(enemies[1]));
    printf("%s\n",enemy_to_string(*getEnemy(enemies,1, 1)));
    
    


    
}