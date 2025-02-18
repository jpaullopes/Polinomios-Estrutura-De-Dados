# Projeto de Manipulação de Polinômios

Este projeto é uma atividade acadêmica que visa implementar e manipular polinômios utilizando listas encadeadas em linguagem C. O projeto inclui diversas funções para criar, exibir, adicionar termos, avaliar, derivar e destruir polinômios.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

*   **`head.h`:** Contém as definições das estruturas e declarações das funções para manipulação de listas ordenadas e polinômios.
*   **`functions.c`:** Implementa as funções declaradas em `head.h`.
*   **`main.c`:** Contém a função principal do programa, que demonstra o uso das funções implementadas em `functions.c`.

## Estruturas de Dados

### Lista Ordenada

Uma lista ordenada é usada como base para a representação de polinômios. A estrutura de um nó da lista ordenada é definida como:

```c
typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;
```

### Polinômio

Um polinômio é representado como uma lista encadeada de termos. Cada termo é composto por um coeficiente (um número de ponto flutuante) e um expoente (um número inteiro). A estrutura de um termo de polinômio é definida como:

```c
typedef struct poli {
    float coef;
    int expo;
    struct poli *prox;
} *Poli;
```

Um polinômio é, portanto, uma lista de termos onde cada termo é um nó com um coeficiente, um expoente e um ponteiro para o próximo termo.

## Função `sum(Poli P, Poli Q)`

A função `sum` realiza a soma de dois polinômios representados por listas encadeadas. A função recebe dois polinômios, `P` e `Q`, como parâmetros e retorna um novo polinômio `R` que é a soma dos dois.

### Implementação da Função `sum_base`

```c
Poli sum_base(Poli Q, Poli P){
    Poli R = NULL; 
    while(Q != NULL){ // Enquanto Q não for nulo
        adt(Q->coef, Q->expo, &R); // Adiciona o termo de Q em R
        Q = Q->prox;
    }
    while(P != NULL){
        adt(P->coef, P->expo, &R); // Adiciona o termo de P em R
        P = P->prox; //P avança
    }
    return R;
}
```

### Descrição

*   **Entrada:** Dois polinômios, `P` e `Q`, representados como listas encadeadas de termos.
*   **Saída:** Um novo polinômio `R` que representa a soma de `P` e `Q`.
*   **Processo:**
    1. **Inicialização:** Um novo polinômio `R` é criado como NULL.
    2. **Iteração sobre P:** A função percorre cada termo do polinômio `P`. Para cada termo, a função `adt` é chamada para adicionar o termo ao polinômio `R`.
    3. **Iteração sobre Q:** A função percorre cada termo do polinômio `Q`. Para cada termo, a função `adt` é chamada para adicionar o termo ao polinômio `R`.
    4. **Retorno:** A função retorna o polinômio resultante `R`.

### Considerações Importantes

*   **Função `adt`:** A função `adt` é responsável por adicionar um termo a um polinômio existente, mantendo a ordenação correta dos termos por expoente e simplificando termos com o mesmo expoente.

## Outras Funções do Projeto

O projeto também inclui outras funções para manipulação de polinômios, como:

*   **`termo(float c, int e, Poli p)`:** Cria um novo termo de polinômio com coeficiente `c`, expoente `e` e próximo termo `p`.
*   **`exibep(Poli p)`:** Exibe um polinômio no formato `+c*x^e`, onde `c` é o coeficiente e `e` é o expoente.
*   **`adt(float c, int e, Poli *p)`:** Adiciona um termo com coeficiente `c` e expoente `e` a um polinômio `p`, mantendo a ordenação e simplificando termos com o mesmo expoente.
*   **`valor(Poli p, float x)`:** Avalia um polinômio `p` para um dado valor de `x`.
*   **`derivada(Poli p)`:** Calcula a derivada de um polinômio `p`.
*   **`destroip(Poli *p)`:** Libera a memória alocada para um polinômio `p`.
*   **`Poli sum(Poli Q, Poli P)`:** Faz a mesma coisa que a `sum_base(Poli P, Poli Q)` mas cria um polinômio vazio, e não um NULL.
## Exemplo de Uso (`main.c`)

```c
#include <stdio.h>
#include "head.h"

int main() {
    // Criação de polinômios
    Poli P = termo(3, 4, termo(-2, 2, termo(5, 0, NULL)));
    Poli Q = termo(1, 3, termo(2, 2, termo(-1, 1, NULL)));

    // Exibição dos polinômios
    printf("Polinomio P: ");
    exibep(P);
    printf("\n");

    printf("Polinomio Q: ");
    exibep(Q);
    printf("\n");

    // Soma dos polinômios
    Poli R = sum_base(P, Q);
    printf("Polinomio R (P + Q): ");
    exibep(R);
    printf("\n");

    // Avaliação do polinômio R para x = 2
    float resultado = valor(R, 2);
    printf("Valor de R para x = 2: %.2f\n", resultado);

    // Derivada do polinômio R
    Poli S = derivada(R);
    printf("Polinomio S (derivada de R): ");
    exibep(S);
    printf("\n");

    // Liberação da memória
    destroip(&P);
    destroip(&Q);
    destroip(&R);
    destroip(&S);

    return 0;
}
```

## Conclusão

Este projeto fornece uma implementação robusta e eficiente para manipulação de polinômios usando listas encadeadas em C. As funções fornecidas permitem criar, exibir, adicionar termos, avaliar, derivar e destruir polinômios, tornando-o uma ferramenta útil para diversas aplicações matemáticas e computacionais.
