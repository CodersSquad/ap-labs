# matrix-multiplication build & test automation

APP_NAME =multiplier
LIB_NAME =logger
CC      = gcc
CFLAGS  = -Wall -lpthread


data_files:
	curl -Ok https://storage.googleapis.com/classify-share/matA.dat
	curl -Ok https://storage.googleapis.com/classify-share/matB.dat

build:
	$(CC) $(CFLAGS) -c ${APP_NAME}.c -o ${APP_NAME}.o
	$(CC) $(CFLAGS) -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	$(CC) $(CFLAGS)  ${LIB_NAME}.o ${APP_NAME}.o  -o ${APP_NAME}

test: build data_files
	 @echo Test 1
	./${APP_NAME} -n 100 -out result_test1.txt
	@echo Test 2
	./${APP_NAME} -n 200 -out result_test2.txt
	@echo Test 3
	./${APP_NAME} -n 400 -out result_test3.txt
	@echo Test 4
	./${APP_NAME} -n 800 -out result_test4.txt
	@echo Test 5
	./${APP_NAME} -out result_test4.txt -n 100

clean:
	rm -rf *.o ${APP_NAME} *.dat
