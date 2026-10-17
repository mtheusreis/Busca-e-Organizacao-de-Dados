#ifndef ITEM_H
#define ITEM_H

typedef struct item_ ITEM;

ITEM *item_criar(
    char *titulo, char *diretor, float avaliacao_media, char *genero, 
    int duracao, char *lingua, char *desc, char *estudios, 
    long long assistidos, long long ap_list, long long likes, long long fans,
    long long lowest, long long medium, long long highest, long long total_av
);

void item_liberar(ITEM *item);

void item_imprimir(ITEM *item);

ITEM *item_ler_csv(char *linha_csv);

#endif