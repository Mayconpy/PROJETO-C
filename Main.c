#include <stdio.h>
#include <conio.h>
#include <windows.h>
void a();
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    int choice;
    printf("Escolha qual meio de otimizacao voce quer\n1-Otimizacao fraca\n2-otimizacao media\n3-otimizacao forte: ");

    
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
    printf("\notimizacao fraca ira desabilitar  aplicativos em segundo plano, ativar modo jogo\n");
    
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
    printf("\nOtimizacao media ira fazer tudo oque a otimizacao fraca faz porem ira tambem mudar seu plano de energia do pc ou nootbook\n");
    
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    printf("\notimizacao forte ira fazer tudo isso e tambem desabilitar servicos inuteis e alguns deixar manual irei citar alguns logo a baixo");


    scanf("%d", &choice);
    switch (choice){
    case 1:
    printf("s");
    break;
    
    case 2: printf("print");break;
    }
}
