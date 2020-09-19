# build & test automation

build:
	go get golang.org/x/tour/pic
	go get golang.org/x/tour/wc
	go build maps.go
	go build slices.go

test: build
	@echo Test 1 - maps.go
	./maps
	@echo Test 2 - slices.go
	./slices

clean:
	rm -rf maps slices
