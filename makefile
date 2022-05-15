all: pendu.exe test.exe
	echo "comilation tnaket"

test.exe: pendu.o test.o
	gcc pendu.o test.o -o test.exe

pendu.exe: pendu.o main.o
	gcc pendu.o main.o -o pendu.exe

pendu.o: pendu.c pendu.h
	gcc -c pendu.c

main.o: main.c pendu.h
	gcc -c main.c

test.o: test.c pendu.h
	gcc -c test.c