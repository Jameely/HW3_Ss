make all: array_num.o string.o mainar.o mainst.o do_string.exe do_sort.exe


array_num.o: array_num.c array_num.h 
	gcc -c array_num.c -o array_num.o

string.o: string.c string.h
	gcc -c string.c -o string.o

mainar.o: main.c  
	gcc -c main.c -o mainar.o

mainst.o: mains.c 
	gcc -c mains.c -o mainst.o

do_string.exe: mainst.o string.o 
	gcc mainst.o string.o -o txtfind

do_sort.exe : array_num.o mainar.o
	gcc array_num.o mainar.o -o isort

isort : isort
	./isort

txtfind : txtfind
	./txtfind

clean: 
	@rm *.o txtfind isort


