main.exe: main.o cLinkList.o
	gcc -o main.exe main.o cLinkList.o
main.o: main.c
	gcc -Wall -g -c main.c
cLinkList.o: cLinkList.c cLinkList.h
	gcc -Wall -g -c cLinkList.c