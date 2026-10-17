#include <stdlib.h>
#include "lista_ord.h"

typedef struct no {
    ITEM *item;
    struct no *prox;
} No;

struct lista_ord {
    No *inicio;
    int tam;
};

LISTA_ORD *lista_ord_criar(void) {
    LISTA_ORD *l = (LISTA_ORD *) malloc(sizeof(LISTA_ORD));
    if (l) {
        l->inicio = NULL;
        l->tam = 0;
    }
    return l;
}

void lista_ord_liberar(LISTA_ORD *l) {
    if (!l) return;
    No *atual = l->inicio;
    while (atual) {
        No *aux = atual;
        atual = atual->prox;
        item_liberar(aux->item);
        free(aux);
    }
    free(l);
}

int lista_ord_vazia(LISTA_ORD *l) {
    if (!l) return 1;
    return l->inicio == NULL;
}

int lista_ord_tamanho(LISTA_ORD *l) {
    if (!l) return 0;
    return l->tam;
}

int lista_ord_inserir(LISTA_ORD *l, ITEM *item) {
    if (!l || !item) return 0;
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) return 0;
    novo->item = item;

    No *anterior = NULL;
    No *atual = l->inicio;

    while (atual && 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!anterior) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    l->tam++;
    return 1;
}

ITEM *lista_ord_remover(LISTA_ORD *l, int posicao) {
    if (!l || lista_ord_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
    No *alvo = NULL;
    ITEM *item = NULL;
    if (posicao == 0) {
        alvo = l->inicio;
        l->inicio = alvo->prox;
    } else {
        No *anterior = l->inicio;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->prox;
        }
        alvo = anterior->prox;
        anterior->prox = alvo->prox;
    }
    item = alvo->item;
    free(alvo);
    l->tam--;
    return item;
}

ITEM *lista_ord_buscar(LISTA_ORD *l, int posicao) {
    if (!l || lista_ord_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
    No *atual = l->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->item;
}