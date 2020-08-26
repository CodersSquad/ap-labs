# word-reverser build & test automation

APP_NAME=month_day

build:
	gcc ${APP_NAME}.c -o ${APP_NAME}.o
test: build
	@echo Test 1
	./${APP_NAME}.o 2040 156
	@echo Test 2
	./${APP_NAME}.o 2000 366
	@echo Test 3
	./${APP_NAME}.o 1900 400
	@echo Test 4
	./${APP_NAME}.o 1799 100
	@echo Test 5
	./${APP_NAME}.o 70 175
clean:
	rm -rf *.o
