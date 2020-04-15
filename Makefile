all: build run clear
build: lab6v4.c MyLib.c
	gcc -Wall -O0 -g3 -DDEBUG -pedantic-errors -std=c89 lab6v4.c MyLib.c -o programm.exe
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm.exe
