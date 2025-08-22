#ifndef MAPA_ARVORE_BINARIA_H
#define MAPA_ARVORE_BINARIA_H

// Nó da árvore, representando um cômodo na mansão
typedef struct NoMapa {
    char nome_comodo[50];
    // A pista que pode ser encontrada neste cômodo (id 0 se não houver)
    int id_pista;
    struct NoMapa *esquerda;
    struct NoMapa *direita;
} NoMapa;

// Protótipos
NoMapa* criar_no_mapa(const char* nome, int id_pista);
void construir_mapa_mansao(NoMapa** raiz);
void liberar_mapa(NoMapa* raiz);

#endif // MAPA_ARVORE_BINARIA_H
