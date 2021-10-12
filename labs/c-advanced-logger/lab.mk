# word-reverser build & test automation

APP_NAME=testLogger
LIB_NAME=logger
EXEC_NAME=main

build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc ${APP_NAME}.o ${LIB_NAME}.o -o ${EXEC_NAME}
test: build
	@echo Test 1 - default
	./${EXEC_NAME} 1 || true
	@echo Test 2 - stdout
	./${EXEC_NAME} 2 || true
	@echo Test 3 - syslog
	./${EXEC_NAME} 3 || true
	@echo Test 4 - Invalid case
	./${EXEC_NAME} 4 || true
clean:
	rm -rf *.o ${EXEC_NAME}
