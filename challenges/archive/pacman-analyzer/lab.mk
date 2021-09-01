# word-reverser build & test automation

APP_NAME=pacman-analyzer

build:
	gcc ${APP_NAME}.c -o ${APP_NAME}.o
test: build
	@echo Test 1
	./${APP_NAME}.o -input pacman.txt -report packages_report.txt
	@echo Test 2
	./${APP_NAME}.o -input pacman2.txt -report packages_report2.txt
	@echo Test 3 - failed test
	./${APP_NAME}.o -input pacman3.log -report packages_report2.txt
	@echo Test 4 - failed test
	./${APP_NAME}.o -output packages_report2.txt

clean:
	rm -rf *.o
