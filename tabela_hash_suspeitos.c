#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash_suspeitos.h"

// Função de hash simples para strings
unsigned int funcao_hash(const char* chave) {
    unsigned long int valor = 0;
    unsigned int i = 0;
    unsigned int tam_chave = strlen(chave);

    for (; i < tam_chave; i++) {
        valor = valor * 37 + chave[i];
    }
    return valor % TAMANHO_TABELA;
}

TabelaHash* criar_tabela_hash() {
    TabelaHash* tabela = (TabelaHash*) malloc(sizeof(TabelaHash));
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->baldes[i] = NULL;
    }
    return tabela;
}

EntradaHash* criar_entrada(const char* chave, const char* valor) {
    EntradaHash* entrada = (EntradaHash*) malloc(sizeof(EntradaHash));
    entrada->chave_pista = strdup(chave);
    entrada->valor_suspeito = strdup(valor);
    entrada->proximo = NULL;
    return entrada;
}

void inserir_na_tabela(TabelaHash* tabela, const char* chave, const char* valor) {
    unsigned int indice = funcao_hash(chave);
    EntradaHash* nova_entrada = criar_entrada(chave, valor);

    // Adiciona no início da lista encadeada (encadeamento separado)
    nova_entrada->proximo = tabela->baldes[indice];
    tabela->baldes[indice] = nova_entrada;
}

const char* buscar_na_tabela(TabelaHash* tabela, const char* chave) {
    unsigned int indice = funcao_hash(chave);
    EntradaHash* atual = tabela->baldes[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave_pista, chave) == 0) {
            return atual->valor_suspeito;
        }
        atual = atual->proximo;
    }
    return "Ninguem"; // Não encontrou suspeito para essa pista
}

void imprimir_tabela(const TabelaHash* tabela) {
    printf("\n--- RELATORIO DE PISTAS E SUSPEITOS ---\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        EntradaHash* atual = tabela->baldes[i];
        if (atual != NULL) {
            printf("Indice [%d]:\n", i);
            while(atual != NULL) {
                printf("  Pista: '%s' -> Suspeito: %s\n", atual->chave_pista, atual->valor_suspeito);
                atual = atual->proximo;
            }
        }
    }
    printf("----------------------------------------\n");
}


void liberar_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        EntradaHash* atual = tabela->baldes[i];
        while (atual != NULL) {
            EntradaHash* temp = atual;
            atual = atual->proximo;
            free(temp->chave_pista);
            free(temp->valor_suspeito);
            free(temp);
        }
    }
    free(tabela);
}
