# Desafio: Nível Mestre - Batalha Naval com Habilidades Especiais

<details>
<summary><strong>Resumo do Projeto</strong></summary>

Neste desafio avançado do jogo Batalha Naval, adicionamos habilidades especiais com áreas de efeito diferenciadas para dar um toque estratégico no jogo. O tabuleiro mantém o formato 10x10 e habilidades em forma de Cone, Cruz e Octaedro são representadas por matrizes que indicam as áreas afetadas.

</details>

<details>
<summary><strong>Funcionalidades</strong></summary>

- Tabuleiro 10x10 para visualização dos navios e áreas de efeito.  
- Três matrizes de habilidades especiais:  
  - Cone (forma triangular expandindo para baixo)  
  - Cruz (área em forma de cruz, com ponto central)  
  - Octaedro (formato losangular, vista frontal)  
- Ponto de origem definido no tabuleiro para cada habilidade.  
- Sobreposição das matrizes de habilidades ao tabuleiro com marcação das áreas afetadas.  
- Visualização clara das áreas com caracteres diferentes no console:
  - Água (0)  
  - Navio (3)  
  - Área afetada pela habilidade (5)  

</details>

<details>
<summary><strong>Como Rodar o Projeto</strong></summary>

```bash
# Clone o repositório
git clone https://github.com/vitoriafmachado/desafio-batalha-naval.git

# Entre na pasta do projeto
cd desafio-batalha-naval

# Compile o programa (supondo gcc)
gcc batalha_naval.c -o batalha_naval

# Execute o programa
./batalha_naval
