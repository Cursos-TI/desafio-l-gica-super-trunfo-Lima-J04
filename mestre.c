#include <stdio.h>
#include <string.h>

#define QTD_ATRIBUTOS 4
#define QTD_CARTAS 2

typedef struct {
    char nome[30];
    int populacao;     // em milhões
    int area;          // em mil km²
    int pib;           // em bilhões de dólares
    int densidade;     // hab/km²
} Carta;

// Função para exibir o menu de seleção de atributos
void exibirMenuAtributos(int excluido) {
    printf("Escolha um atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Densidade Demográfica\n");
}

// Função para obter valor do atributo
int obterAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

// Nome do atributo para exibição
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta cartas[QTD_CARTAS] = {
        {"Brasil", 213, 8516, 1800, 25},
        {"Canadá", 38, 9985, 1700, 4}
    };

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        exibirMenuAtributos(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > QTD_ATRIBUTOS) {
            printf("Opção inválida. Tente novamente.\n");
            atributo1 = 0;
        }
    } while (atributo1 == 0);

    // Escolha do segundo atributo
    do {
        exibirMenuAtributos(atributo1);
        printf("Digite o número do segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > QTD_ATRIBUTOS || atributo2 == atributo1) {
            printf("Opção inválida. Tente novamente.\n");
            atributo2 = 0;
        }
    } while (atributo2 == 0);

    // Comparação dos atributos
    int val1_1 = obterAtributo(cartas[0], atributo1);
    int val1_2 = obterAtributo(cartas[0], atributo2);
    int val2_1 = obterAtributo(cartas[1], atributo1);
    int val2_2 = obterAtributo(cartas[1], atributo2);

    // Cálculo da pontuação baseada na comparação de cada atributo
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (atributo1 == 4) ? (val1_1 < val2_1 ? 1 : 0) : (val1_1 > val2_1 ? 1 : 0);
    pontos2 += (atributo1 == 4) ? (val2_1 < val1_1 ? 1 : 0) : (val2_1 > val1_1 ? 1 : 0);

    pontos1 += (atributo2 == 4) ? (val1_2 < val2_2 ? 1 : 0) : (val1_2 > val2_2 ? 1 : 0);
    pontos2 += (atributo2 == 4) ? (val2_2 < val1_2 ? 1 : 0) : (val2_2 > val1_2 ? 1 : 0);

    int soma1 = val1_1 + val1_2;
    int soma2 = val2_1 + val2_2;

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributos escolhidos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    printf("\n");

    printf("%s:\n", cartas[0].nome);
    printf("  %s: %d\n", nomeAtributo(atributo1), val1_1);
    printf("  %s: %d\n", nomeAtributo(atributo2), val1_2);
    printf("  Soma dos atributos: %d\n\n", soma1);

    printf("%s:\n", cartas[1].nome);
    printf("  %s: %d\n", nomeAtributo(atributo1), val2_1);
    printf("  %s: %d\n", nomeAtributo(atributo2), val2_2);
    printf("  Soma dos atributos: %d\n\n", soma2);

    if (soma1 > soma2)
        printf(">> %s venceu!\n", cartas[0].nome);
    else if (soma2 > soma1)
        printf(">> %s venceu!\n", cartas[1].nome);
    else
        printf(">> Empate!\n");

    return 0;
}
