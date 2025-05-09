#include <stdio.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular os atributos derivados
void calcularDadosDerivados(struct Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = carta->pib / carta->populacao;
    else
        carta->pibPerCapita = 0;
}

int main() {
    // Definindo duas cartas manualmente (pré-cadastradas)
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 699000000000.0, 25};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6748000, 1182.30, 410000000000.0, 18};

    // Calculando densidade populacional e PIB per capita
    calcularDadosDerivados(&carta1);
    calcularDadosDerivados(&carta2);

    // Escolher o atributo a ser comparado:
    // Opções: "populacao", "area", "pib", "densidade", "pibPerCapita"
    // Neste exemplo, vamos comparar o PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    // Comparação usando if-else
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta1.pibPerCapita < carta2.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
