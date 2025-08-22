# Desafio Detective Quest – Tema 4

## Sobre o Desafio

`Detective Quest` é um protótipo de jogo de mistério em C, desenvolvido para a Enigma Studios. O projeto demonstra a aplicação prática de estruturas de dados avançadas — Árvore Binária, Árvore de Busca Binária (BST) e Tabela Hash — como mecânicas centrais para a jogabilidade. O jogador assume o papel de um detetive que deve explorar uma mansão, coletar pistas e associá-las a suspeitos para resolver um crime.

## Estrutura do Projeto

O código foi desenvolvido de forma modular para isolar a lógica de cada estrutura de dados e facilitar a manutenção, uma prática essencial na engenharia de software.

-   `main.c`: O ponto de entrada da aplicação. Controla o loop principal do jogo e a interação com o jogador via terminal.
-   `mapa_arvore_binaria.h` / `.c`: Implementa uma **Árvore Binária** para representar o mapa da mansão.
-   `pistas_arvore_busca.h` / `.c`: Implementa uma **Árvore de Busca Binária (BST)** para armazenar e organizar as pistas encontradas.
-   `tabela_hash_suspeitos.h` / `.c`: Implementa uma **Tabela Hash** para criar associações rápidas entre pistas e suspeitos.
-   `jogo.h` / `.c`: O módulo principal que integra as três estruturas de dados e gerencia o estado e as regras do jogo.

## Estruturas de Dados e Suas Aplicações

### 1. Árvore Binária (Mapa da Mansão)

-   **Aplicação:** Representa a planta da mansão de forma não-linear. Cada nó da árvore é um cômodo, e suas ramificações (esquerda e direita) são os caminhos possíveis para outros cômodos.
-   **Funcionamento:** O jogador navega pela mansão ao "percorrer" a árvore, movendo-se do nó pai para um dos nós filhos. A estrutura é estática e pré-definida para criar um layout consistente para o desafio.

### 2. Árvore de Busca Binária (Catálogo de Pistas)

-   **Aplicação:** Armazena as pistas que o jogador encontra. A principal vantagem é que as pistas são mantidas em ordem (neste caso, por um ID numérico).
-   **Funcionamento:** Quando uma nova pista é encontrada, ela é inserida na BST. A qualquer momento, o jogador pode visualizar seu "caderno de anotações", e as pistas serão exibidas de forma ordenada (usando um percurso *in-order* na árvore), o que facilita a organização mental do caso.

### 3. Tabela Hash (Vínculo Pista-Suspeito)

-   **Aplicação:** Cria uma associação direta e extremamente rápida entre uma pista (chave) e um suspeito (valor).
-   **Funcionamento:** Quando uma pista é adicionada ao inventário, uma entrada correspondente é criada na Tabela Hash. Isso permite uma consulta com complexidade de tempo média de O(1) para responder à pergunta: "Quem é o suspeito relacionado a esta pista?". Colisões são tratadas usando a técnica de **encadeamento separado**.

## Mecânica do Jogo

1.  **Navegação:** O jogador se move entre os cômodos da mansão usando os comandos "esquerda" e "direita", percorrendo a **Árvore Binária** do mapa.
2.  **Investigação:** Em cada cômodo, o jogador pode investigar para encontrar pistas.
3.  **Coleta de Dados:** Ao encontrar uma pista, ela é automaticamente adicionada à **BST de Pistas** e registrada na **Tabela Hash** com seu respectivo suspeito.
4.  **Resolução:** O jogador pode, a qualquer momento, revisar as pistas coletadas (que serão exibidas em ordem) e as associações na tabela hash para deduzir quem é o culpado e fazer uma acusação.

## Como Compilar e Executar

Você precisará de um compilador C (como o GCC). No terminal, navegue até a pasta onde os arquivos foram salvos e execute o comando de compilação:

```bash
gcc main.c mapa_arvore_binaria.c pistas_arvore_busca.c tabela_hash_suspeitos.c jogo.c -o detective_quest
