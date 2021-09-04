#include <stdio.h>
#include <stdlib.h>

/* month_day function's prototype*/
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char *months[12] = {
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
};

int main(int argc, char **argv) {
    int pday;
    int pmonth;
    if(argc > 2){
        //check days are no more than 366
       
        month_day(atoi(argv[1]), atoi(argv[2]), &pmonth, &pday);
        if(pmonth != -1){
            printf("%s %d, %s\n", months[pmonth], pday, argv[1]);
        }else{
            printf("Not a valid date\n");
            return 0;
        } 
        return 0;
    }
    printf("Not enough arguments\n");
    return -1;
}

//year and yearday are from argv
//*pmonth and *pday will be returned as result
void month_day(int year, int yearday, int *pmonth, int *pday){
    //Checks if leap year
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(leap == 0 && yearday <= 365 || leap == 1 && yearday <= 366){
       //gets date of year
        for(int i = 0; i < 12; i++){
            if(yearday <= daytab[leap][i]){
                *pmonth = i;
                *pday = yearday;
                break;
            }else{
                yearday -= daytab[leap][i];
            }
        }    
    }else{
        *pmonth = -1;
    }
}