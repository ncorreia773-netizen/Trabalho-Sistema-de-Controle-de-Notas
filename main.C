#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char nomes[MAX][100];
    float notas1[MAX];
    float notas2[MAX];
    float medias[MAX];
    int quantidade;
    int i;
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    float maior;
    float menor;
    float soma = 0;

    printf("\n=== CONTROLE DE NOTAS ===\n\n");

    printf("Quantidade de alunos: ");
    scanf("%d", &quantidade);

    if(quantidade <= 0 || quantidade > MAX) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    getchar(); // limpa buffer

    for(i = 0; i < quantidade; i++) {
        printf("\nAluno %d\n", i+1);

        printf("Nome: ");
        fgets(nomes[i], 100, stdin);
        nomes[i][strlen(nomes[i]) - 1] = '\0'; // remove o enter

        printf("Nota 1: ");
        scanf("%f", &notas1[i]);
        printf("Nota 2: ");
        scanf("%f", &notas2[i]);
        getchar();

        medias[i] = (notas1[i] + notas2[i]) / 2;
    }

    maior = medias[0];
    menor = medias[0];

    printf("\n--- RESULTADOS ---\n");

    for(i = 0; i < quantidade; i++) {
        printf("\n%s\n", nomes[i]);
        printf("Notas: %.1f e %.1f\n", notas1[i], notas2[i]);
        printf("Media: %.1f\n", medias[i]);

        if(medias[i] >= 7) {
            printf("APROVADO\n");
            aprovados++;
        } else if(medias[i] >= 5) {
            printf("RECUPERACAO\n");
            recuperacao++;
        } else {
            printf("REPROVADO\n");
            reprovados++;
        }

        if(medias[i] > maior) {
            maior = medias[i];
        }
        if(medias[i] < menor) {
            menor = medias[i];
        }

        soma = soma + medias[i];
    }

    printf("\n--- RESUMO DA TURMA ---\n");
    printf("Maior media: %.1f\n", maior);
    printf("Menor media: %.1f\n", menor);
    printf("Media da turma: %.1f\n", soma / quantidade);
    printf("\nAprovados: %d\n", aprovados);
    printf("Recuperacao: %d\n", recuperacao);
    printf("Reprovados: %d\n", reprovados);

    printf("\n=== FIM ===\n");

    return 0;
}

