#ifndef KMP_H
#define KMP_H
#include "Musica.h"

typedef struct dfa{
    int *masc;
    int *potencias;
} dfa;

dfa* cria_dfa(sequencia* , sequencia* , dfa*);
int KMP(sequencia* , dfa* , int);
void limpeza_dfas(dfa* , int);

#endif