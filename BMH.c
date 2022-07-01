#include "BMH.h"
#define tam_alfabet 12

int BMH(sequencia *arranjo1, sequencia *arranjo2){
    if((arranjo1->tamanho == 0) && (arranjo2->tamanho == 0)) return -7;
    int tab_desloc[tam_alfabet];
    
    for (int i = 0; i < tam_alfabet; i++){
        tab_desloc[i] = arranjo2->tamanho;
    }
    
    for (int i = 1; i < arranjo2->tamanho; i++){
        tab_desloc[arranjo2->notas[i-1]] = (arranjo2->tamanho) - i;
    }   
    
    int i = (arranjo2->tamanho), j, k;
    int potencia_ant, potencia_atual;
    k = i;
    j = arranjo2->tamanho;
        while (i <= arranjo1->tamanho)
        {
           
            if(comparador(arranjo1->notas[k-1],arranjo2->notas[j-1]) == 0){
                k = i;
                j = arranjo2->tamanho;
                while (arranjo1->notas[k-1] == arranjo2->notas[j-1]){
                    k--;
                    j--;
                    if (j == 0) return k;
                }
                
                
            } else{
                k = i;
                j = arranjo2->tamanho;
                potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
                potencia_ant = potencia_atual;
                
                while (potencia_ant == potencia_atual && j > 0 && potencia_atual != -6){
                    k--;
                    j--;
                    if (j == 0) return k;
                    potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
                }
                                    
            }

            if (i == (arranjo1->tamanho)) i = 1 + (arranjo1->tamanho); 
            else i = i + tab_desloc[arranjo1->notas[i-1]];
        }

        
    return -6;
}