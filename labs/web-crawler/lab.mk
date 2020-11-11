# build & test automation

APP_NAME=web-crawler

build:
	go get gopl.io/ch5/links
	go build -o ${APP_NAME} ${APP_NAME}.go

test: build
	@echo Test 1
	./${APP_NAME} -depth=2 -results=test1.txt https://google.com/
	@echo Test 2
	./${APP_NAME} -depth=3 -results=test2.txt http://www.gopl.io/
	@echo Test 3
	./${APP_NAME} -depth=1 -results=test3.txt http://www.gopl.io/
	@echo Test 4 - failed
	./${APP_NAME} http://www.gopl.io/

clean:
	rm -rf ${APP_NAME} *.txt
