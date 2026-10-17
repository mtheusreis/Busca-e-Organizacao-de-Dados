#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    ITEM *item;
    struct no *prox;
} No;

struct pilha {
    No *topo;
    int tam;
};

PILHA *pilha_criar(void) {
    PILHA *p = (PILHA *) malloc(sizeof(PILHA));
    if (p) {
        p->topo = NULL;
        p->tam = 0;
    }
    return p;
}

void pilha_liberar(PILHA *p) {
    if (!p) return;
    No *atual = p->topo;
    while (atual) {
        No *aux = atual;
        atual = atual->prox;
        item_liberar(aux->item);
        free(aux);
    }
    free(p);
}

int pilha_vazia(PILHA *p) {
    if (!p) return 1;
    return p->topo == NULL;
}

int pilha_empilhar(PILHA *p, ITEM *item) {
    if (!p) return 0;
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) return 0;
    novo->item = item;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
    return 1;
}

ITEM *pilha_desempilhar(PILHA *p) {
    if (!p || pilha_vazia(p)) return NULL;
    No *aux = p->topo;
    ITEM *item = aux->item;
    p->topo = aux->prox;
    free(aux);
    p->tam--;
    return item;
}

ITEM *pilha_topo(PILHA *p) {
    if (!p || pilha_vazia(p)) return NULL;
    return p->topo->item;
}

int pilha_tamanho(PILHA *p) {
    if (!p) return 0;
    return p->tam;
}