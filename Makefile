all: build
build: lab6v4.c MyLib.c
	gcc -Wall -O0 -g3 -DDEBUG -pedantic-errors -std=c89 lab6v4.c MyLib.c -o programm
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm		