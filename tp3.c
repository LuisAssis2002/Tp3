#include "ShiftAndExato.h"
#include "KMP.h"
#include "BMH.h"
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]){

    // definindo o tempo de execução
    struct timeval start, end;
    float tmp_exec;
    gettimeofday(&start, NULL);

    int a, metodo = 0;
    sequencia arranjo1, arranjo2;
    FILE *file = fopen("saida.txt", "w");
    fclose(file);
    file = fopen(argv[1], "r");
    if(argv[2] == NULL) printf("Metodo nao especificado\n");
    else metodo = atoi(argv[2]);
    if(file == NULL){
        printf("Erro, entrada do arquivo incorreta\n");
        return 0;
    }

    /*processo dos metodos:
    metodo 1: Forca Bruta
    metodo 2: ShiftAndExato
    metodo 3: BMH
    */
    if(metodo == 1){
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        a = forca_bruta(&arranjo1, &arranjo2);
        if(a == -7) break;
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 2){
        mascara *M;
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        M = cria_mascaras(&arranjo1, &arranjo2, M);
        a = shift_and_exato(&arranjo1, M, arranjo2.tamanho);
        if(a == -7) break;
        gravador(a);
        limpeza_mascaras(M, arranjo1.tamanho);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
        free(M);
    }
    if(metodo == 3){
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        a = BMH(&arranjo1, &arranjo2);
        if(a == -7) break;
        gravador(a);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
    }
    if(metodo == 4){
        dfa *D;
        while(1){
        leitor_de_arquivo(&arranjo1, &arranjo2, file);
        D = cria_dfa(&arranjo1, &arranjo2, D);
        a = KMP(&arranjo1, D, arranjo2.tamanho);
        //inserir aqui a funcao BMH, ex: a = BMH(&arranjo1, &arranjo2);
        if(a == -7) break;
        gravador(a);
        limpeza_dfas(D , arranjo1.tamanho);
        limpeza(&arranjo1);
        limpeza(&arranjo2);
        }
        free(D);
    }
    //fim dos metodos
    
    fclose(file);
    
    // captura do tempo de execução
    gettimeofday(&end, NULL);
    tmp_exec = end.tv_sec - start.tv_sec;
    printf("\ntempo de: %.4f\n", tmp_exec);
    return 0;
}