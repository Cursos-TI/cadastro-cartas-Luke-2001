#include <stdio.h>
#include <string.h> // para usar strcspn e manipular strings

// 🛡️ Desafio Super Trunfo - Países
// 🌍 Nível Aventureiro
// Objetivo: Expandir o sistema de cadastro das cidades para incluir propriedades calculadas
// que permitem uma análise mais detalhada das cartas.

// 📘 Diferenças em relação ao Nível Novato:
// - Cálculo automático da Densidade Populacional (população / área)
// - Cálculo automático do PIB per Capita (PIB / população)

#define TOTAL_CARTAS 32

// Estrutura para armazenar as propriedades de uma carta
struct Carta {
    char estado;                 // Estado (A-H)
    char codigo[5];              // Código da carta (ex: A01)
    char nomeCidade[50];         // Nome da cidade
    int populacao;               // População
    float area;                  // Área (km²)
    float pib;                   // PIB (em bilhões)
    int numPontosTuristicos;     // Número de pontos turísticos

    // Novas propriedades calculadas
    float densidadePopulacional; // População / área
    float pibPerCapita;          // PIB / população
};

int main() {
    struct Carta cartas[TOTAL_CARTAS];

    printf("=============================================\n");
    printf("     🛡️  SUPER TRUNFO - PAÍSES - NÍVEL AVENTUREIRO\n");
    printf("=============================================\n");

    // Entrada de dados
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        printf("Informe o estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Informe o código da carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        getchar(); // limpa o buffer antes do fgets

        printf("Informe o nome da cidade: ");
        fgets(cartas[i].nomeCidade, 50, stdin);
        cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0';

        printf("Informe a população: ");
        scanf("%d", &cartas[i].populacao);

        printf("Informe a área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("Informe o PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Informe o número de pontos turísticos: ");
        scanf("%d", &cartas[i].numPontosTuristicos);

        // Cálculos automáticos
        cartas[i].densidadePopulacional = cartas[i].area > 0 ? (float)cartas[i].populacao / cartas[i].area : 0;
        cartas[i].pibPerCapita = cartas[i].populacao > 0 ? (cartas[i].pib * 1000000000.0) / cartas[i].populacao : 0;
    }

    // Exibição dos dados
    printf("\n=============================================\n");
    printf("           📊 CARTAS CADASTRADAS\n");
    printf("=============================================\n");

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\n-----------------------------\n");
        printf("Carta %d\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].numPontosTuristicos);

        // Exibe os novos cálculos
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidadePopulacional);
        printf("PIB per Capita: R$ %.2f\n", cartas[i].pibPerCapita);
    }

    printf("\n=============================================\n");
    printf("       ✅ Cadastro e cálculos concluídos!\n");
    printf("=============================================\n");

    return 0;
}
