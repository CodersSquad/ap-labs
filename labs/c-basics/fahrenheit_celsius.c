#include <stdio.h>

#define   LOWER  0       /* lower limit of table */
#define   UPPER  300     /* upper limit */
#define   STEP   20      /* step size */

/* print Fahrenheit-Celsius table */

int main(int argc, char **argv)
{
    if (argc == 2){
    printf("Fahrenheit: %3d, Celcius: %6.1f\n", atoi(argv[1]), (5.0/9.0)*(atoi(argv[1])-32));


  } else if (argc == 4){
    int fahr, lower, upper, stepnext
    lower = atoi(argv[1]);
    upper = atoi(argv[2]);
    next = atoi(argv[3]);


     for (fahr = lower; fahr <= upper; fahr = fahr + next)
	printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
	
    return 0;
}
