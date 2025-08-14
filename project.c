#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;                        // Letra de A a H
    char codigo[4];                     // Ex.: "A01"
    char nomeCidade[50];                // Nome da cidade
    unsigned long int populacao;        // População (usando tipo grande)
    float area;                         // Área em km²
    float pib;                          // PIB em bilhões de reais
    int pontosTuristicos;               // Nº de pontos turísticos
    float densidadePopulacional;        // Calculada
    float pibPerCapita;                 // Calculado
    float superPoder;                   // Calculado
} Carta;

// Função para ler os dados de uma carta
void lerCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // lê até o ENTER

    printf("Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Area (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula os atributos derivados
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao; // PIB estava em bilhões

    // Calcula o "super poder"
    carta->superPoder = (float)carta->populacao +
                        carta->area +
                        (carta->pib * 1000000000.0f) +
                        carta->pontosTuristicos +
                        carta->pibPerCapita +
                        (1.0f / carta->densidadePopulacional);
}

// Função para exibir uma carta formatada
void exibirCarta(Carta carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar e mostrar quem venceu em cada atributo
void compararCartas(Carta c1, Carta c2) {
    printf("\n=== Comparacao de Cartas ===\n");

    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    Carta carta1, carta2;

    // Cadastro das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibindo informações
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparação
    compararCartas(carta1, carta2);

    return 0;
}
