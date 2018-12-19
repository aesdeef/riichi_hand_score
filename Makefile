score.o: score.c score.h
	gcc -c score.c

score.out: score.o
	gcc score.o -o score.out