#include "Musica.h"

int main(int argc, char *argv[]){
    int a;
    sequencia arranjo1, arranjo2;
    FILE *file = fopen(argv[1], "r");
    int metodo = atoi(argv[2]);
    if(file == NULL){
        printf("Erro, entrada do arquivo incorreta\n");
    }
    printf("arq: %s\n met: %d\n", argv[1], metodo);
    leitor_de_arquivo(&arranjo1, &arranjo2, file);

    //processo dos metodos:
    if(metodo == 1) a = forca_bruta(&arranjo1, &arranjo2);

    //fim dos metodos
    
    printf("a: %d\n", a);
    limpeza(&arranjo1);
    limpeza(&arranjo2);
    fclose(file);
    return 0;
}