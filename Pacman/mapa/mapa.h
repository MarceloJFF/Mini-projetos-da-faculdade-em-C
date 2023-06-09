#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

/*  Constantes */
#define MAPA_PERSONAGEM '@'
#define MAPA_FANTASMA 'F'
#define MAPA_OBETIVO 'O'
#define MAPA_CAMINHO '.'
#define MAPA_PAREDE '|'
#define DESENHO_LINHA 4
#define DESENHO_COLUNA 7

/*  Structs */
//  Mapa
struct dados_mapa
{
    char **matriz;
    int linha;
    int coluna;
    int objetivo;
    char fantasmas;
};
typedef struct dados_mapa mapa;

/*  Matrizes */
//  Personagem
char desenho_personagem[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {" .--. "},
    {"/ _.-'"},
    {"\\ '-. "},
    {" '--' "}
};
//  Fantasmas
char desenho_fantasma[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}
};
//  Parede
char desenho_parede[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"......"},
    {"......"},
    {"......"},
    {"......"}
};
//  Caminho
char desenho_caminho[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};
//  Objetivo
char desenho_objetivo[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

/*  Funcoes */
void gerar_matriz(mapa *m);
void ler_mapa(mapa *m);
void imprimir_mapa(mapa *m);
void desenhar_tela(char desenho, int parte);
void identificar_elementos(mapa *mapa);
void liberar_matriz(mapa *m);

#endif // MAPA_H_INCLUDED