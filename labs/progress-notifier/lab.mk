# word-reverser build & test automation

APP_NAME=base64
LIB_NAME=logger

build:
	gcc -c ${APP_NAME}.c -o ${APP_NAME}.o
	gcc -c ${LIB_NAME}.c -o ${LIB_NAME}.o
	gcc    ${LIB_NAME}.o ${APP_NAME}.o  -o ${APP_NAME}

files:
	curl -Ok http://textfiles.com/stories/vgilante.txt
	curl -Ok http://textfiles.com/stories/sick-kid.txt
	curl -Ok http://textfiles.com/stories/aesop11.txt
	head -c 2147483648 </dev/urandom > megafile.txt

test: build files
	 @echo Test 1
	./${APP_NAME} --encode vgilante.txt
	./${APP_NAME} --decode vgilante-encoded.txt
	@echo Test 2
	./${APP_NAME} --encode sick-kid.txt
	./${APP_NAME} --decode sick-kid-encoded.txt
	@echo Test 3
	./${APP_NAME} --encode aesop11.txt
	./${APP_NAME} --decode aesop11-encoded.txt
	@echo Test 4 - megafile - 2 Gb
	./${APP_NAME} --encode megafile.txt
	./${APP_NAME} --decode megafile-encoded.txt
	@echo Test 5 - failed test
	./${APP_NAME} --decode non-existing-file.txt

clean:
	rm -rf *.o ${APP_NAME} *-encoded.txt vgilante.txt sick-kid.txt aesop11.txt megafile.txt
