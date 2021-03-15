main: main.o fraction.o
	gcc -o main.out main.o fraction.o

main.o: main.c fraction.h
	gcc -c main.c

fraction.o: fraction.c fraction.h
	gcc -c fraction.c

clean:
	rm *.o main.out