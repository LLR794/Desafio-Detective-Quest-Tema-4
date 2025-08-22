#include <stdio.h>
#include "jogo.h"

// "Banco de dados" do jogo
Pista banco_de_pistas[] = {
    {1, "Carta Rasgada"}, {2, "Taca Quebrada"}, {3, "Documento Secreto"},
    {4, "Faca Ensanguentada"}, {5, "Pegada de Bota"}
};
const char* suspeito_da_pista[] = {
    "Coronel Mostarda", "Dona Branca", "Professor Plum", "Mordomo", "Coronel Mostarda"
};

void inicializar_jogo(Jogo* jogo) {
    construir_mapa_mansao(&jogo->mapa_mansao);
    jogo->local_atual_jogador = jogo->mapa_mansao;
    jogo->pistas_encontradas = NULL;
    jogo->relacoes_pista_suspeito = criar_tabela_hash();
    for(int i=0; i<6; i++) jogo->pistas_coletadas[i] = 0; // Nenhuma pista coletada
    
    printf("Bem-vindo ao Detective Quest! Um crime ocorreu nesta mansao.\n");
    printf("Explore os comodos, encontre as pistas e descubra o culpado.\n");
}

void imprimir_estado_atual(const Jogo* jogo) {
    printf("\n--------------------------------------------------\n");
    printf("Voce esta em: %s\n", jogo->local_atual_jogador->nome_comodo);
    if (jogo->local_atual_jogador->esquerda) {
        printf("  [E]squerda: %s\n", jogo->local_atual_jogador->esquerda->nome_comodo);
    }
    if (jogo->local_atual_jogador->direita) {
        printf("  [D]ireita: %s\n", jogo->local_atual_jogador->direita->nome_comodo);
    }
}

void mover_jogador(Jogo* jogo, char direcao) {
    if ((direcao == 'e' || direcao == 'E') && jogo->local_atual_jogador->esquerda) {
        jogo->local_atual_jogador = jogo->local_atual_jogador->esquerda;
    } else if ((direcao == 'd' || direcao == 'D') && jogo->local_atual_jogador->direita) {
        jogo->local_atual_jogador = jogo->local_atual_jogador->direita;
    } else {
        printf("Caminho invalido.\n");
    }
}

void investigar_comodo(Jogo* jogo) {
    int id = jogo->local_atual_jogador->id_pista;
    if (id == 0) {
        printf("Voce investiga o comodo, mas nao encontra nada de novo.\n");
        return;
    }
    if (jogo->pistas_coletadas[id] == 1) {
        printf("Voce ja coletou a pista deste comodo.\n");
        return;
    }

    // Encontrou uma nova pista!
    Pista pista_achada = banco_de_pistas[id - 1];
    const char* suspeito_ligado = suspeito_da_pista[id - 1];
    printf("\n!!! NOVA PISTA ENCONTRADA: %s !!!\n", pista_achada.descricao);
    
    // Adiciona na Árvore de Busca Binária
    jogo->pistas_encontradas = inserir_pista(jogo->pistas_encontradas, pista_achada);
    
    // Adiciona na Tabela Hash
    inserir_na_tabela(jogo->relacoes_pista_suspeito, pista_achada.descricao, suspeito_ligado);
    
    jogo->pistas_coletadas[id] = 1; // Marca como coletada
}

void acusar_suspeito(const Jogo* jogo) {
     printf("\nQuem voce acusa pelo crime?\n");
     printf("1. Coronel Mostarda\n2. Dona Branca\n3. Professor Plum\n4. Mordomo\n");
     int escolha;
     scanf("%d", &escolha);
     
     // Lógica simples de vitória: Coronel Mostarda tem 2 pistas.
     if (escolha == 1) {
         printf("\nACUSACAO CORRETA! O Coronel Mostarda, com seu passado suspeito, foi descuidado e deixou duas pistas.\nVoce solucionou o caso! Parabens, detetive!\n");
     } else {
         printf("\nACUSACAO INCORRETA! O verdadeiro culpado escapou enquanto voce perdia tempo com o suspeito errado...\n");
     }
}

void encerrar_jogo(Jogo* jogo) {
    liberar_mapa(jogo->mapa_mansao);
    liberar_arvore_pistas(jogo->pistas_encontradas);
    liberar_tabela(jogo->relacoes_pista_suspeito);
    printf("\nJogo encerrado. Toda a memoria foi liberada.\n");
}
