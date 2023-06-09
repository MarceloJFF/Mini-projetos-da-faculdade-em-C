//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "foge_foge.h"
#include "mapa/mapa.h"

//  Variaveis structs
mapa m;
personagem heroi;
inimigo *fantasmas;

//  Funcao que localiza as coordenadas do personagem na matriz
void localizar_personagem(void)
{
    for(int linha = 0; linha < m.linha; linha++)
    {
        for(int coluna = 0; coluna < m.coluna; coluna++)
        {
            if(m.matriz[linha][coluna] == MAPA_PERSONAGEM)
            {
                heroi.x = linha;
                heroi.y = coluna;
            }
        }
    }
}

//  Funcao que movimenta o personagem
void movimentar_personagem(char comando)
{
    int x = heroi.x;
    int y = heroi.y;
    switch(comando)
    {
        case(CIMA_PERSONAGEM):
            x--;
            break;
        case(BAIXO_PERSONAGEM):
            x++;
            break;
        case(DIREITA_PERSONAGEM):
            y++;
            break;
        case(ESQUERDA_PERSONAGEM):
            y--;
            break;
        default:
            return;
    }
    if(verificar_movimento_personagem(x, y))
    {
        return;
    }
    atualizar_personagem(x, y);
}

//  Funcao que verifica se o movimento do personagem e valido
int verificar_movimento_personagem(int x, int y)
{
    if(m.matriz[x][y] != MAPA_CAMINHO && m.matriz[x][y] != MAPA_OBETIVO)
    {
        return 1;
    }
    return 0;
}

//  Funcao que atualiza a posicao do personagem
void atualizar_personagem(int x, int y)
{
    if(m.matriz[x][y] == MAPA_OBETIVO)
    {
        m.objetivo--;
    }
    m.matriz[x][y] = MAPA_PERSONAGEM;
    m.matriz[heroi.x][heroi.y] = MAPA_CAMINHO;
    heroi.x = x;
    heroi.y = y;
}

//  Funcao que localiza as coordenadas dos fantasmas no mapa
void localizar_fantasmas(void)
{
    fantasmas = malloc(sizeof(int) * m.fantasmas);
    int fantasmas_numero = 0;
    for(int linha = 0; linha < m.linha; linha++)
    {
        for(int coluna = 0; coluna < m.coluna; coluna++)
        {
            if(m.matriz[linha][coluna] == MAPA_FANTASMA)
            {
                fantasmas[fantasmas_numero].x = linha;
                fantasmas[fantasmas_numero].y = coluna;
                fantasmas_numero++;
            }
        }
    }
}

//  Funcao que movimenta os fantasmas
void movimentar_fantasmas(int indice)
{
    int tentativas = 0;
    int x = fantasmas[indice].x;
    int y = fantasmas[indice].y;
    while(tentativas < 10)
    {
        int direcao;
        direcao = rand() % FANTASMA_MOVIMENTOS;
        switch(direcao)
        {
            case(CIMA_FANTASMA):
                x--;
                break;
            case(BAIXO_FANTASMA):
                x++;
                break;
            case(DIREITA_FANTASMA):
                y++;
                break;
            case(ESQUERDA_FANTASMA):
                y--;
                break;
            default:
                printf("Erro ao movimentar fantasma! \n");
                exit(1);
        }
        if(verificar_movimento_fantasmas(x, y))
        {
            x = fantasmas[indice].x;
            y = fantasmas[indice].y;
            tentativas++;
            continue;
        }
        tentativas = 10;
    }
    atualizar_fantasmas(indice, x, y);
    indice++;
    if(indice < m.fantasmas)
    {
        movimentar_fantasmas(indice);
    }
}

//  Funcao que verifica se o movimento e valido
int verificar_movimento_fantasmas(int x, int y)
{
    if(m.matriz[x][y] != MAPA_CAMINHO && m.matriz[x][y] != MAPA_PERSONAGEM)
    {
        return 1;
    }
    return 0;
}

//  Funcao que atualiza a posicao do fantasmas
void atualizar_fantasmas(int indice, int x, int y)
{
    m.matriz[x][y] = MAPA_FANTASMA;
    m.matriz[fantasmas[indice].x][fantasmas[indice].y] = MAPA_CAMINHO;
    fantasmas[indice].x = x;
    fantasmas[indice].y = y;
}

//  Funcao que verifica se o jogador morreu
int verificar_gameover(void)
{
    if(m.matriz[heroi.x][heroi.y] != MAPA_PERSONAGEM)
    {
        system("clear");
        imprimir_mapa(&m);
        printf("Voce morreu! \n");
        return 0;
    }
    if(m.objetivo == 0)
    {
        system("clear");
        imprimir_mapa(&m);
        printf("Voce ganhou! \n");
        return 0;
    }
    return 1;
}