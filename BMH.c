#include "BMH.h"

int BMH(sequencia *arranjo1, sequencia *arranjo2){
    int tabela[12];

    if((arranjo1->tamanho == 0) && (arranjo2->tamanho == 0)) return -7;
    
    for (int i = 0; i < 12; i++){
        tabela[i] = arranjo2->tamanho;
    }
    
    for (int i = 1; i < arranjo2->tamanho; i++){
        tabela[arranjo2->notas[i-1]] = arranjo2->tamanho - i;
    }   
    
    int i = arranjo2->tamanho, j, k;
    int potencia_ant, potencia_atual;
    k = i;
    j = arranjo2->tamanho;
        while (i < arranjo1->tamanho)
        {
            
            if(comparador(arranjo1->notas[k-1],arranjo2->notas[j-1]) == 0){
                k = i;
                j = arranjo2->tamanho;
                while (arranjo1->notas[k-1] == arranjo2->notas[j-1]){
                    k--;
                    j--;
                    
                }
                if (j == 0) return k;
                
            } else{
                k = i;
                j = arranjo2->tamanho;
                potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
                potencia_ant = potencia_atual;
                
                while (potencia_ant == potencia_atual && j > 0 && potencia_atual != -6){
                    k--;
                    j--;
                    potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
                }
                if (j == 0) return k;                    
            }

            i = i + tabela[arranjo1->notas[i-1]];
        }

        
    return -6;
}