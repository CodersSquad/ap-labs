// Este código se implementó con un poco de ayuda de un artículo relacionado encontrado en programador clic.
// Una disculpa maestro, no logré acabarlo porque lo hice a último día y acepto las consecuencias, aunque ojalá y pudiera ganar algunos puntos por lo que alcance a resolver, ¡saludos!

#include <stdio.h>
#include <stdlib.h>

static char dayT[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
char *months(int n) {
    static char *names[] = { 
        "Jan", "Feb", "Mar", 
        "Apr", "May", "Jun", 
        "Jul", "Aug", "Sept", 
        "Oct", "Nov", "Dec"
    };
    return (n<1||n>12) ? names[0] : names[n];
}

/* month_day function's prototype*/
void month_day(int year, int yearday, int *pmonth, int *pday){
    char *p;
    
    if(year<1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    
    int flag = (year%4==0 && year%100!=0) || year%400==0;
    p = dayT[flag];
    int i = 1;  
    while(yearday>*++p) {
        yearday -= *p;
        i++;
        if(i>12) {
            *pmonth = -1;
            *pday = -1;
            return;
        }
    }

    *pmonth = i+1;
    *pday = yearday;
}

int main(void) {
    int year, yearday, pday, pmonth;
    month_day(year, yearday, &pmonth, &pday);
    char* months_names = months(pmonth);
    printf("%s %d, %d\n", months_names, pday, year);
    return 0;
}