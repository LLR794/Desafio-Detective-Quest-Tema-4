#include <stdio.h>
#include <stdlib.h>
#include "pistas_arvore_busca.h"

NoPista* criar_no_pista(Pista p) {
    NoPista* novo_no = (NoPista*) malloc(sizeof(NoPista));
    novo_no->pista = p;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Insere uma pista na BST de forma ordenada pelo ID
NoPista* inserir_pista(NoPista* raiz, Pista p) {
    if (raiz == NULL) {
        return criar_no_pista(p);
    }
    if (p.id < raiz->pista.id) {
        raiz->esquerda = inserir_pista(raiz->esquerda, p);
    } else if (p.id > raiz->pista.id) {
        raiz->direita = inserir_pista(raiz->direita, p);
    }
    return raiz;
}

// Imprime as pistas em ordem (percurso in-order)
void imprimir_pistas_in_order(NoPista* raiz) {
    if (raiz != NULL) {
        imprimir_pistas_in_order(raiz->esquerda);
        printf("  - Pista #%d: %s\n", raiz->pista.id, raiz->pista.descricao);
        imprimir_pistas_in_order(raiz->direita);
    }
}

// Libera a memória da árvore usando percurso pós-ordem
void liberar_arvore_pistas(NoPista* raiz) {
    if (raiz == NULL) return;
    liberar_arvore_pistas(raiz->esquerda);
    liberar_arvore_pistas(raiz->direita);
    free(raiz);
}
