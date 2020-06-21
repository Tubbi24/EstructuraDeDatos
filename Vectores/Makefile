vector.o: vector.c
	gcc vector.c -c

main.o: main.c
	gcc main.c -c

a.out: main.o vector.o
	gcc main.o vector.o

run: a.out
	./a.out
	
clean:
	rm -f a.out main.o vector.o

