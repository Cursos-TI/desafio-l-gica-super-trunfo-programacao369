

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARTAS 5

// Estrutura para representar uma carta
typedef struct {
    char cidade[50];
    char estado[50];
    char pais[50];
    float pib;        // Em bilhões de dólares
    float populacao;  // Em milhões de habitantes
    int pontosTuristicos;
} Carta;

// Função para inicializar as cartas
void inicializarCartas(Carta cartas[]) {
    strcpy(cartas[0].cidade, "São Paulo");
    strcpy(cartas[0].estado, "São Paulo");
    strcpy(cartas[0].pais, "Brasil");
    cartas[0].pib = 480;
    cartas[0].populacao = 12.33;
    cartas[0].pontosTuristicos = 25;

    strcpy(cartas[1].cidade, "Nova York");
    strcpy(cartas[1].estado, "Nova York");
    strcpy(cartas[1].pais, "EUA");
    cartas[1].pib = 1700;
    cartas[1].populacao = 8.3;
    cartas[1].pontosTuristicos = 30;

    strcpy(cartas[2].cidade, "Paris");
    strcpy(cartas[2].estado, "Île-de-France");
    strcpy(cartas[2].pais, "França");
    cartas[2].pib = 900;
    cartas[2].populacao = 2.1;
    cartas[2].pontosTuristicos = 35;

    strcpy(cartas[3].cidade, "Tóquio");
    strcpy(cartas[3].estado, "Tóquio");
    strcpy(cartas[3].pais, "Japão");
    cartas[3].pib = 1600;
    cartas[3].populacao = 14.0;
    cartas[3].pontosTuristicos = 20;

    strcpy(cartas[4].cidade, "Londres");
    strcpy(cartas[4].estado, "Inglaterra");
    strcpy(cartas[4].pais, "Reino Unido");
    cartas[4].pib = 800;
    cartas[4].populacao = 9.0;
    cartas[4].pontosTuristicos = 40;
}

// Função para jogar uma rodada
void jogarRodada(Carta carta1, Carta carta2, int atributo) {
    printf("\nComparando cartas:\n");
    printf("%s (%s, %s) VS %s (%s, %s)\n", 
        carta1.cidade, carta1.estado, carta1.pais, 
        carta2.cidade, carta2.estado, carta2.pais);

    float valor1 = 0, valor2 = 0;

    switch (atributo) {
        case 1:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            printf("Atributo: PIB (em bilhões de dólares)\n");
            break;
        case 2:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            printf("Atributo: População (em milhões)\n");
            break;
        case 3:
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            printf("Atributo: Pontos turísticos\n");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("%s: %.2f VS %s: %.2f\n", carta1.cidade, valor1, carta2.cidade, valor2);

    if (valor1 > valor2) {
        printf("%s vence a rodada!\n", carta1.cidade);
    } else if (valor1 < valor2) {
        printf("%s vence a rodada!\n", carta2.cidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta cartas[NUM_CARTAS];
    int atributoEscolhido;
    srand(time(NULL));

    // Inicializa as cartas
    inicializarCartas(cartas);

    printf("Bem-vindo ao Super Trunfo das Cidades!\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1. PIB (em bilhões de dólares)\n");
    printf("2. População (em milhões)\n");
    printf("3. Pontos turísticos\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &atributoEscolhido);

    // Sorteia duas cartas diferentes
    int cartaJogador1 = rand() % NUM_CARTAS;
    int cartaJogador2 = rand() % NUM_CARTAS;

    while (cartaJogador2 == cartaJogador1) {
        cartaJogador2 = rand() % NUM_CARTAS;
    }

    // Joga a rodada
    jogarRodada(cartas[cartaJogador1], cartas[cartaJogador2], atributoEscolhido);

    return 0;
}
