#include<iostream>
#include<clocale>
#include"funcoesFila.h"
#include"dadosEntrada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    FilaDuplamenteEncadeada<string> filaPrioridade; cria(filaPrioridade);

    bool isQuitTrue = false;
    do{
        Menu();
        int op1 = inputOptionMenu();
        switch(op1){
            case 1:
                system("clear||cls");
                inputInsere(filaPrioridade);
                break;
            case 2:
                system("clear||cls");
                removePorPrioridade(filaPrioridade);
                break;
            case 3:
                system("clear||cls");
                inputVerificaElemento(filaPrioridade);
                break;
            case 4:
                system("clear||cls");
                cout<<"*Elemento -> Prioridade*"<<endl;
                mostra(filaPrioridade);
                cout<<endl;
                mostraOrdenado(filaPrioridade);
                system("PAUSE");
                system("clear||cls");
                break;
            case 5:
                cout<<"========="<<endl;
                cout<<"Sa�ndo..."<<endl;
                isQuitTrue = true;
        }
    }while(!isQuitTrue);

    destroiFila(filaPrioridade);
    return 0;
}
