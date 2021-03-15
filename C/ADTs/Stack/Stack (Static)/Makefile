objects = main.o stack.o
binaryObjects = decimalToBinary.o stack.o

main: $(objects)
	gcc -o main.out $(objects)

binary:	$(binaryObjects) 
	gcc -o decimalToBinary.out $(binaryObjects)

stack.o: stack.h
main.o: stack.h
binary.o: stack.h
	gcc -c decimalToBinary.c

clean:
	rm *.o main.out