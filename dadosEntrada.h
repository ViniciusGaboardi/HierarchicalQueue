#ifndef DADOSENTRADA_H_INCLUDED
#define DADOSENTRADA_H_INCLUDED

using namespace std;

void Menu() //autoexplicativo
{
    cout<<"Burgoise Queue"<<endl;
    cout<<"======================"<<endl;
    cout<<"1 - Insert Element"<<endl;
    cout<<"2 - Remove Element"<<endl;
    cout<<"3 - Verify Element"<<endl;
    cout<<"4 - Show Queue"<<endl;
    cout<<"5 - Exit"<<endl;
    cout<<"======================"<<endl;
}

void displayPrioridade()
{
    cout<<"Priority Tiers"<<endl;
    cout<<"===================="<<endl;
    cout<<"1 - Tier 1"<<endl;
    cout<<"2 - Tier 2"<<endl;
    cout<<"3 - Tier 3"<<endl;
    cout<<"===================="<<endl;
}

bool checkInputNum(string num) //checagem de dados para input de valores inteiros para o menu
{
    for(int i=0; i<num.length(); i++)
        if(!isdigit(num[i]))
            return false;
    return true;
}

bool checkPrioridade(int num)
{
    if(num<1 or num>3)
        return false;
    return true;
}

int inputOptionMenu() //fun��o para o menu principal (as entradas de 1 a 3 pra acessar cada op��o)
{
    int op1;
    string op;
    bool check;
    do{
        cout<<"Which operation would you like to perform?"<<endl;
        cout<<"A: ";
        getline(cin, op);
        check = checkInputNum(op);
        if((check) and (op!=""))
            op1 = stoi(op);
        if((op1<1 or op1>5) or (op=="")){
            cout<<"That option does not exist."<<endl;
            system("pause");
            system("clear||cls");
        }
    }while(!check and op1<1 and op1>5);
    return op1;
}

template<typename T>
void inputInsere(FilaDuplamenteEncadeada<T> &fila)
{
    T elemento; int prioridade; string checaPrioridade;
    cout<<"Insert"<<endl;
    cout<<"========"<<endl;
    cout<<"Element: ";
    cin>>elemento;
    cin.ignore();
    do{
        displayPrioridade();
        cout<<"Priority Tier: ";
        getline(cin, checaPrioridade);
        if((checkInputNum(checaPrioridade)) and (checaPrioridade!=""))
            prioridade = stoi(checaPrioridade);
        if((!checkPrioridade(prioridade)) or checaPrioridade==""){
            cout<<"Specified level does not exist. Please try again."<<endl;
            system("pause");
            system("clear||cls");
        }
    }while(!checkPrioridade(prioridade));

    insere(fila, elemento, prioridade);
    cout<<"Successfully inserted!"<<endl;
    system("pause");
    system("clear||cls");
}

template<typename T>
void inputVerificaElemento(FilaDuplamenteEncadeada<T> fila)
{
    T elemento;
    cout<<"Verify:"<<endl;
    cout<<"========================"<<endl;
    cout<<"Element: ";
    cin>>elemento;
    if(!existeElemento(fila, elemento))
        cout<<"Element "<<elemento<<" was not found."<<endl;
    else
        cout<<"Element "<<elemento<<" found!"<<endl;

    system("PAUSE");
    system("clear||cls");
}

#endif // DADOSENTRADA_H_INCLUDED
