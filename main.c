#include <stdio.h>
#include "jogo.h"

int main() {
    Jogo meu_jogo;
    inicializar_jogo(&meu_jogo);
    char comando;

    do {
        imprimir_estado_atual(&meu_jogo);
        printf("\nComandos: (M)over, (I)nvestigar, Ver (P)istas, (A)cusar, (S)air\n");
        printf("O que voce faz, detetive? ");
        scanf(" %c", &comando);

        switch (comando) {
            case 'm':
            case 'M': {
                char direcao;
                printf("Direcao ([E]squerda/[D]ireita): ");
                scanf(" %c", &direcao);
                mover_jogador(&meu_jogo, direcao);
                break;
            }
            case 'i':
            case 'I':
                investigar_comodo(&meu_jogo);
                break;
            case 'p':
            case 'P':
                printf("\n--- SEU CADERNO DE PISTAS ---\n");
                imprimir_pistas_in_order(meu_jogo.pistas_encontradas);
                imprimir_tabela(meu_jogo.relacoes_pista_suspeito);
                break;
            case 'a':
            case 'A':
                acusar_suspeito(&meu_jogo);
                comando = 's'; // Força a saída do loop após acusação
                break;
            case 's':
            case 'S':
                printf("Decidindo encerrar o caso por hoje...\n");
                break;
            default:
                printf("Comando nao reconhecido, detetive.\n");
        }

    } while (comando != 's' && comando != 'S');

    encerrar_jogo(&meu_jogo);
    return 0;
}
