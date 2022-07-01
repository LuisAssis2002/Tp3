#include "Musica.h"

//lê o tamanho e as notas de dois arranjos de notas
void leitor_de_arquivo(sequencia *arranjo1, sequencia *arranjo2, FILE* file){
    int n = 0;
    char Nota[2];
    size_t len = 0;
    ssize_t r;
    fscanf(file, "%d %d", &arranjo1->tamanho, &arranjo2->tamanho);
    if((arranjo1->tamanho == 0) && (arranjo2->tamanho == 0)) return;
    char *leitor = NULL;
    arranjo1->notas = (int*) malloc(arranjo1->tamanho * sizeof(int));
    arranjo2->notas = (int*) malloc(arranjo2->tamanho * sizeof(int));
    while((r = getline(&leitor, &len, file)) != -1){
        for(int i = 0; i < len; i++){
            if((leitor[i] == '\n') || (leitor[i] == '\0')) break; //para a busca na linha
            else if(leitor[i] == ' ') continue;
            else{
                if(leitor[i] == 'A'){
                    if(leitor[i + 1] == '#'){
                        arranjo1->notas[n] = 2;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo1->notas[n] = 12;
                        i++;
                    }
                    else arranjo1->notas[n] = 1;
                }
                if(leitor[i] == 'B'){
                    if(leitor[i + 1] == 'b'){
                        arranjo1->notas[n] = 2;
                        i++;
                    }
                    else arranjo1->notas[n] = 3;
                }
                if(leitor[i] == 'C'){
                    if(leitor[i + 1] == '#'){
                        arranjo1->notas[n] = 5;
                        i++;
                    }
                    else arranjo1->notas[n] = 4;
                }
                if(leitor[i] == 'D'){
                    if(leitor[i + 1] == '#'){
                        arranjo1->notas[n] = 7;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo1->notas[n] = 5;
                        i++;
                    }
                    else arranjo1->notas[n] = 6;
                }
                if(leitor[i] == 'E'){
                    if(leitor[i + 1] == 'b'){
                        arranjo1->notas[n] = 7;
                        i++;
                    }
                    else arranjo1->notas[n] = 8;
                }
                if(leitor[i] == 'F'){
                    if(leitor[i + 1] == '#'){
                        arranjo1->notas[n] = 10;
                        i++;
                    }
                    else arranjo1->notas[n] = 9;
                }
                if(leitor[i] == 'G'){
                    if(leitor[i + 1] == '#'){
                        arranjo1->notas[n] = 12;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo1->notas[n] = 10;
                        i++;
                    }
                    else arranjo1->notas[n] = 11;
                }
                n++;
            }
        }
        if(n == arranjo1->tamanho) break;
    }
    n = 0;
    while((r = getline(&leitor, &len, file)) != -1){
        for(int i = 0; i < len; i++){
            if((leitor[i] == '\n') || (leitor[i] == '\0')) break; //para a busca na linha
            else if(leitor[i] == ' ') continue;
            else{
                if(leitor[i] == 'A'){
                    if(leitor[i + 1] == '#'){
                        arranjo2->notas[n] = 2;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo2->notas[n] = 12;
                        i++;
                    }
                    else arranjo2->notas[n] = 1;
                }
                if(leitor[i] == 'B'){
                    if(leitor[i + 1] == 'b'){
                        arranjo2->notas[n] = 2;
                        i++;
                    }
                    else arranjo2->notas[n] = 3;
                }
                if(leitor[i] == 'C'){
                    if(leitor[i + 1] == '#'){
                        arranjo2->notas[n] = 5;
                        i++;
                    }
                    else arranjo2->notas[n] = 4;
                }
                if(leitor[i] == 'D'){
                    if(leitor[i + 1] == '#'){
                        arranjo2->notas[n] = 7;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo2->notas[n] = 5;
                        i++;
                    }
                    else arranjo2->notas[n] = 6;
                }
                if(leitor[i] == 'E'){
                    if(leitor[i + 1] == 'b'){
                        arranjo2->notas[n] = 7;
                        i++;
                    }
                    else arranjo2->notas[n] = 8;
                }
                if(leitor[i] == 'F'){
                    if(leitor[i + 1] == '#'){
                        arranjo2->notas[n] = 10;
                        i++;
                    }
                    else arranjo2->notas[n] = 9;
                }
                if(leitor[i] == 'G'){
                    if(leitor[i + 1] == '#'){
                        arranjo2->notas[n] = 12;
                        i++;
                    }
                    else if(leitor[i + 1] == 'b'){
                        arranjo2->notas[n] = 10;
                        i++;
                    }
                    else arranjo2->notas[n] = 11;
                }
                n++;
            }
        }
        if(n == arranjo2->tamanho) break;
    }
    free(leitor);
}

//libera a memória alocada pelo arranjo de notas
void limpeza(sequencia *arranjo){
    free(arranjo->notas);
}

//grava os resultados no arquivo saida.txt
void gravador(int a){
    FILE *file = fopen("saida.txt", "a");
    if(a != -6) fprintf(file, "S %d\n", a);
    else fprintf(file, "N\n");
    fclose(file);
}

//compara duas notas e retorna 1 caso elas sejam de uma frequência semelhante e -6 caso não
int comparador(int Nota1, int Nota2){
    float aux;
    int u, potencia = 0;
    if(Nota1 == Nota2) return potencia;
    if(Nota1 > Nota2){
        aux = Nota1 - Nota2;
        u = 1;
    }
    if(Nota2 > Nota1){
        aux = -(Nota2 - Nota1);
        u = -1;
    }
    if(aux == 1) return 1;
    if(aux == -1) return -1;
    while((aux >= 2) || (aux <= -2)){
        aux = aux / 2;
        potencia++;
    }
    potencia = (u * potencia) + u;
    if((aux == 1) || (aux == -1)) return potencia;
    if(Nota1 > Nota2) aux = (Nota1 - Nota2) - (u * 12);
    if(Nota2 > Nota1) aux = (-(Nota2 - Nota1)) - (u * 12);
    if(aux == 1) return 1;
    if(aux == -1) return -1;
    potencia = 0;

    while((aux >= 2) || (aux <= -2)){
        aux = aux / 2;
        potencia++;
    }

    potencia = (-u) * (potencia + 1);
    if((aux == 1) || (aux == -1)) return potencia;
    return -6;
}

/*busca de forma bruta no arranjo 1 sequencias iguais ao arranjo 2,..
 caso encontre retorna a posicao do primeiro termo da primeira aparicao do arranjo 2,
  caso nao encontre, retorna -6 , em caso da entrada "0 0", retorna -7
*/
int forca_bruta(sequencia *arranjo1, sequencia *arranjo2){
    int potencia_anterior, potencia_atual;
    if((arranjo1->tamanho == 0) && (arranjo2->tamanho == 0)) return -7;
    for(int i = 0; ((i < arranjo1->tamanho) && (i <= arranjo1->tamanho - arranjo2->tamanho)); i++){
        potencia_anterior = -6;
        for(int j = 0; j < arranjo2->tamanho; j++){
            potencia_atual = comparador(arranjo1->notas[i+j], arranjo2->notas[j]);
            if(((potencia_atual == potencia_anterior) || (potencia_anterior == -6)) && (potencia_atual != -6)){
                potencia_anterior = potencia_atual;
            }
            else break;
            if(j == (arranjo2->tamanho - 1)) return i;
        }
    }
    return -6;
}