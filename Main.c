#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Basic_optimization(){}

void optization_intermediary(){}

void advanced_optimization(){}

void colortext(int color){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);}

int main(){

    colortext(1);
    printf("\notimizacao fraca ira desabilitar  aplicativos em segundo plano, ativar modo jogo\n");

    colortext(2);
    printf("\nOtimizacao media ira fazer tudo oque a otimizacao fraca faz porem ira tambem mudar seu plano de energia do pc ou nootbook\n");

    colortext(4);
    printf("\notimizacao forte ira fazer tudo isso e tambem desabilitar servicos inuteis\ne alguns deixar manual irei citar alguns logo a baixo");




    colortext(7);
    int choice;
    printf("\nEscolha qual meio de otimizacao voce quer\n1-Otimizacao fraca\n2-otimizacao media\n3-otimizacao forte: ");


    scanf("%d", &choice);
    switch (choice){
    case 1:
    Basic_optimization();
    break;

    case 2: 
    optization_intermediary();
    break;
    }
}

