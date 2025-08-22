#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa_arvore_binaria.h"

NoMapa* criar_no_mapa(const char* nome, int id_pista) {
    NoMapa* novo_no = (NoMapa*) malloc(sizeof(NoMapa));
    strcpy(novo_no->nome_comodo, nome);
    novo_no->id_pista = id_pista;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Constrói a estrutura fixa do mapa da mansão
void construir_mapa_mansao(NoMapa** raiz) {
    *raiz = criar_no_mapa("Hall de Entrada", 0);
    (*raiz)->esquerda = criar_no_mapa("Biblioteca", 1); // Pista 1: Carta Rasgada
    (*raiz)->direita = criar_no_mapa("Sala de Jantar", 2); // Pista 2: Taca Quebrada
    (*raiz)->esquerda->esquerda = criar_no_mapa("Escritorio", 3); // Pista 3: Documento Secreto
    (*raiz)->direita->esquerda = criar_no_mapa("Cozinha", 4); // Pista 4: Faca Ensanguentada
    (*raiz)->direita->direita = criar_no_mapa("Jardim de Inverno", 5); // Pista 5: Pegada de Bota
}

// Libera a memória da árvore usando percurso pós-ordem
void liberar_mapa(NoMapa* raiz) {
    if (raiz == NULL) return;
    liberar_mapa(raiz->esquerda);
    liberar_mapa(raiz->direita);
    free(raiz);
}
