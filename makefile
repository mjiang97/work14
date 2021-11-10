all: work14.o
	gcc -o program work14.o
work13.o: work14.c
	gcc -c work14.c
run: 
	./program
clean: 
	rm *.o
	rm program