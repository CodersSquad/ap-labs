# build & test automation

APP_NAME=genericsort

build:
	gcc -c quicksort.c -o quicksort.o
	gcc -c mergesort.c -o mergesort.o
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc quicksort.o mergesort.o ${APP_NAME}.o -o ${APP_NAME}
test: build
	@echo Test 1 - sort numbers quick sort
	./${APP_NAME} -n numbers.txt -quicksort -o qs_sorted_numbers.txt || true
	@echo Test 2 - sort strings merge sort
	./${APP_NAME} strings.txt -mergesort -o ms_sorted_strings.txt || true
	@echo Test 3 - sort strings - quick sort
	./${APP_NAME} strings.txt -quicksort -o qs_sorted_strings.txt || true
	@echo Test 4 - handle missing parameters
	./${APP_NAME} || true
	@echo Test 5 - handle incomplete parameters
	./${APP_NAME} -n || true
clean:
	rm -rf *.o ${APP_NAME}
