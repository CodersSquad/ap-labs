#include <stdio.h>
#include "strlib.c"


int main(int argc, char **argv){
    switch(argc){
        case 2:
        printf("Initial Length      : %d\n", mystrlen(argv[1]));
        break;
        case 3:
        printf("Initial Length      : %d\n", mystrlen(argv[1]));
        printf("New String          : %s\n", mystradd(argv[1], argv[2]));
        break;
        case 4:
        printf("Initial Length      : %d\n", mystrlen(argv[1]));
        printf("New String          : %s\n", mystradd(argv[1], argv[2]));
        if(mystrfind(argv[1], argv[3]) == 1){
            printf("SubString was found : yes\n");
        } else {
            printf("SubString was found : no\n");
        }
        break;
        
            }
    return 0;
}
