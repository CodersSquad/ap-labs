# word-reverser build & test automation

build:
	gcc reverser.c -o reverser.o
test: build
	@echo Running manual input test
	./reverser.o
clean:
	rm -rf *.o
