#ifndef TABELA_HASH_SUSPEITOS_H
#define TABELA_HASH_SUSPEITOS_H

#define TAMANHO_TABELA 10

// Estrutura para uma entrada na tabela (usando encadeamento separado para colisões)
typedef struct EntradaHash {
    char* chave_pista;
    char* valor_suspeito;
    struct EntradaHash* proximo;
} EntradaHash;

typedef struct {
    EntradaHash* baldes[TAMANHO_TABELA];
} TabelaHash;

// Protótipos
TabelaHash* criar_tabela_hash();
void inserir_na_tabela(TabelaHash* tabela, const char* chave, const char* valor);
const char* buscar_na_tabela(TabelaHash* tabela, const char* chave);
void imprimir_tabela(const TabelaHash* tabela);
void liberar_tabela(TabelaHash* tabela);

#endif // TABELA_HASH_SUSPEITOS_H
