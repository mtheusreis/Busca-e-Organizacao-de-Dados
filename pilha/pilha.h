#ifndef PILHA_H
#define PILHA_H

#include "item.h"

typedef struct pilha PILHA;

PILHA *pilha_criar(void);
void pilha_liberar(PILHA *p);
int pilha_vazia(PILHA *p);
int pilha_empilhar(PILHA *p, ITEM *item);
ITEM *pilha_desempilhar(PILHA *p);
ITEM *pilha_topo(PILHA *p);
int pilha_tamanho(PILHA *p);

#endif