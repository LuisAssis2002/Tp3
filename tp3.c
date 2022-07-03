#include "ShiftAndExato.h"
#include "KMP.h"
#include "BMH.h"
#include <sys/time.h>
#include <time.h>

/*
    metodo 1: Forca Bruta
    metodo 2: KMP
    metodo 3: BMH
    metodo 4: ShiftAndExato
*/
int main(int argc, char *argv[]){

    // definindo o tempo de execução
    struct timeval start, end;
    float tmp_exec;
    gettimeofday(&start, NULL);

    int a, metodo = 0;
    sequencia arranjo1, arranjo2;
    FILE *file = fopen("saida.txt", "w"); //cria o arquivo de saída
    fclose(file);
    file = fopen(argv[1], "r");
    //verifica se o método escolhido é valido
    if((argv[2] == NULL)) printf("Metodo nao especificado\n");
    else metodo = atoi(argv[2]);
    if((metodo != 1) && (metodo != 2) && (metodo != 3) && (metodo != 4)) printf("Metodo nao encontrado, tente outra vez, de preferencia com um que exista\n");
    if(file == NULL){ //verifica se o arquivo escolhido é válido
        printf("Erro, entrada do arquivo incorreta\n");
        return 0;
    }

    //processo dos metodos:
    if(metodo == 1){
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        a = forca_bruta(&arranjo1, &arranjo2);
        if(a == -7) break; //verifica o caso de fechamento do programa
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 2){
        dfa *D;
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        D = cria_dfa(&arranjo1, &arranjo2, D);
        a = KMP(&arranjo1, D, arranjo2.tamanho);
        if(a == -7) break; //verifica o caso de fechamento do programa
        gravador(a);
        limpeza_dfas(D , arranjo1.tamanho);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
        free(D);
    }
    if(metodo == 3){
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        a = BMH(&arranjo1, &arranjo2);
        if(a == -7) break; //verifica o caso de fechamento do programa
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 4){
        mascara *M;
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        M = cria_mascaras(&arranjo1, &arranjo2, M);
        a = shift_and_exato(&arranjo1, M, arranjo2.tamanho);
        if(a == -7) break; //verifica o caso de fechamento do programa
        gravador(a);
        limpeza_mascaras(M, arranjo1.tamanho);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
        free(M);
    }
    //fim dos metodos
    
    fclose(file);
    
    // captura do tempo de execução
    gettimeofday(&end, NULL);
    tmp_exec = end.tv_sec - start.tv_sec;
    printf("\ntempo de: %.6f\n", tmp_exec);
    return 0;
}