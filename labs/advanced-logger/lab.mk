# word-reverser build & test automation

APP_NAME=testLogger
LIB_NAME=logger
build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc    ${LIB_NAME}.o ${APP_NAME}.o  -o ${APP_NAME}
test: build
	 @echo Test 1
	./${APP_NAME} 1
	@echo Test 2
	./${APP_NAME} 2
	@echo Test 3
	./${APP_NAME} 3
	@echo Test 4 - invalid test
	./${APP_NAME} 4
	@echo Test 5 - failed
	./${APP_NAME}

clean:
	rm -rf *.o ${APP_NAME}
