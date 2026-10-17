#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAX_STR 300
#define MAX_DESC 1500

struct item_ {
    char titulo[MAX_STR];
    char diretor[MAX_STR];
    float avaliacao_media;
    char genero[MAX_STR];
    int duracao;
    char lingua[MAX_STR];
    char desc[MAX_DESC];
    char estudios[MAX_STR];
    long long assistidos;
    long long ap_list;
    long long likes;
    long long fans;
    long long lowest;
    long long medium;
    long long highest;
    long long total_av;
};

ITEM *item_criar(
    char *titulo, char *diretor, float avaliacao_media, char *genero, 
    int duracao, char *lingua, char *desc, char *estudios, 
    long long assistidos, long long ap_list, long long likes, long long fans,
    long long lowest, long long medium, long long highest, long long total_av
) {
    ITEM *item = (ITEM *) malloc(sizeof(ITEM));
    if (!item) return NULL;

    snprintf(item->titulo, MAX_STR, "%s", titulo ? titulo : "");
    snprintf(item->diretor, MAX_STR, "%s", diretor ? diretor : "");
    item->avaliacao_media = avaliacao_media;
    snprintf(item->genero, MAX_STR, "%s", genero ? genero : "");
    item->duracao = duracao;
    snprintf(item->lingua, MAX_STR, "%s", lingua ? lingua : "");
    snprintf(item->desc, MAX_DESC, "%s", desc ? desc : "");
    snprintf(item->estudios, MAX_STR, "%s", estudios ? estudios : "");
    item->assistidos = assistidos;
    item->ap_list = ap_list;
    item->likes = likes;
    item->fans = fans;
    item->lowest = lowest;
    item->medium = medium;
    item->highest = highest;
    item->total_av = total_av;

    return item;
}

void item_liberar(ITEM *item) {
    if (item) {
        free(item);
    }
}

void item_imprimir(ITEM *item) {
    if (!item) return;
    printf("Filme: %s | Diretor: %s | Nota: %.2f | Duração: %d min | Likes: %lld\n",
           item->titulo, item->diretor, item->avaliacao_media, item->duracao, item->likes);
}

ITEM *item_ler_csv(char *linha_csv) {
    if (!linha_csv || strlen(linha_csv) == 0) return NULL;

    linha_csv[strcspn(linha_csv, "\r\n")] = '\0';

    char *copia = strdup(linha_csv);
    if (!copia) return NULL;

    char *token;

    token = strtok(copia, "\t");
    if (!token) {
        free(copia);
        return NULL;
    }

    token = strtok(NULL, "\t");
    char *titulo = token ? token : "";

    token = strtok(NULL, "\t");
    char *diretor = token ? token : "";

    token = strtok(NULL, "\t");
    float avaliacao_media = token ? atof(token) : 0.0f;

    token = strtok(NULL, "\t");
    char *genero = token ? token : "";

    token = strtok(NULL, "\t");
    int duracao = token ? atoi(token) : 0;

    token = strtok(NULL, "\t");
    char *lingua = token ? token : "";

    token = strtok(NULL, "\t");
    char *desc = token ? token : "";

    token = strtok(NULL, "\t");
    char *estudios = token ? token : "";

    token = strtok(NULL, "\t");
    long long assistidos = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long ap_list = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long likes = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long fans = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long lowest = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long medium = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long highest = token ? atoll(token) : 0;

    token = strtok(NULL, "\t");
    long long total_av = token ? atoll(token) : 0;

    ITEM *item = item_criar(
        titulo, diretor, avaliacao_media, genero, duracao, lingua, desc, estudios,
        assistidos, ap_list, likes, fans, lowest, medium, highest, total_av
    );

    free(copia);
    return item;
}