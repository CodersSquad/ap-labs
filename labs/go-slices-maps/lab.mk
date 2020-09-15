# build & test automation

build:
	go build maps.go
	go build slices.go
	go get golang.org/x/tour/pic

test: build
	@echo Test 1 - maps.go
	./maps
	@echo Test 2 - slices.go
	./slices

clean:
	rm -rf maps slices
