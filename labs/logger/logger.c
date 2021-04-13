#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>


int infof ( const char * format, ... )
{
    //time
    time_t rwtime;
    struct tm * info;
    time (&rwtime);
    info = localtime (&rwtime);
    char *timeStr= asctime(info);
    timeStr[strlen(timeStr)-1] = 0;

    //color text
    printf("\x1b[34m");

    //list of arguments
    va_list args;
    va_start (args, format);
    printf("INFO[%s]: ",timeStr);

    vprintf (format, args);
    printf("\n");
    va_end (args);

    printf("\x1b[0m");
    
    return 1;
}

int warnf ( const char * format, ... )
{
    //time
    time_t rwtime;
    struct tm * info;
    time (&rwtime);
    info = localtime (&rwtime);
    char *timeStr= asctime(info);
    timeStr[strlen(timeStr)-1] = 0;

    //color text
    printf("\x1b[33m");

    //list of arguments
    va_list args;
    va_start (args, format);
    printf("WARNING[%s]: ",timeStr);

    vprintf (format, args);
    printf("\n");
    va_end (args);

    printf("\x1b[0m");
    
    return 1;
}

int errorf ( const char * format, ... )
{
    //time
    time_t rwtime;
    struct tm * info;
    time (&rwtime);
    info = localtime (&rwtime);
    char *timeStr= asctime(info);
    timeStr[strlen(timeStr)-1] = 0;

    //color text
    printf("\x1b[31m");

    //list of arguments
    va_list args;
    va_start (args, format);
    printf("ERROR[%s]: ",timeStr);

    vprintf (format, args);
    printf("\n");
    va_end (args);

    printf("\x1b[0m");
    
    return 1;
}

int panicf ( const char * format, ... )
{
    //time
    time_t rwtime;
    struct tm * info;
    time (&rwtime);
    info = localtime (&rwtime);
    char *timeStr= asctime(info);
    timeStr[strlen(timeStr)-1] = 0;

    //color text
    printf("\x1b[36m");

    //list of arguments
    va_list args;
    va_start (args, format);
    printf("PANIC[%s]: ",timeStr);

    vprintf (format, args);
    printf("\n");
    va_end (args);

    printf("\x1b[0m");
    
    return 1;
}
