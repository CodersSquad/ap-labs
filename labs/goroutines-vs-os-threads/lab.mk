# build & test automation

build:
	go build pipeline.go
	go build ping-pong.go

test: build
	@echo Test 1 - pipeline.go
	./pipeline
	@echo Test 2 - ping-pong.go
	./ping-pong

clean:
	rm -rf pipeline ping-pong
