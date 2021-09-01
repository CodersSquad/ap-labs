# build & test automation

APP_NAME=geometry

build:
	go build -o ${APP_NAME} ${APP_NAME}.go

test: build
	@echo Test 1 - 2 points
	./${APP_NAME} 2 | true
	@echo Test 2 - 4 point
	./${APP_NAME} 4 | true
	@echo Test 3 - 8 points
	./${APP_NAME} 8 | true
	@echo Test 4 - 12 points
	./${APP_NAME} 12 | true
	@echo Test 5 - no points
	./${APP_NAME} | true
	make clean

clean:
	rm -rf ${APP_NAME}
