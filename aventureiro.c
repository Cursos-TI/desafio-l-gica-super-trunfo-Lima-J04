#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\nComparando os países:\n");
    printf("1) %s\n2) %s\n", c1.nome, c2.nome);
    printf("Atributo escolhido: ");

    switch (opcao) {
        case 1:
            printf("População\n");
            printf("%s: %d habitantes\n", c1.nome, c1.populacao);
            printf("%s: %d habitantes\n", c2.nome, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Área\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("PIB\n");
            printf("%s: %.2f trilhões USD\n", c1.nome, c1.pib);
            printf("%s: %.2f trilhões USD\n", c2.nome, c2.pib);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos\n");
            printf("%s: %d\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nome, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica (menor vence!)\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.densidadeDemografica < c1.densidadeDemografica)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

int main() {
    // Exemplo com duas cartas fixas
    Carta pais1 = {"Brasil", 213000000, 8515767.0, 2.055, 18, 25.0};
    Carta pais2 = {"Japão", 125800000, 377975.0, 5.065, 20, 333.0};

    int escolha;

    printf("=== SUPER TRUNFO: COMPARAÇÃO DE PAÍSES ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha);

    compararCartas(pais1, pais2, escolha);

    return 0;
}
