# word-reverser build & test automation

APP_NAME=static-linking
LIB_NAME=strlib
EXE_NAME=main

build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc ${APP_NAME}.o ${LIB_NAME}.o -o ${EXE_NAME}.o
test: build
	@echo Test 1 - addition
	./${EXE_NAME}.o -add "Initial String " "This is the rest to be added" 
	@echo Test 2 - find
	./${EXE_NAME}.o -find "This is a super long string" "super long"
	@echo Test 3 - failed addition
	./${EXE_NAME}.o -add "Initial String"
	@echo Test 4 - failed find
	./${EXE_NAME}.o -find "This is my super long string"
clean:
	rm -rf *.o
