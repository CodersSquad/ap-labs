#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <syslog.h>

#define RESET 0
#define BRIGHT 1
#define DIM 2
#define UNDERLINE 3
#define BLINK 4
#define REVERSE 7
#define HIDDEN 8

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

int mysyslog = 0;
int status = 0;

int initLogger(char *logType)
{
    if (strcmp(logType, "syslog") == 0)
    {
        mysyslog = 1;
        printf("Initializing Logger on: %s\n", logType);
    }
    else if (strcmp(logType, "") == 0 || strcmp(logType, "stdout") == 0)
    {
        printf("Initializing Logger on: stdout\n");
    }
    else
    {
        printf("Not proper value");
        return 1;
    }
    return 0;
}

void textcolor(int attr, int fg, int bg)
{
    char command[13];

    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
}

int infof(const char *format, ...)
{
    textcolor(BRIGHT, BLUE, BLACK);
    va_list arg;
    va_start(arg, format);

    if (mysyslog == 1)
    {
        openlog("logger", LOG_PID | LOG_CONS, LOG_SYSLOG);
        vsyslog(LOG_INFO, format, arg);
        closelog();
    }
    else
    {
        vprintf(format, arg);
        printf("\n");
    }

    va_end(arg);
    textcolor(RESET, WHITE, BLACK);
    return 0;
}

int warnf(const char *format, ...)
{
    textcolor(BRIGHT, YELLOW, BLACK);
    va_list arg;
    va_start(arg, format);

    if (mysyslog == 1)
    {
        openlog("logger", LOG_PID | LOG_CONS, LOG_SYSLOG);
        vsyslog(LOG_WARNING, format, arg);
        closelog();
    }
    else
    {
        vprintf(format, arg);
        printf("\n");
    }

    va_end(arg);
    textcolor(RESET, WHITE, BLACK);
    return 0;
}

int errorf(const char *format, ...)
{
    textcolor(BRIGHT, RED, BLACK);
    va_list arg;
    va_start(arg, format);

    if (mysyslog == 1)
    {
        openlog("logger", LOG_PID | LOG_CONS, LOG_SYSLOG);
        vsyslog(LOG_ERR, format, arg);
        closelog();
    }
    else
    {
        vprintf(format, arg);
        printf("\n");
    }

    va_end(arg);
    textcolor(RESET, WHITE, BLACK);
    return 0;
}

int panicf(const char *format, ...)
{
    textcolor(BRIGHT, WHITE, RED);
    va_list arg;
    va_start(arg, format);

    if (mysyslog == 1)
    {
        openlog("logger", LOG_PID | LOG_CONS, LOG_SYSLOG);
        vsyslog(LOG_EMERG, format, arg);
        closelog();
    }
    else
    {
        vprintf(format, arg);
        printf("\n");
    }

    va_end(arg);
    textcolor(RESET, WHITE, BLACK);
    raise(SIGABRT);
    return 0;
}