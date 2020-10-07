#include <stdio.h>
#include "logger.h"

int initLogger(char *logType) {
    printf("Initializing Logger on: %s\n", logType);
    return 0;
}

int infof(const char *format, ...) {
    return 0;
}

int warnf(const char *format, ...) {
    return 0;
}

int errorf(const char *format, ...) {
    return 0;
}
int panicf(const char *format, ...) {
    return 0;
}
