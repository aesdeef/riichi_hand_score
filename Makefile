score.o: score.o score.h
	gcc -c score.o

score.out: score.o
	gcc score.o -o score.out