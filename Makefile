all: tp3

tp3: tp3.c Musica.o ShiftAndExato.o
	gcc tp3.c Musica.o ShiftAndExato.o -lm -o tp3

Musica.o: Musica.c Musica.h
	gcc -c Musica.c

ShiftAndExato.o: ShiftAndExato.c ShiftAndExato.h
	gcc -c ShiftAndExato.c

clean:
	rm Musica.o
	rm ShiftAndExato.o
	rm tp3