#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#define linha 3;
#define coluna 3;

void jogo (void);

int main(void)
{

    setlocale( LC_ALL, "Portuguese" );

    printf("\n JOGO DA VELHA EM C");
    printf("\n--------------------");

    jogo();

    printf("\n\n\n");
    system("pause");

    return 0;
}

void jogo ( void )
{
    char tabuleiro[3][3];
    int i,j;
    int controle = 0;
    
    void mostrarTabuleiro( char tabuleiro[3][3] );
    void jogada ( char tabuleiro[3][3]);
    void jogadaPC ( char tabuleiro[3][3] );

    for ( i = 0; i < LINHA; i++ )
    {
        for ( j = 0; j < COLUNA; j++ )
        {
            tabuleiro[i][j] = ' ';
        }
    }

    while ( controle == 0 )
    {
        mostrarTabuleiro(tabuleiro);
        jogada(tabuleiro);
        jogadaPC(tabuleiro);
        mostrarTabuleiro(tabuleiro);
    }
}

void mostrarTabuleiro ( char tabuleiro[3][3] )
{
    int i,j;

    for ( i = 0; i < LINHA; i++ )
    {
        printf("\n");
        for ( j = 0; j < COLUNA; j++ )
        {
            printf(" %c ",tabuleiro[i][j]);
        }
    }
}

void jogada ( char tabuleiro[3][3] )
{
    int linha;
    int coluna;
    int verificaJogada = 0;

    while ( verificaJogada == 0 )
    {
        printf("\n - Digite a linha da sua jogada: ");
        scanf("%d",&linha);
        printf("\n - Digite a coluna da sua jogada: ");
        scanf("%d",&coluna);

        if ( tabuleiro[linha][coluna] == 'X' )
        {
            printf("\n - Você já ocupou essa casa! ");
        }
        else if ( tabuleiro[linha][coluna] == 'O' )
        {
            printf("\n - Essa casa está ocupada! ");
        }
        else
        {
            verificaJogada = 1;
        }
    }

    tabuleiro[linha][coluna] = 'X';
}

void jogadaPC ( char tabuleiro[3][3] )
{
    int linha,coluna;
    int verificaJogada = 0;

    srand(time(NULL));

    while ( verificaJogada == 0 )
    {
        linha = rand() % 3;
        coluna = rand() % 3;

        if ( tabuleiro[linha][coluna] == 'X' )
        {
            verificaJogada = 0;
        }
        else if ( tabuleiro[linha][coluna] == 'O')
        {
            verificaJogada = 0;
        }
        else
        {
            verificaJogada = 1;
        }
    }

    tabuleiro[linha][coluna] = 'O';
}

