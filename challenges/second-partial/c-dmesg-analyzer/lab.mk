# build & test automation

APP_NAME=dmesg-analyzer
DMESG_TXT=dmesg.txt

build:
	gcc ${APP_NAME}.c -o ${APP_NAME}
test: build
	@echo Test 1
	./${APP_NAME} ${DMESG_TXT} || true
	@echo Test 2
	./${APP_NAME} || true
	make clean
clean:
	rm -rf ${APP_NAME}
