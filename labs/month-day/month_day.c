#include <stdio.h>
#include <stdlib.h>

//Here i differentiate between lead and non leap years 
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* month_day function's prototype (given)*/
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (int i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *moth_name(int n) {
  static char *name[] = {
    "Invalid", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };
  return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char **argv) {
  // Place your magic here
  if (argc < 3) {
    printf("Send year and year day, calculate moth");
    return 1;
  }
  int year, yearday, month, day;
  year = atoi(argv[1]);
  yearday = atoi(argv[2]);
  month_day(year, yearday, &month, &day);
  char *mon = moth_name(month);
  printf("%s %d, %d \n", mon, day, year);
  return 0;
}
