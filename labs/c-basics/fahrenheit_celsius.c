#include <stdio.h>
#include <stdlib.h>

#define   LOWER  0       /* lower limit of table */
#define   UPPER  300     /* upper limit */
#define   STEP   20      /* step size */

/* print Fahrenheit-Celsius table */

int main(int argc, char** argv)
{
    int fahr;
    int start = strtol(argv[1],NULL,10);
    int end = strtol(argv[2],NULL,10);
    int increment = strtol(argv[1],NULL,10);

    for (fahr = start; fahr <= end; fahr = fahr + increment)
	printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}
