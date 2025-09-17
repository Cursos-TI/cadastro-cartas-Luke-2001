#include <stdio.h>
#include <string.h> // para usar strcspn e manipular strings

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

#define TOTAL_CARTAS 32

// Estrutura para armazenar as propriedades de uma carta
struct Carta {
    char estado;                // Estado (A-H)
    char codigo[5];             // Código da carta (ex: A01)
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População
    float area;                 // Área
    float pib;                  // PIB
    int numPontosTuristicos;    // Número de pontos turísticos
};

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  struct Carta cartas[TOTAL_CARTAS];

  // Área para entrada de dados
  for (int i = 0; i < TOTAL_CARTAS; i++) {
      printf("\n=== Cadastro da Carta %d ===\n", i + 1);

      printf("Informe o estado (A-H): ");
      scanf(" %c", &cartas[i].estado);

      printf("Informe o código da carta (ex: A01): ");
      scanf("%s", cartas[i].codigo);

      getchar(); // limpa o buffer antes do fgets

      printf("Informe o nome da cidade: ");
      fgets(cartas[i].nomeCidade, 50, stdin);
      cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0'; // remove \n do fgets

      printf("Informe a população: ");
      scanf("%d", &cartas[i].populacao);

      printf("Informe a área: ");
      scanf("%f", &cartas[i].area);

      printf("Informe o PIB: ");
      scanf("%f", &cartas[i].pib);

      printf("Informe o número de pontos turísticos: ");
      scanf("%d", &cartas[i].numPontosTuristicos);
  }

  // Área para exibição dos dados da cidade
  printf("\n=== Cartas Cadastradas ===\n");
  for (int i = 0; i < TOTAL_CARTAS; i++) {
      printf("\nCarta %d\n", i + 1);
      printf("Estado: %c\n", cartas[i].estado);
      printf("Código: %s\n", cartas[i].codigo);
      printf("Cidade: %s\n", cartas[i].nomeCidade);
      printf("População: %d\n", cartas[i].populacao);
      printf("Área: %.2f km²\n", cartas[i].area);
      printf("PIB: %.2f bilhões\n", cartas[i].pib);
      printf("Pontos Turísticos: %d\n", cartas[i].numPontosTuristicos);
  }

  return 0;
}
