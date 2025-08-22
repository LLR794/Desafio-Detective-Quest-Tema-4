#ifndef JOGO_H
#define JOGO_H

#include "mapa_arvore_binaria.h"
#include "pistas_arvore_busca.h"
#include "tabela_hash_suspeitos.h"

// Estrutura aninhada para gerenciar todo o estado do jogo
typedef struct {
    NoMapa* mapa_mansao;
    NoMapa* local_atual_jogador;
    NoPista* pistas_encontradas;
    TabelaHash* relacoes_pista_suspeito;
    int pistas_coletadas[6]; // Vetor para controlar pistas já coletadas
} Jogo;

// Protótipos da lógica do jogo
void inicializar_jogo(Jogo* jogo);
void imprimir_estado_atual(const Jogo* jogo);
void mover_jogador(Jogo* jogo, char direcao);
void investigar_comodo(Jogo* jogo);
void acusar_suspeito(const Jogo* jogo);
void encerrar_jogo(Jogo* jogo);

#endif // JOGO_H
