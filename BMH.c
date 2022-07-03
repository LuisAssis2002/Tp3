#include "BMH.h"

// para padronização o texto será chamado de arranjo1 e o padrão de arranjo2

// nosso alfabeto é sempre as notas musicais, por isso defnimos o tamanho 12
#define tam_alfabet 12


int BMH(sequencia *arranjo1, sequencia *arranjo2){

    // caso o tamanho  do padrão e do texto sejam iguais a 0, a função 
    //já retorna um valor que encerra o programa
    if((arranjo1->tamanho == 0) && (arranjo2->tamanho == 0)) return -7;

    int *tab_desloc;
    int tab_aux[tam_alfabet];
    tab_desloc = pre_proces(arranjo2, tab_aux); // inicializa a tabela de deslocamento pelo metodo BMH
    
    int i = (arranjo2->tamanho), j, k;
    int potencia_ant, potencia_atual;
    k = i;
    j = arranjo2->tamanho;

    while (i <= arranjo1->tamanho) //enquanto i for menor que o tamanho do texto pode haver casamento
    {
        k = i;
        j = arranjo2->tamanho;
        potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
        potencia_ant = potencia_atual;
        
        // compara as potencias atual e anterior verificando se a sequencia mantém a diferença
        // de meios tons em toda a sequencia, o que caracteriza a mesma melodia em outro tom
        while (potencia_ant == potencia_atual && j > 0 && potencia_atual != -6){ 
            k--;
            j--;
            if (j == 0) return k;
            potencia_atual = comparador(arranjo1->notas[k-1], arranjo2->notas[j-1]);
        }
                
        // no caso de já ter computado a última posição do texto
        // e não ter encontrado uma ocorrencia, sai do while
        if (i == (arranjo1->tamanho)) break;
        else i = i + tab_desloc[arranjo1->notas[i-1]];
    }
     
    return -6;
}


int* pre_proces(sequencia *padrao, int* tab_desloc){
    
    // inicializa a tabela de deslocamento com todas as posições recebendo
    // o tamanho do padrão para não haver posições inválidas
    for (int i = 0; i < tam_alfabet; i++){
        tab_desloc[i] = padrao->tamanho;
    }
    
    
    //faz o cálculo dos deslocamentos e os atribui as devidas posições
    for (int i = 1; i < padrao->tamanho; i++){
        tab_desloc[padrao->notas[i-1]] = (padrao->tamanho) - i;
    }  

    return tab_desloc;
}