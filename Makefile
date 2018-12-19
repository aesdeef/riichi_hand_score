score.o: score.c score.h
	gcc -c score.c

score.out: score.o
	gcc score.o -lm -o score.out
