# build & test automation

APP_NAME=monitor
LIB_NAME=logger

build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc    ${LIB_NAME}.o ${APP_NAME}.o  -o ${APP_NAME}

test1: build
	 @echo Test 1
	sudo ./${APP_NAME} /tmp
test2: build
	@echo Test 2
	./${APP_NAME} ${HOME}
test3: build
	@echo Test 3
	./${APP_NAME} $(PWD)
test4: build
	@echo Test 4 - failed
	./${APP_NAME}

clean:
	rm -rf *.o ${APP_NAME}
