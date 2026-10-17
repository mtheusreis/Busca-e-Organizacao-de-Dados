#include <stdlib.h>
#include "lista_cabeca.h"

typedef struct no {
    ITEM *item;
    struct no *prox;
} No;

struct lista_cabeca {
    No *cabeca;
    int tam;
};

LISTA_CABECA *lista_cabeca_criar(void) {
    LISTA_CABECA *l = (LISTA_CABECA *) malloc(sizeof(LISTA_CABECA));
    if (l) {
        l->cabeca = (No *) malloc(sizeof(No));
        if (!l->cabeca) {
            free(l);
            return NULL;
        }
        l->cabeca->item = NULL;
        l->cabeca->prox = NULL;
        l->tam = 0;
    }
    return l;
}

void lista_cabeca_liberar(LISTA_CABECA *l) {
    if (!l) return;
    No *atual = l->cabeca;
    while (atual) {
        No *aux = atual;
        atual = atual->prox;
        if (aux->item) {
            item_liberar(aux->item);
        }
        free(aux);
    }
    free(l);
}

int lista_cabeca_vazia(LISTA_CABECA *l) {
    if (!l) return 1;
    return l->tam == 0;
}

int lista_cabeca_tamanho(LISTA_CABECA *l) {
    if (!l) return 0;
    return l->tam;
}

int lista_cabeca_inserir(LISTA_CABECA *l, int posicao, ITEM *item) {
    if (!l || posicao < 0 || posicao > l->tam) return 0;
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) return 0;
    novo->item = item;
    
    No *atual = l->cabeca;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    l->tam++;
    return 1;
}

ITEM *lista_cabeca_remover(LISTA_CABECA *l, int posicao) {
    if (!l || lista_cabeca_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
    
    No *atual = l->cabeca;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    
    No *alvo = atual->prox;
    ITEM *item = alvo->item;
    atual->prox = alvo->prox;
    free(alvo);
    l->tam--;
    return item;
}

ITEM *lista_cabeca_buscar(LISTA_CABECA *l, int posicao) {
    if (!l || lista_cabeca_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
    
    No *atual = l->cabeca->prox;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->item;
}