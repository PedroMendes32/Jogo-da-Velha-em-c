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

    jogo();

    printf("\n\n FIM DE JOGO! ");
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
            tabuleiro[i][j] = '_';
        }
    }

    while ( controle == 0 )
    {   
        printf("\n JOGO DA VELHA EM C");
        printf("\n--------------------");
        mostrarTabuleiro(tabuleiro);
        printf("\n\n");
        jogada(tabuleiro);
        verificaVencedor(tabuleiro,&controle);
        
        if ( controle == 1 )
        {
            mostrarTabuleiro(tabuleiro);
            break;
        }
        else
        {
            jogadaPC(tabuleiro);
            verificaVencedor(tabuleiro);

            if ( controle == 1)
            {
                mostrarTabuleiro(tabuleiro);
                break;
            }
        }

        system("cls");
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
            printf("\n - Você já ocupou essa casa! \n");
        }
        else if ( tabuleiro[linha][coluna] == 'O' )
        {
            printf("\n - Essa casa está ocupada! \n");
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
    int verificaEmpate = 0;
    int i,j;

    if (( tabuleiro[0][0] == 'X')&&( tabuleiro[0][1] == 'X' )&&( tabuleiro[0][2] == 'X' ))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[1][0] == 'X')&&( tabuleiro[1][1] == 'X' )&&( tabuleiro[1][2] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[2][0] == 'X')&&( tabuleiro[2][1] == 'X' )&&( tabuleiro[2][2] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][0] == 'X')&&( tabuleiro[1][0] == 'X' )&&( tabuleiro[2][0] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][1] == 'X')&&( tabuleiro[1][1] == 'X' )&&( tabuleiro[2][1] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][2] == 'X')&&( tabuleiro[1][2] == 'X' )&&( tabuleiro[2][2] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][0] == 'X')&&( tabuleiro[1][1] == 'X' )&&( tabuleiro[2][2] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[2][0] == 'X')&&( tabuleiro[1][1] == 'X' )&&( tabuleiro[0][2] == 'X'))
    {
        printf("\n - Você venceu! ");
        *controleJogo = 1;
    }
    //verifica jogadas do computador//

    else if (( tabuleiro[0][0] == 'O')&&( tabuleiro[0][1] == 'O' )&&( tabuleiro[0][2] == 'O' ))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[1][0] == 'O')&&( tabuleiro[1][1] == 'O' )&&( tabuleiro[1][2] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[2][0] == 'O')&&( tabuleiro[2][1] == 'O' )&&( tabuleiro[2][2] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][0] == 'O')&&( tabuleiro[1][0] == 'O' )&&( tabuleiro[2][0] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][1] == 'O')&&( tabuleiro[1][1] == 'O' )&&( tabuleiro[2][1] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][2] == 'O')&&( tabuleiro[1][2] == 'O' )&&( tabuleiro[2][2] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[0][0] == 'O')&&( tabuleiro[1][1] == 'O' )&&( tabuleiro[2][2] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else if ((tabuleiro[2][0] == 'O')&&( tabuleiro[1][1] == 'O' )&&( tabuleiro[0][2] == 'O'))
    {
        printf("\n - Você perdeu! ");
        *controleJogo = 1;
    }
    else
    {
        for ( i = 0; i < LINHA; i++ )
        {
            for ( j = 0; j < COLUNA; j++ )
            {
                if ( tabuleiro[i][j] != '_' )
                {
                    verificaEmpate++;

                    if ( verificaEmpate == 9 )
                    {
                        printf("\n - O jogo empatou! ");
                        *controleJogo = 1;
                    }
                }
            }
        }
    }
}

