#include "ShiftAndExato.h"

//cria as mascaras do ShiftAnd
mascara* cria_mascaras(sequencia *arranjo1, sequencia *arranjo2, mascara *M){
    M = (mascara*) malloc(arranjo1->tamanho * sizeof(mascara));
    int aux;
    for(int i = 0; i < arranjo1->tamanho; i++){
        M[i].potencias = (int*) malloc(arranjo2->tamanho * sizeof(int));
        M[i].masc = 0;
        for(int j = 1; j <= arranjo2->tamanho; j++){
            if((aux = comparador(arranjo1->notas[i], arranjo2->notas[j - 1])) != -6){
                M[i].masc = M[i].masc | (int) pow(2,(arranjo2->tamanho - j));
                M[i].potencias[j-1] = aux;
            }
            else M[i].potencias[j-1] = -6;
        }
    }
    return M;
}

/*busca atraves do ShiftAndExato no arranjo 1 sequencias iguais ao arranjo 2,..
 caso encontre retorna a posicao do primeiro termo da primeira aparicao do arranjo 2,
  caso nao encontre, retorna -6 , em caso da entrada "0 0", retorna -7
*/
int shift_and_exato(sequencia *arranjo1, mascara *M, int m){
    int R = 0, r = 0, aux;
    if((arranjo1->tamanho == 0) && (m == 0)) return -7;
    for(int i = 0; (i < arranjo1->tamanho); i++){
        aux = m - 1;
        R = (r >> 1) | (int) pow(2, (m - 1));
        r = R & M[i].masc;
        if((r & 1) == 1){
            for(int j = i; j > ((i - m)+1); j--){
                if(M[j].potencias[aux] != M[j - 1].potencias[aux- 1]){
                    r--;
                    break;
                }
                aux--;
            }
            if((r & 1) == 1) return (i - (m-1));
        }
    }
    return -6;
}

//libera a memoria alocada paras mascaras
void limpeza_mascaras(mascara* M, int tamanho){
    for(int i = 0; i < tamanho; i++) free(M[i].potencias);
    free(M);
}