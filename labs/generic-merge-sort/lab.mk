# word-reverser build & test automation

APP_NAME=generic_merge_sort

build:
	gcc ${APP_NAME}.c -o ${APP_NAME}.o
test: build
	@echo Test 1 - sort numbers
	./${APP_NAME}.o -n numbers.txt
	@echo Test 2 - sort strings
	./${APP_NAME}.o strings.txt
	@echo Test 3 - handle missing parameters
	./${APP_NAME}.o
	@echo Test 4 - handle incomplete parameters
	./${APP_NAME}.o -n
clean:
	rm -rf *.o
