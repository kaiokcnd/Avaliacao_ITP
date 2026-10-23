#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

void calcular_media(float notas[][3], float *media, int qntd_estudantes){
    for(int k = 0; k < qntd_estudantes; k++){
        float resultado = (notas[k][0] + notas[k][1] + notas[k][2]) / 3;
        media[k] = resultado;
    }
}

void tabela(int qntd_estudantes, char nomes[][TAM_NOME], float notas[][3], float *media){
printf("-------------------------------Tabela-------------------------------\n");
    for(int k = 0; k < qntd_estudantes; k++){
        printf("%s %.2f %.2f %.2f %.2f  ", nomes[k], notas[k][0], notas[k][1], notas[k][2], media[k]);
        if(media[k] >= 6){
            printf("Atingiu a meta.\n");
        }
        else{
            printf("Abaixo da meta.\n");
        }
    }
}

void ranking(int qntd_estudantes, float *media, char nomes[][TAM_NOME]){
    float maior = 0;
    int *pos_aluno = malloc(qntd_estudantes * sizeof(int));
    int i = 0; 
    for(int k = 0; k < qntd_estudantes; k++){
        if(media[k] > maior){
            maior = media[k];
            pos_aluno = malloc(qntd_estudantes * sizeof(int));
            i = 0;
            pos_aluno[i] = k;
            i++;
        } 
        else if(media[k] == maior){
            pos_aluno[i] = k;
            i++;
        }
    }
    if(i > 1){
        printf("Mais de um aluno obteve a maior média da turma: %.2f! São eles:", maior);
        for(int j = 0; j < i; j++){
            printf("%s\n", nomes[pos_aluno[j]]);
        }
    }
    else{
        printf("Maior média: %.2f. Aluno: %s\n", maior, nomes[pos_aluno[0]]);
    }
}

int main(){

int qntd_estudantes, valido;
int i, j;

//Solicitar a quantidade de estudantes 
do
{
    printf("Quantos estudantes?\n");
    scanf("%d", &qntd_estudantes);
    getchar();
    if(qntd_estudantes > 10){
        printf("Limite de 10 estudantes!\n");
 }
 else if(qntd_estudantes == 0) printf("Quantidade de estudantes deve ser maior que zero!\n");
 
 
} while (qntd_estudantes > 10 || qntd_estudantes == 0);

//Solicita o nome dos estudantes

char nomes[qntd_estudantes][TAM_NOME];
 for(i=0; i < qntd_estudantes; i++){
    int valido = 1;
    do{
        printf("Digite o nome do estudante %d:", i + 1);
        fgets(nomes[i], sizeof(nomes[i]), stdin);
        int tamanho = strlen(nomes[i]);

        if (tamanho > 0 && nomes[i][tamanho - 1] == '\n') {
            nomes[i][tamanho - 1] = '\0';
        } else if (!feof(stdin)) {
            int c = getchar();

            if (c != '\n' && c != EOF) {
                while ((c = getchar()) != '\n' && c != EOF);
                valido = 0;
            }
        }
        if (strlen(nomes[i]) == 0) {
            valido = 0;
        }
        if (!valido) {
            printf("Nome invalido! Digite de 1 a 50 caracteres.\n");
        }

        } while (!valido);
 }
 
//Ler notas por estudante
float notas[qntd_estudantes][3];

for(i = 0; i < qntd_estudantes; i++){
    printf("Digite as notas do aluno %s:", nomes[i]);
    for(j = 0; j < 3; j++){
        scanf("%f", &notas[i][j]);

    }

}
// Calcular média e armazenar em vetor alocado dinamicamente

float *media = malloc(qntd_estudantes * sizeof(float));

calcular_media(notas, media, qntd_estudantes);

tabela(qntd_estudantes, nomes, notas, media);

ranking(qntd_estudantes, media, nomes);






return 0;
}