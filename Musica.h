#ifndef Musica_H
#define Musica_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct sequencia{
    int *notas, tamanho;
} sequencia;

void leitor_de_arquivo(sequencia*, sequencia*, FILE*);
void limpeza(sequencia*);
void gravador(int);
int comparador(int, int);
int forca_bruta(sequencia*, sequencia*);

#endif