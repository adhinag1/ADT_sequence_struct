FLAG= -g -std=gnu11 -w

all: program5.c data.h list.c list.h vector.c vector.h profile.c profile.h
	gcc $(FLAG) program5.c -o program5

run: all
	./program5

checkmem: all
	valgrind ./program5

clean:
	rm program5