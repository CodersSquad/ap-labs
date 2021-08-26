# build & test automation

APP_NAME=calculator

build:
	gcc ${APP_NAME}.c -o ${APP_NAME}.o
test: build
	@echo Test 1
	./${APP_NAME}.o add 1 43 52 3 5 2 23 23 23 25 45 32 74 || true
	@echo Test 2
	./${APP_NAME}.o sub 34 23 52 2 1 534 23 || true
	@echo Test 3
	./${APP_NAME}.o mult 3 6 73 3 || true
	@echo Test 4
	./${APP_NAME}.o 13 34 64 23 hello || true
	@echo Test 5
	./${APP_NAME}.o div 23 23 5 23 || true
clean:
	rm -rf *.o
