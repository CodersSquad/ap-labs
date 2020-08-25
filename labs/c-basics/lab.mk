# word-reverser build & test automation

build:
	gcc fahrenheit_celsius.c -o fahrenheit_celsius.o
test: build
	@echo Test1
	./fahrenheit_celsius.o 100
	@echo Test2
	./fahrenheit_celsius.o 0 200 10
	@echo Test3
	./fahrenheit_celsius.o 0 100 20
clean:
	rm -rf *.o
