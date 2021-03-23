# build & test automation

build:
	go build geometry.go

test: build
	@echo Test 1 - 2 points - failed test
	./geometry 2
	@echo Test 2 - 4 points
	./geometry 4
	@echo Test 3 - 8 points
	./geometry 8
	@echo Test 4 - 12 points
	./geometry 12

clean:
	rm -rf geometry
