#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#define LINHA 3
#define COLUNA 3

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
    void verificaVencedor ( char tabuleiro[3][3], int *controleJogo );

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
        verificaVencedor(tabuleiro,&controle);
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

void verificaVencedor ( char tabuleiro[3][3], int *controleJogo )
{
    int i,j;
    int verificaEmpate = 0;
    int verificaTabuleiro[3][3];
    int linha1 = 0,linha2 = 0,linha3 = 0,coluna1 = 0,coluna2 = 0,coluna3 = 0;

    for ( i = 0; i < LINHA; i++ )
    {
        for ( j = 0; j < COLUNA; j++ )
        {
            if ( tabuleiro[i][j] == 'X' )
            {
                verificaTabuleiro[i][j] = 1;
            }
            else if ( tabuleiro[i][j] == 'O' )
            {
                verificaTabuleiro[i][j] = 0;
            }
        }
    }

    for ( i = 0; i < LINHA; i++ )
    {
        linha1 = linha1 + tabuleiro[0][i];

        if ( linha1 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( linha1 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }

        linha2 = linha2 + tabuleiro[1][i];

        if ( linha2 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( linha2 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }

        linha3 = linha3 + tabuleiro[2][i];

        if ( linha3 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( linha3 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }

        coluna1 = coluna1 + tabuleiro[i][0];

        if ( coluna1 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( coluna1 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }

        coluna2 = coluna2 + tabuleiro[i][1];

        if ( coluna2 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( coluna2 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }

        coluna3 = coluna3 + tabuleiro[i][2];

        if ( coluna3 == 3 )
        {
            printf("\n - Você venceu! ");
            *controleJogo = 1;
            break;
        }
        else if ( coluna3 == 0 )
        {
            printf("\n - Você perdeu! ");
            *controleJogo = 1;
            break;
        }
    }

    for ( i = 0; i < LINHA; i++ )
    {
        for ( j = 0; j < COLUNA; j++ )
        {
            if ( tabuleiro[i][j] != ' ' )
            {
                verificaEmpate++;

                if ( verificaEmpate == 9 )
                {
                    printf("\n - O jogo empatou!");
                    *controleJogo = 1;
                    break;
                }
            }
        }
    }


}

