#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

// Função para criar um novo nó
Lista no(Item x, Lista p) {
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

// Função para inserir um item em uma lista ordenada
void ins(Item x, Lista *L) {
    while (*L != NULL && (*L)->item < x) {
        L = &((*L)->prox);
    }
    *L = no(x, *L);
}

// Função para remover um item de uma lista ordenada
void rem(Item x, Lista *L) {
    while (*L != NULL && (*L)->item < x) {
        L = &((*L)->prox);
    }
    if (*L == NULL || (*L)->item > x) {
        return;
    }
    Lista n = *L;
    *L = n->prox;
    free(n);
}

// Função para verificar se um item está em uma lista ordenada
int em(Item x, Lista L) {
    while (L != NULL && L->item < x) {
        L = L->prox;
    }
    return (L != NULL && L->item == x);
}

// Função para exibir os itens de uma lista ordenada
void exibe(Lista L) {
    while (L != NULL) {
        printf("%d ", L->item);
        L = L->prox;
    }
}

// Função para criar um termo de polinômio
Poli termo(float c, int e, Poli p) {
    Poli n = (Poli)malloc(sizeof(struct poli));
    n->coef = c;
    n->expo = e;
    n->prox = p;
    return n;
}

// Função para exibir um polinômio
void exibep(Poli p) {
    if (p == NULL) {
        return;
    }
    printf("%+.1f", p->coef);
    if (p->expo != 0) {
        printf("*x^%d", p->expo);
    }
    exibep(p->prox);
}

// Função para adicionar um termo a um polinômio
void adt(float c, int e, Poli *p) {
    if (*p == NULL || (*p)->expo < e) { //se o expoente do termo for maior que o expoente do polinômio
        *p = termo(c, e, *p); //adiciona o termo no inicio do polinomio
    } else if ((*p)->expo == e) { //se o expoente do termo for ingual a do polinomio
        (*p)->coef += c;
        if ((*p)->coef == 0) {
            Poli n = *p;
            *p = n->prox;
            free(n);
        }
    } else {
        adt(c, e, &((*p)->prox));
    }
}

// Função para avaliar um polinômio
float valor(Poli p, float x) {
    if (p == NULL) {
        return 0;
    } else {
        return p->coef * pow(x, p->expo) + valor(p->prox, x);
    }
}

// Função para derivar um polinômio
Poli derivada(Poli p) {
    if (p == NULL || p->expo == 0) {
        return NULL;
    }
    return termo(p->coef * p->expo, p->expo - 1, derivada(p->prox));
}

// Função para destruir um polinômio
void destroip(Poli *p) {
    if (*p == NULL) {
        return;
    }
    destroip(&((*p)->prox));
    free(*p);
    *p = NULL;
}

//funcao da questão também mas com a diferença de que ela não cria um polinomio vazio e sim um NULL
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

//função da questao
Poli sum(Poli Q, Poli P){
    Poli R = termo(0, -1, NULL); // Cria um polinômio vazio
    Poli cabeca = R; 
    while(Q != NULL){ // Enquanto Q não for nulo
        adt(Q->coef, Q->expo, &R); // Adiciona o termo de Q em R
        Q = Q->prox;
    }
    while(P != NULL){
        adt(P->coef, P->expo, &R); // Adiciona o termo de P em R
        P = P->prox; //P avança
    }
    R = cabeca->prox; 
    free(cabeca); 
    return R;
}