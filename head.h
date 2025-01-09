#ifndef LSTORD_H
#define LSTORD_H

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

// Funções para manipulação de lista ordenada
Lista no(Item x, Lista p);
void ins(Item x, Lista *L);
void rem(Item x, Lista *L);
int em(Item x, Lista L);
void exibe(Lista L);

// Estrutura para representar um termo de polinômio
typedef struct poli {
    float coef;
    int expo;
    struct poli *prox;
} *Poli;

// Funções para manipulação de polinômios
Poli termo(float c, int e, Poli p);
void exibep(Poli p);
void adt(float c, int e, Poli *p);
float valor(Poli p, float x);
Poli derivada(Poli p);
void destroip(Poli *p);
Poli sum(Poli Q, Poli P);

#endif