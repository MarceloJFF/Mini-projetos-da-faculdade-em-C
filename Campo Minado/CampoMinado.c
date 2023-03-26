  /* Instituto Federal do Maranhão
    Data: 12/11/2020
    Disciplina: Linguagem de Programacao I
    Professora: Evaldinolia Gilbertoni Moreira
    Alunos: Marcelo Jhones e Julio Evencio dos Anjos Igreja
    Atividade de Vetores, Elaboracao de um Campo Minado em C*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void geraCampoMinado();
void mostrarCampoMinado();
void jogada();
void facil();
void mediano();
void dificil();
void bombaMina();
void campoMinadoFinal();
int coluna, linha;
int nivel;
int total_minas = 0;
int minas = 0;
int campoMinado[25][25];
int x, y;
int mina_Copia[25][25];
int final_CampoMinado[25][25];

void main(){
    printf("\t JOGO CAMPO MINADO\n");
    nivel = 0;
    do{
        printf(" 1 ---- Facil \n");
        printf(" 2 ---- Mediano \n");
        printf(" 3 ---- Dificil \n");
        printf("\t Escolha um nivel: \n");
        scanf("%d", &nivel);

        if((nivel != 1) && (nivel != 2) && (nivel != 3)){
            printf("\t Nivel invalido \n");
        }
    }while(nivel<1 && nivel>3);

    if(nivel == 1){                  //Escolha do nivel
        facil();}
    else if(nivel == 2){
        mediano();}
    else if(nivel == 3){
        dificil();}
}

void facil(){                         //Modo facil
    coluna = 9;
    linha = 9;
    total_minas = 10;
    geraCampoMinado();
    jogada();
}


void dificil(){                                      //Joga no modo dificil
    coluna = 16;
    linha = 20;
    total_minas = 90;
    geraCampoMinado();
    jogada();
}

void mediano(){                                      //Joga em dificuldade media
    coluna = 16;
    linha = 16;
    total_minas = 40;
    geraCampoMinado();
    jogada();
}



void geraCampoMinado(){                            //Funcao que gera as minas
    int i = 0, j = 0;

    srand(time(NULL));
    for(i=0;i<linha; i++){
        for(j=0;j<coluna;j++){
            campoMinado[i][j] = '-';
            mina_Copia[i][j] = campoMinado[i][j];
            final_CampoMinado[i][j] = campoMinado[i][j];
        }
    }
    for(minas = 0; minas < total_minas;minas++){//gerando as minas em posicoes aleatorias
        i = rand()%(linha);
        j = rand()%(coluna);
        if(campoMinado[i][j]!= '*'){
            campoMinado[i][j] = '*';
            final_CampoMinado[i][j]= campoMinado[i][j];
        }
    }
    //aqui embaixo coloca quantas bombas adjacentes tem em cada posicao vazia
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            if( campoMinado[i][j] != '*'){
                campoMinado[i][j] = 0;
            }
            if((campoMinado[i-1][j-1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i][j-1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i-1][j] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i-1][j+1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i+1][j-1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i+1][j] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i][j+1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }
            if((campoMinado[i+1][j+1] == '*') && (campoMinado[i][j] != '*')){
                campoMinado[i][j]++;
            }

        }
    }
}
void mostrarCampoMinado(void){// mostrando a interface do campo minado
    int i = 0, j = 0, r = 0;
    while(r < coluna ){
        if(r == 0 ){
            printf("\t");
        }
        printf("%d \t", r);
        r++;
    }
    printf("\n\n");
    for(i=0;i<linha;i++){
        printf("%d\t",i);
        for(j=0;j<coluna;j++){
            if(mina_Copia[i][j] == '-'){
                printf("%c\t", mina_Copia[i][j]);
            }
            else if(campoMinado[i][j] == 0){
                mina_Copia[i][j] = '0';
                printf("%c\t", mina_Copia[i][j]);
            }
            else{
                printf("%d\t", mina_Copia[i][j]);
            }
        }
        printf("\n");
    }
}


void jogada(){ // Funcao para efetuar as jogadas
    int i=0, j=0, cont=0;
    printf("\n");
    mostrarCampoMinado();
    printf("\n");
    for(i=0;i<linha; i++){
        for(j=0;j<coluna;j++){
            if(campoMinado[i][j] == mina_Copia[i][j]){
                cont++;}
        }
    }
    if(cont == (( coluna * linha ) - total_minas)){                 //Testa se a quantidade de jogadas "cont" é igual a area - total de minas para verificar s eo jogador ganhou
         printf("\n\n\n\tVoce Ganhou !!!!!\n\n\n");
         exit(1);
    }
    printf("\n Escolha as duas coordenadas das bombas:");
    scanf("%d %d", &x, &y); // Pegando as coordenadas
    system("cls");
    if((x >= linha) || (y >= coluna)|| (x < 0) || (y < 0)){
        printf("\n Digite um valor dentro do intervalo\n");
        jogada();
    }
    if(campoMinado[x][y] == '*' ){                            // Se o jogador escolhe a coordenada que tem bomba carrega essa funcao
        bombaMina();
    }
    if(mina_Copia[x][y] != '-' ){
        printf("\n Coordenada ja Digitada\n");
        jogada();
    }
    else {
        mina_Copia[x][y] = campoMinado[x][y]; //posicao que o usuario digita armazenada no array
        if(campoMinado[x][y] == 0 ){
            if(campoMinado[x-1][y-1] == 0){
                mina_Copia[x-1][y] = campoMinado[x-1][y];
            }
            if(campoMinado[x-1][y] == 0 ){
                mina_Copia[x-1][y] = campoMinado[x-1][y];
            }
            if(campoMinado[x][y-1] == 0 ){
                mina_Copia[x][y-1] = campoMinado[x][y-1];
            }
            if(campoMinado[x-1][y+1] == 0 ){
                mina_Copia[x-1][y+1] = campoMinado[x-1][y+1];
            }
            if(campoMinado[x+1][y-1] == 0 ){
                mina_Copia[x+1][y-1] = campoMinado[x+1][y-1];
            }
            if(campoMinado[x+1][y] == 0 ){
                mina_Copia[x+1][y] = campoMinado[x+1][y];
            }
            if(campoMinado[x][y+1] == 0 ){
                mina_Copia[x][y+1] = campoMinado[x][y+1];
            }
            if(campoMinado[x+1][y+1] == 0 ){
                mina_Copia[x+1][y+1] = campoMinado[x+1][y+1];
            }
        }
        jogada();
    }
}

void bombaMina(){         //Funcao que encerra o programa quando o jogado seleciona uma bomba
    campoMinadoFinal();
    printf("\n\t\tNessa coordenada havia uma mina %d,%d\n\t Voce perdeu!!!! \n \n", x, y);
    exit(1);

}

void campoMinadoFinal(){// Printa o campo Minado mostrando a localizacao de todas as minas
    int i = 0, j = 0, k = 0;
    while( k < coluna){
        if( k == 0 ){
            printf("\t");
        }
        printf("%d\t", k);
        k++;
    }
    printf("\n\n");

    for(i=0;i<linha;i++){
        printf("%d\t",i);
        for(j=0;j<coluna;j++){
            printf("%c\t", final_CampoMinado[i][j]);
        }
        printf("\n");
    }
}



