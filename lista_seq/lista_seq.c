#include <stdlib.h>
#include "lista_seq.h"

struct lista_seq {
    ITEM **itens;
    int capacidade;
    int fim;
};

LISTA_SEQ *lista_seq_criar(int capacidade) {
    if (capacidade <= 0) return NULL;
    LISTA_SEQ *l = (LISTA_SEQ *) malloc(sizeof(LISTA_SEQ));
    if (l) {
        l->itens = (ITEM **) malloc(capacidade * sizeof(ITEM *));
        if (!l->itens) {
            free(l);
            return NULL;
        }
        l->capacidade = capacidade;
        l->fim = 0;
    }
    return l;
}

void lista_seq_liberar(LISTA_SEQ *l) {
    if (!l) return;
    for (int i = 0; i < l->fim; i++) {
        item_liberar(l->itens[i]);
    }
    free(l->itens);
    free(l);
}

int lista_seq_vazia(LISTA_SEQ *l) {
    if (!l) return 1;
    return l->fim == 0;
}

int lista_seq_cheia(LISTA_SEQ *l) {
    if (!l) return 1;
    return l->fim == l->capacidade;
}

int lista_seq_tamanho(LISTA_SEQ *l) {
    if (!l) return 0;
    return l->fim;
}

int lista_seq_inserir(LISTA_SEQ *l, int posicao, ITEM *item) {
    if (!l || lista_seq_cheia(l)) return 0;
    if (posicao < 0 || posicao > l->fim) return 0;
    for (int i = l->fim; i > posicao; i--) {
        l->itens[i] = l->itens[i - 1];
    }
    l->itens[posicao] = item;
    l->fim++;
    return 1;
}

ITEM *lista_seq_remover(LISTA_SEQ *l, int posicao) {
    if (!l || lista_seq_vazia(l)) return NULL;
    if (posicao < 0 || posicao >= l->fim) return NULL;
    ITEM *item = l->itens[posicao];
    for (int i = posicao; i < l->fim - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }
    l->fim--;
    return item;
}

ITEM *lista_seq_buscar(LISTA_SEQ *l, int posicao) {
    if (!l || lista_seq_vazia(l)) return NULL;
    if (posicao < 0 || posicao >= l->fim) return NULL;
    return l->itens[posicao];
}