FLAG= -g -std=gnu11 -w

all: main.c data.h list.c list.h vector.c vector.h profile.c profile.h
	gcc $(FLAG) main.c -o main

run: all
	./main

checkmem: all
	valgrind ./main

clean:
	rm main
