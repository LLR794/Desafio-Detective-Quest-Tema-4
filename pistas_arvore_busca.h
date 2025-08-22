#ifndef PISTAS_ARVORE_BUSCA_H
#define PISTAS_ARVORE_BUSCA_H

// Estrutura que define uma pista
typedef struct {
    int id;
    char descricao[100];
} Pista;

// Nó da BST de pistas
typedef struct NoPista {
    Pista pista;
    struct NoPista *esquerda;
    struct NoPista *direita;
} NoPista;

// Protótipos
NoPista* inserir_pista(NoPista* raiz, Pista p);
void imprimir_pistas_in_order(NoPista* raiz); // Imprime em ordem crescente de ID
void liberar_arvore_pistas(NoPista* raiz);

#endif // PISTAS_ARVORE_BUSCA_H
