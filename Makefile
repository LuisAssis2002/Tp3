all: tp3

tp3: tp3.c Musica.o
	gcc tp3.c Musica.o -o tp3

Musica.o: Musica.c Musica.h
	gcc -c Musica.c

clean:
	rm Musica.o
	rm tp3