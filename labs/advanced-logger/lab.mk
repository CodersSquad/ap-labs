# word-reverser build & test automation

APP_NAME=testLogger
LIB_NAME=logger
EXE_NAME=main

build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc ${APP_NAME}.o ${LIB_NAME}.o -o ${EXE_NAME}.o
test: build
	@echo Test 1 - default
	./${EXE_NAME}.o 1
	@echo Test 2 - stdout
	./${EXE_NAME}.o 2
	@echo Test 3 - syslog
	./${EXE_NAME}.o 3
	@echo Test 4 - Invalid case
	./${EXE_NAME}.o 4
clean:
	rm -rf *.o
