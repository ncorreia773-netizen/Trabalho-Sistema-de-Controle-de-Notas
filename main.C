#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100

int main() {
    // Vetores para armazenar os dados
    char nomes[MAX_ALUNOS][MAX_NOME];
    float nota1[MAX_ALUNOS];
    float nota2[MAX_ALUNOS];
    float medias[MAX_ALUNOS];
    
    int qtd_alunos;
    int i;
    
    // Contadores de situacao
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    
    // Variaveis para maior, menor e media da turma
    float maior_media, menor_media, soma_medias = 0;
    float media_turma;
    
    printf("========================================\n");
    printf("   SISTEMA DE CONTROLE DE NOTAS\n");
    printf("========================================\n\n");
    
    // Entrada da quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &qtd_alunos);
    
    // Validacao simples
    if (qtd_alunos <= 0 || qtd_alunos > MAX_ALUNOS) {
        printf("Quantidade invalida! O programa sera encerrado.\n");
        return 1;
    }
    
    // Limpar o buffer do teclado
    getchar();
    
    // Cadastro dos alunos
    printf("\n--- Cadastro dos Alunos ---\n");
    for (i = 0; i < qtd_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(nomes[i], MAX_NOME, stdin);
        
        // Remove o \n que o fgets deixa no final
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
        
        printf("Nota 1: ");
        scanf("%f", &nota1[i]);
        
        printf("Nota 2: ");
        scanf("%f", &nota2[i]);
        
        getchar(); // limpa o buffer
        
        // Calcula a media individual
        medias[i] = (nota1[i] + nota2[i]) / 2.0;
    }
    
    // Processamento: classificar e encontrar maior/menor
    maior_media = medias[0];
    menor_media = medias[0];
    
    printf("\n========================================\n");
    printf("         RESULTADOS INDIVIDUAIS\n");
    printf("========================================\n");
    
    for (i = 0; i < qtd_alunos; i++) {
        printf("\nAluno: %s\n", nomes[i]);
        printf("Nota 1: %.1f | Nota 2: %.1f\n", nota1[i], nota2[i]);
        printf("Media: %.1f\n", medias[i]);
        
        // Classificacao
        if (medias[i] >= 7.0) {
            printf("Situacao: APROVADO\n");
            aprovados++;
        } else if (medias[i] >= 5.0) {
            printf("Situacao: RECUPERACAO\n");
            recuperacao++;
        } else {
            printf("Situacao: REPROVADO\n");
            reprovados++;
        }
        
        // Atualiza maior e menor media
        if (medias[i] > maior_media) {
            maior_media = medias[i];
        }
        if (medias[i] < menor_media) {
            menor_media = medias[i];
        }
        
        // Soma para media da turma
        soma_medias = soma_medias + medias[i];
    }
    
    // Calcula media da turma
    media_turma = soma_medias / qtd_alunos;
    
    // Resultados gerais
    printf("\n========================================\n");
    printf("         RESULTADOS DA TURMA\n");
    printf("========================================\n");
    printf("Maior media: %.1f\n", maior_media);
    printf("Menor media: %.1f\n", menor_media);
    printf("Media da turma: %.1f\n", media_turma);
    printf("\nQuantidade de alunos:\n");
    printf("  Aprovados: %d\n", aprovados);
    printf("  Em recuperacao: %d\n", recuperacao);
    printf("  Reprovados: %d\n", reprovados);
    
    printf("\n========================================\n");
    printf("         FIM DO PROGRAMA\n");
    printf("========================================\n");
    
    return 0;
}
