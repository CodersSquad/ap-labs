#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

int main(int argc, char **argv){
	int isValid;

	isValid = argc > 1;
	if (isValid) {
		printf("%d\n", atoi(argv[1]));
		switch(atoi(argv[1])) {
		case 1:
		// default logging
		infof("INFO Message %d", 1);
		warnf("WARN Message %d", 2);
		errorf("ERROR Message %d", 2);
		break;
		case 2:
		// stdout logging
		initLogger("stdout");
		infof("INFO Message %d", 1);
		warnf("WARN Message %d", 2);
		errorf("ERROR Message %d", 2);
		break;
		case 3:
		// syslog logging
		initLogger("syslog");
		infof("INFO Message %d", 1);
		warnf("WARN Message %d", 2);
		errorf("ERROR Message %d", 2);
		break;
		default:
		errorf("Invalid test case");
		break;
		}
	} else {
		errorf("Must have an integer argument to test.");
	}

    return 0;
}
