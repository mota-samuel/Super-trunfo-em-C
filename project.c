#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf)
#include <stdlib.h>  // Biblioteca para funções utilitárias (atof)
#include <string.h>  // Biblioteca para manipulação de strings (strcmp)

int main() {
    char entrada[50]; // Vetor de chars para armazenar a entrada do usuário (até 49 caracteres + '\0')
    double soma = 0.0; // Variável para acumular a soma dos números digitados
    int contador = 0;  // Contador de quantos números foram digitados

    printf("Digite numeros e, quando quiser calcular a media, digite '='\n");

    // Loop infinito para ir lendo os valores até encontrar o '='
    while (1) {
        printf("Digite um valor ou '=': ");
        scanf("%s", entrada); // Lê a entrada como string (palavra)

        // strcmp compara duas strings:
        // Retorna 0 se forem iguais
        if (strcmp(entrada, "=") == 0) {
            // Se o usuário não digitou nenhum número ainda
            if (contador == 0) {
                printf("Nenhum valor foi digitado.\n");
            } else {
                // Calcula a média: soma dividida pelo número de valores
                double media = soma / contador;
                printf("Media dos %d valores = %.2f\n", contador, media);
            }
            break; // Sai do loop
        }

        // atof converte string para double (ex.: "3.5" → 3.5)
        double valor = atof(entrada);
        soma += valor;    // Soma o valor à soma acumulada
        contador++;       // Incrementa a quantidade de números digitados
    }

    return 0; // Retorna 0 para indicar que o programa terminou sem erros
}

