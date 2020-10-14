# word-reverser build & test automation

APP_NAME=monitor
LIB_NAME=logger
build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc    ${LIB_NAME}.o ${APP_NAME}.o  -o ${APP_NAME}
test: build
	 @echo Test 1
	sudo ./${APP_NAME} /tmp
	@echo Test 2
	./${APP_NAME} ${HOME}
	@echo Test 3
	./${APP_NAME} $(PWD)
	@echo Test 4 - failed
	./${APP_NAME}

clean:
	rm -rf *.o ${APP_NAME}
