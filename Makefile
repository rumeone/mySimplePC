
bin/prog: build/main.o build/draw.o build/func.o lib/libmyTerm.a lib/libmybigChars.a lib/libmyReadkey.a bin
	gcc build/main.o build/draw.o build/func.o -L./lib -lmyTerm -L./lib -lmybigChars -L./lib -lmyReadkey -lm -o bin/prog


lib/libmyTerm.a: build/myTerm.o lib
	ar rc lib/libmyTerm.a build/myTerm.o

lib/libmyReadkey.a: build/myReadkey.o lib
	ar rc lib/libmyReadkey.a build/myReadkey.o

build/main.o: src/main.c src/func.h src/myTerm.h src/bigChars.h build
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/func.o: src/func.c src/func.h build
	gcc -Wall -Werror -c src/func.c -o build/func.o 

build/myTerm.o: src/myTerm.c src/myTerm.h build
	gcc -Wall -Werror -c src/myTerm.c -o build/myTerm.o

build/bigChars.o: src/bigChars.c src/bigChars.h src/myTerm.h build
	gcc -Wall -Werror -c src/bigChars.c -o build/bigChars.o

build/myReadkey.o: src/myReadkey.c src/myReadkey.h build
	gcc -Wall -Werror -c src/myReadkey.c -o build/myReadkey.o

build/draw.o: src/draw.c src/bigChars.h src/myTerm.h src/func.h src/myReadkey.h build
	gcc -Wall -Werror -c src/draw.c -o build/draw.o

build: 
	mkdir build

bin:
	mkdir bin

lib:
	mkdir lib

clean: 
	rm -rf bin build lib *.bin

.PHONY: all clean 
