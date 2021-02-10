# build & test automation

APP_NAME=test-lab

test:
	@echo Test 1 - single name scenario
	go run ./${APP_NAME}.go buddy
	@echo Test 2 - failed scenario
	go run ./${APP_NAME}.go
	@echo Test 3 - full name scenario
	go run ./${APP_NAME}.go Best Buddy Ever
