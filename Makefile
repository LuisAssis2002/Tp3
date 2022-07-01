all: tp3

tp3: tp3.c Musica.o ShiftAndExato.o KMP.o BMH.o
	gcc tp3.c Musica.o ShiftAndExato.o KMP.o BMH.o -lm -o tp3

Musica.o: Musica.c Musica.h
	gcc -c Musica.c

ShiftAndExato.o: ShiftAndExato.c ShiftAndExato.h
	gcc -c ShiftAndExato.c

KMP.o: KMP.c KMP.h
	gcc -c KMP.c
	
BMH.o: BMH.c BMH.h
	gcc -c BMH.c

clean:
	rm Musica.o
	rm ShiftAndExato.o
	rm KMP.o
	rm BMH.o
	rm tp3