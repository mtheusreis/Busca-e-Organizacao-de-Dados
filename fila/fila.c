#include <stdlib.h>
#include "fila.h"

typedef struct no {
    ITEM *item;
    struct no *prox;
} No;

struct fila {
    No *inicio;
    No *fim;
    int tam;
};

FILA *fila_criar(void) {
    FILA *f = (FILA *) malloc(sizeof(FILA));
    if (f) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tam = 0;
    }
    return f;
}

void fila_liberar(FILA *f) {
    if (!f) return;
    No *atual = f->inicio;
    while (atual) {
        No *aux = atual;
        atual = atual->prox;
        item_liberar(aux->item);
        free(aux);
    }
    free(f);
}

int fila_vazia(FILA *f) {
    if (!f) return 1;
    return f->inicio == NULL;
}

int fila_inserir(FILA *f, ITEM *item) {
    if (!f) return 0;
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) return 0;
    novo->item = item;
    novo->prox = NULL;
    if (f->fim) {
        f->fim->prox = novo;
    } else {
        f->inicio = novo;
    }
    f->fim = novo;
    f->tam++;
    return 1;
}

ITEM *fila_remover(FILA *f) {
    if (!f || fila_vazia(f)) return NULL;
    No *aux = f->inicio;
    ITEM *item = aux->item;
    f->inicio = aux->prox;
    if (!f->inicio) {
        f->fim = NULL;
    }
    free(aux);
    f->tam--;
    return item;
}

ITEM *fila_frente(FILA *f) {
    if (!f || fila_vazia(f)) return NULL;
    return f->inicio->item;
}

int fila_tamanho(FILA *f) {
    if (!f) return 0;
    return f->tam;
}