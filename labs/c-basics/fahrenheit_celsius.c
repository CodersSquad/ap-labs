#include <stdio.h>
#include <stdlib.h>

#define   LOWER  0       /* lower limit of table */
#define   UPPER  300     /* upper limit */
#define   STEP   20      /* step size */

/* print Fahrenheit-Celsius table */

int main(int argc, char **argv)
{
    int fahr;

    if(argc==2){
      fahr=atoi(argv[1]);
      printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    else{
      int start = atoi(argv[1]);
      int end = atoi(argv[2]);
      int stepp = atoi(argv[3]);
      for (fahr = start; fahr <= end; fahr = fahr + stepp)
	  printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

    return 0;
}
