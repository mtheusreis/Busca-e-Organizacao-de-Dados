#include <stdlib.h>
#include "lista_enc.h"

typedef struct no {
    ITEM *item;
    struct no *prox;
} No;

struct lista_enc {
    No *inicio;
    int tam;
};

LISTA_ENC *lista_enc_criar(void) {
    LISTA_ENC *l = (LISTA_ENC *) malloc(sizeof(LISTA_ENC));
    if (l) {
        l->inicio = NULL;
        l->tam = 0;
    }
    return l;
}

void lista_enc_liberar(LISTA_ENC *l) {
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

int lista_enc_vazia(LISTA_ENC *l) {
    if (!l) return 1;
    return l->inicio == NULL;
}

int lista_enc_tamanho(LISTA_ENC *l) {
    if (!l) return 0;
    return l->tam;
}

int lista_enc_inserir(LISTA_ENC *l, int posicao, ITEM *item) {
    if (!l || posicao < 0 || posicao > l->tam) return 0;
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) return 0;
    novo->item = item;
    if (posicao == 0) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        No *anterior = l->inicio;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->prox;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    l->tam++;
    return 1;
}

ITEM *lista_enc_remover(LISTA_ENC *l, int posicao) {
    if (!l || lista_enc_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
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

ITEM *lista_enc_buscar(LISTA_ENC *l, int posicao) {
    if (!l || lista_enc_vazia(l) || posicao < 0 || posicao >= l->tam) return NULL;
    No *atual = l->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->item;
}