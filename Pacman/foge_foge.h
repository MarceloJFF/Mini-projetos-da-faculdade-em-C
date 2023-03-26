#ifndef FOGE_FOGE_H_INCLUDED
#define FOGE_FOGE_H_INCLUDED

/*  Constantes */
#define CIMA_PERSONAGEM 'w'
#define BAIXO_PERSONAGEM 's'
#define DIREITA_PERSONAGEM 'd'
#define ESQUERDA_PERSONAGEM 'a'
#define FANTASMA_MOVIMENTOS 4
#define CIMA_FANTASMA 0
#define BAIXO_FANTASMA 1
#define DIREITA_FANTASMA 2
#define ESQUERDA_FANTASMA 3

/*  Struct */
//  Personagem
struct dados_personagem
{
    int x;
    int y;
};
typedef struct dados_personagem personagem;
//  inimigo
struct dados_fantasmas
{
    int x;
    int y;
};
typedef struct dados_fantasmas inimigo;

/*  Funcoes */
void localizar_personagem(void);
void movimentar_personagem(char comando);
int verificar_movimento_personagem(int x, int y);
void atualizar_personagem(int x, int y);
void localizar_fantasmas(void);
void movimentar_fantasmas(int indice);
int verificar_movimento_fantasmas(int x, int y);
void atualizar_fantasmas(int indice, int x, int y);
int verificar_gameover(void);

#endif // FOGE_FOGE_H_INCLUDED