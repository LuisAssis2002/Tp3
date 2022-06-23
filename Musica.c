#include "Musica.h"

//lê o tamanho e as notas de dois arranjos de notas
void leitor_de_arquivo(sequencia *arranjo1, sequencia *arranjo2, FILE* file){
    int n = 0;
    char Nota[2], leitor[500];
    fscanf(file, "%d %d", &arranjo1->tamanho, &arranjo2->tamanho);
    arranjo1->notas = (int*) malloc(arranjo1->tamanho * sizeof(int));
    arranjo2->notas = (int*) malloc(arranjo2->tamanho * sizeof(int));
    while(fgets(leitor, 500, file) != NULL){
        for(int i = 0; i < 500; i++){
            if((leitor[i] == '\n') || (leitor[i] == '\0')) break; //para a busca na linha
            else if(leitor[i] == ' ') continue;
            else{
                if(leitor[i] == 'A') arranjo1->notas[n] = 1;
                if(leitor[i] == 'B') arranjo1->notas[n] = 3;
                if(leitor[i] == 'C') arranjo1->notas[n] = 4;
                if(leitor[i] == 'D') arranjo1->notas[n] = 6;
                if(leitor[i] == 'E') arranjo1->notas[n] = 8;
                if(leitor[i] == 'F') arranjo1->notas[n] = 9;
                if(leitor[i] == 'G') arranjo1->notas[n] = 11;
                if(leitor[i] == '#'){ 
                    i++;
                    if(leitor[i] == 'A') arranjo1->notas[n] = 2;
                    if(leitor[i] == 'C') arranjo1->notas[n] = 5;
                    if(leitor[i] == 'D') arranjo1->notas[n] = 7;
                    if(leitor[i] == 'F') arranjo1->notas[n] = 10;
                    if(leitor[i] == 'G') arranjo1->notas[n] = 12;
                }
                if(leitor[i] == '_'){
                    i++;
                    if(leitor[i] == 'A') arranjo1->notas[n] = 12;
                    if(leitor[i] == 'B') arranjo1->notas[n] = 2;
                    if(leitor[i] == 'D') arranjo1->notas[n] = 5;
                    if(leitor[i] == 'E') arranjo1->notas[n] = 7;
                    if(leitor[i] == 'G') arranjo1->notas[n] = 10;
                }
                n++;
            }
        }
        if(n == arranjo1->tamanho) break;
    }
    n = 0;
    while(fgets(leitor, 500, file) != NULL){
        for(int i = 0; i < 500; i++){
            if((leitor[i] == '\n') || (leitor[i] == '\0')) break; //para a busca na linha
            else if(leitor[i] == ' ') continue;
            else{
                if(leitor[i] == 'A') arranjo2->notas[n] = 1;
                if(leitor[i] == 'B') arranjo2->notas[n] = 3;
                if(leitor[i] == 'C') arranjo2->notas[n] = 4;
                if(leitor[i] == 'D') arranjo2->notas[n] = 6;
                if(leitor[i] == 'E') arranjo2->notas[n] = 8;
                if(leitor[i] == 'F') arranjo2->notas[n] = 9;
                if(leitor[i] == 'G') arranjo2->notas[n] = 11;
                if(leitor[i] == '#'){
                    i++;
                    if(leitor[i] == 'A') arranjo2->notas[n] = 2;
                    if(leitor[i] == 'C') arranjo2->notas[n] = 5;
                    if(leitor[i] == 'D') arranjo2->notas[n] = 7;
                    if(leitor[i] == 'F') arranjo2->notas[n] = 10;
                    if(leitor[i] == 'G') arranjo2->notas[n] = 12;
                }
                if(leitor[i] == '_'){
                    i++;
                    if(leitor[i] == 'A') arranjo2->notas[n] = 12;
                    if(leitor[i] == 'B') arranjo2->notas[n] = 2;
                    if(leitor[i] == 'D') arranjo2->notas[n] = 5;
                    if(leitor[i] == 'E') arranjo2->notas[n] = 7;
                    if(leitor[i] == 'G') arranjo2->notas[n] = 10;
                }
                n++;
            }
        }
        if(n == arranjo2->tamanho) break;
    }
}

//libera a memória alocada pelo arranjo de notas
void limpeza(sequencia *arranjo){
    free(arranjo->notas);
}

//compara duas notas e retorna 1 caso elas sejam de uma frequência semelhante e 0 caso não
int comparador(int Nota1, int Nota2){
    float aux;
    int potencia = 0;
    if(Nota1 == Nota2) return potencia;
    if(Nota1 > Nota2) aux = Nota1 - Nota2;
    if(Nota2 > Nota1) aux = Nota2 - Nota1;
    while(aux >= 2){
        aux = aux / 2;
        potencia++;
    }
    if(aux == 1) return potencia;
    else return -1;
}

/*busca de forma bruta no arranjo 1 sequencias iguais ao arranjo 2,..
 caso encontre retorna a posicao do primeiro termo da primeira aparicao do arranjo 2,
  caso nao encontre, retorna -1 
*/
int forca_bruta(sequencia *arranjo1, sequencia *arranjo2){
    int potencia_anterior, potencia_atual;
    for(int i = 0; i < arranjo1->tamanho; i++){
        potencia_anterior = -1;
        for(int j = 0; j < arranjo2->tamanho; j++){
            potencia_atual = comparador(arranjo1->notas[i+j], arranjo2->notas[j]);
            printf("pt: %d\n", potencia_atual);
            printf("pat: %d\n", potencia_anterior);
            if(((potencia_atual == potencia_anterior) || (potencia_anterior == -1)) && (potencia_atual != -1)){
                printf("---\n");
                potencia_anterior = potencia_atual;
            }
            else break;
            if(j == (arranjo2->tamanho - 1)) return i;
        }
    }
    return -1;
}