# build & test automation

build:
	go build geometry.go

test: build
	@echo Test 1 - 2 sides - failed test
	./geometry
	@echo Test 2 - 4 sides
	./geometry 4
	@echo Test 3 - 8 sides
	./geometry 8
	@echo Test 3 - 12 sides
	./geometry 12

clean:
	rm -rf geometry
