#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
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