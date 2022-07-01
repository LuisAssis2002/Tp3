#include "KMP.h"

dfa* cria_dfa(sequencia *arranjo1, sequencia *arranjo2, dfa *D){
    D = (dfa*) malloc(arranjo1->tamanho * sizeof(dfa));
    int aux, ant, rep = 0, k = 0;
    for(int i = 0; i < arranjo1->tamanho; i++){
        D[i].potencias = (int*) malloc(arranjo2->tamanho * sizeof(int));
        D[i].masc = (int*) malloc(arranjo2->tamanho * sizeof(int));
        ant = -6;
        rep = 0;
        for(int j = 0; j < arranjo2->tamanho; j++){
            aux = comparador(arranjo1->notas[i], arranjo2->notas[j]);
            D[i].potencias[j] = aux;
            if((j == rep) && (aux != -6)) rep++;
            if(aux == -6) D[i].masc[j] = 0;
            if(aux != -6){
                D[i].masc[j] = j + 1;
                k++;
            }
            if((aux == -6) && (ant != -6)){
                if(rep <= (k + 1)) D[i].masc[j] = rep;
                else D[i].masc[j] = k + 1;
                k = 0;
            }
            ant = aux;
        }
    }
    return D;
}

int KMP(sequencia *arranjo1, dfa *D, int m){
    int aux, aux2, ant, pos = 0, j = 0, rep = 0, t = 0;
    if((arranjo1->tamanho == 0) && (m == 0)) return -7;
    for(int i = 0; ((i <= (arranjo1->tamanho -(m - j))) && (i < arranjo1->tamanho)); i++){
        aux = m - 1;
        j = D[i].masc[j];
        if(j == m){
            for(int k = i; k > ((i - m) + 1); k--){
                if(D[k].potencias[aux] != D[k - 1].potencias[aux - 1]){
                    rep = 0;
                    ant = -6;
                    for(int a = 0; a < m; a++){
                        aux2 = D[i].potencias[a];
                        if((a == rep) && (aux2 != -6) && (a != (m - 1))) rep++;
                        if(aux2 != -6)  t++;
                        if(((aux2 == -6) || (a == (m - 1))) && (ant != -6)){
                            if((rep <= (t + 1)) && (a == (m - 1))) j = rep;
                            if((rep > (t + 1)) && (a == (m - 1))) j = t + 1;
                            t = 0;
                        }
                        if((rep == 0) && (a == (m - 1))) j = rep;
                        ant = aux2;
                    }
                    break;
                }
                aux--;
            }
            if(j == m) return (i - (m-1));
        }
    }
    return -6;
}

void limpeza_dfas(dfa *D, int tamanho){
    for(int i = 0; i < tamanho; i++){
        free(D[i].potencias);
        free(D[i].masc);
    }
    free(D);
}
