#include <stdio.h>
#include <stdlib.h>

//O programa recebe como parametro um número que será o tamanho do texto principal (t1), sendo que t1 >= 5, o padrão já está definido;
int main(int argc, char *argv[]){
    int t1;
    t1 = atoi(argv[1]);
    if(t1 < 5){
        printf("A entrada deve ser maior que 5\n");
        return 0;
    }
    FILE *fp = fopen("entrada.txt", "w");
    fprintf(fp, "%d 5\n", t1);
    while(t1 > 5){
        fprintf(fp, "A ");
        t1--;
    }
    fprintf(fp, "A A A A B\nA A A A B\n0 0");
    fclose(fp);
    return 0;
}