#include <stdio.h>
int infof ( const char * format, ... );
int warnf ( const char * format, ... );
int errorf ( const char * format, ... );
int panicf ( const char * format, ... );

int main(){
    char *message = "hello";


    infof("This is a %s log",message);
    warnf("This is a %s warning",message);
    errorf("This is a %s error",message);
    panicf("Alert, this is a %s panic", message);




    return 0;

}