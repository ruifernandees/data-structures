objects = main.o stack.o

main: $(objects)
	gcc -o main.out $(objects)

stack.o: stack.h
main.o: stack.h

clean:
	rm *.o main.out