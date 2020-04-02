functions.o: functions.c
	gcc functions.c -c

main.o: main.c
	gcc main.c -c

a.out: main.o functions.o
	gcc main.o functions.o

run: a.out
	./a.out
	
clean:
	rm -f a.out main.o functions.o

