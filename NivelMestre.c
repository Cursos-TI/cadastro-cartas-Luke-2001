#include <stdio.h>
#include <string.h>

// 🏆 Desafio Super Trunfo - Países
// 🌎 Nível Mestre
// Objetivo: Permitir a comparação entre duas cartas com base em suas propriedades
// e calcular o "Super Poder" total de cada uma.

// 🆕 Diferenças em relação ao Nível Aventureiro:
// - Comparação entre duas cartas com base nos atributos
// - Cálculo do "Super Poder" (soma de todas as propriedades)
// - Exibição da carta vencedora em cada categoria

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
    float densidadePopulacional; // População / área
    float pibPerCapita;          // PIB / população
    float superPoder;            // Soma ponderada das propriedades
};

int main() {
    struct Carta cartas[TOTAL_CARTAS];

    printf("=============================================\n");
    printf("     🏆  SUPER TRUNFO - PAÍSES - NÍVEL MESTRE\n");
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

        // Super Poder (soma ponderada das principais propriedades)
        cartas[i].superPoder = (float)cartas[i].populacao +
                               cartas[i].area +
                               (cartas[i].pib * 1000) +
                               cartas[i].numPontosTuristicos +
                               (cartas[i].pibPerCapita / 1000);
    }

    printf("\n=============================================\n");
    printf("           📊 CARTAS CADASTRADAS\n");
    printf("=============================================\n");

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCarta %d - %s (%s)\n", i + 1, cartas[i].nomeCidade, cartas[i].codigo);
        printf("Estado: %c\n", cartas[i].estado);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].numPontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidadePopulacional);
        printf("PIB per Capita: R$ %.2f\n", cartas[i].pibPerCapita);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
    }

    // Escolha de cartas para comparação
    int c1, c2;
    printf("\n=============================================\n");
    printf("        ⚔️  COMPARAÇÃO ENTRE CARTAS\n");
    printf("=============================================\n");

    printf("Digite o número da primeira carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &c1);
    printf("Digite o número da segunda carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &c2);

    // Ajuste de índice
    c1--; 
    c2--;

    struct Carta a = cartas[c1];
    struct Carta b = cartas[c2];

    printf("\n=============================================\n");
    printf("🔍 Comparando %s (Carta %d) vs %s (Carta %d)\n", a.nomeCidade, c1 + 1, b.nomeCidade, c2 + 1);
    printf("=============================================\n");

    // Função de comparação com base nas regras
    printf("\n🏙️  População: ");
    printf("%s vence!\n", a.populacao > b.populacao ? a.nomeCidade : b.nomeCidade);

    printf("🌐 Área: ");
    printf("%s vence!\n", a.area > b.area ? a.nomeCidade : b.nomeCidade);

    printf("💰 PIB: ");
    printf("%s vence!\n", a.pib > b.pib ? a.nomeCidade : b.nomeCidade);

    printf("🎡 Pontos Turísticos: ");
    printf("%s vence!\n", a.numPontosTuristicos > b.numPontosTuristicos ? a.nomeCidade : b.nomeCidade);

    printf("👥 Densidade Populacional: ");
    printf("%s vence!\n", a.densidadePopulacional < b.densidadePopulacional ? a.nomeCidade : b.nomeCidade);

    printf("💵 PIB per Capita: ");
    printf("%s vence!\n", a.pibPerCapita > b.pibPerCapita ? a.nomeCidade : b.nomeCidade);

    printf("⚡ Super Poder Total: ");
    printf("%s vence!\n", a.superPoder > b.superPoder ? a.nomeCidade : b.nomeCidade);

    printf("\n=============================================\n");
    printf("       🏁 Comparação finalizada com sucesso!\n");
    printf("=============================================\n");

    return 0;
}
