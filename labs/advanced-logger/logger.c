#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include "logger.h"

#define INFO "INFO"
#define WARN "WARN"
#define ERROR "ERROR"
#define PANIC "PANIC"
#define LOG_FILE "loggerLogs"

#define RESET 0
#define BRIGHT 1

#define BLACK 0
#define RED 1
#define YELLOW  3
#define BLUE  4
#define MAGENTA 5

void resetTerminalColor();
void setTerminalColor(int attr, int b);
void formatString(char *s, const char *format, int ls, char *sf, int lf);
void writeToLog(char *s, int mode);

// One is syslog, 0 is stdout
int isLog = 0;

int initLogger(char *logType) {
    if (strcmp(logType, "syslog") == 0) {
        printf("Initializing Logger on: %s\n", logType);
        isLog = 1;
    } else {
        if (strcmp(logType, "stdout") == 0 || strlen(logType) == 0) {
            isLog = 0;
        } else {
            errorf("Not a valid argument, got '%s'", logType);
        }
    }
    return 0;
}

int infof(const char *format, ...) {
    va_list arg;
    size_t l, lInfo;
    char *s;
    int done, i;

    lInfo = strlen(INFO) + 2;
    l = strlen(format);
    s = (char *) malloc(l + 2 + lInfo);
    formatString(s, format, l, INFO, lInfo);

    va_start(arg, format);
    if (isLog) {
        printf("Writting to syslog INFO...\n");
        openlog(LOG_FILE, LOG_PID, LOG_USER);
        syslog(LOG_INFO, format, arg);
        closelog();
    } else {
        setTerminalColor(RESET, BLUE);
        done = vfprintf(stdout, s, arg);
        resetTerminalColor();
    }
    
    free(s);
    va_end(arg);
    return done;
}

int warnf(const char *format, ...) {
    va_list arg;
    size_t l, lWarn;
    char *s;
    int done, i;

    lWarn = strlen(WARN) + 2;
    l = strlen(format);
    s = (char *) malloc(l + 1 + lWarn);
    formatString(s, format, l, WARN, lWarn);

    va_start(arg, format);
    done = 0;
    if (isLog) {
        printf("Writting to syslog WARN...\n");
        openlog(LOG_FILE, LOG_PID, LOG_USER);
        syslog(LOG_WARNING, format, arg);
        closelog();
    } else {
        setTerminalColor(RESET, YELLOW);
        done = vfprintf(stdout, s, arg);
        resetTerminalColor();
    }
    free(s);
    va_end(arg);
    return done;
}

int errorf(const char *format, ...) {
    va_list arg;
    size_t l, lInfo;
    char *s;
    int done, i, a;

    lInfo = strlen(ERROR) + 2;
    l = strlen(format);
    s = (char *) malloc(l + 1 + lInfo);
    formatString(s, format, l, ERROR, lInfo);

    va_start(arg, format);
    if (isLog) {
        printf("Writting to syslog ERROR...\n");
        openlog(LOG_FILE, LOG_PID, LOG_USER);
        syslog(LOG_ERR, format, arg);
        closelog();
    } else {
        setTerminalColor(RESET, RED);
        done = vfprintf(stdout, s, arg);
        resetTerminalColor();
    }
    free(s);
    va_end(arg);
    return done;
}

int panicf(const char *format, ...) {
    va_list arg;
    size_t l, lInfo;
    char *s;
    int done, i;

    lInfo = strlen(PANIC) + 2;
    l = strlen(format);
    s = (char *) malloc(l + 1 + lInfo);
    formatString(s, format, l, PANIC, lInfo);

    va_start(arg, format);
    if (isLog) {
        printf("Writting to syslog PANIC...\n");
        openlog(LOG_FILE, LOG_PID, LOG_USER);
        syslog(LOG_CRIT, format, arg);
        closelog();
    } else {
        setTerminalColor(RESET, MAGENTA);
        done = vfprintf(stdout, s, arg);
        resetTerminalColor();
    }
    free(s);
    va_end(arg);
    return done;
}

void formatString(char *s, const char *format, int ls, char *sf, int lf) {
    int i;

    for (i = 0; i < lf-1; i++) {
        s[i] = sf[i];
    }
    s[lf-2] = ':';
    s[lf-1] = ' ';
    for (i = lf; i < ls + lf; i++) {
        s[i] = format[i-lf];
    }
    s[ls+lf] = '\n';
    s[ls+lf+1] = '\0';
}

void setTerminalColor(int attr, int t) {
    char command[13];
    sprintf(command, "%c[%d;%d;1m", 0x1B, attr, t + 30);
    printf("%s", command);
}

void resetTerminalColor() {
    char command[13];
    sprintf(command, "%c[%d;0;0m", 0x1B, RESET);
    printf("%s", command);
}
