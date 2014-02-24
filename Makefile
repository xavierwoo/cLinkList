main.exe: main.o cLinkList.o
	gcc -o main.exe main.o cLinkList.o
main.o: main.c
	gcc -g -c main.c
cLinkList.o: cLinkList.c cLinkList.h
	gcc -g -c cLinkList.c