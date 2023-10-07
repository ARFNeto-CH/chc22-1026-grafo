#include <iostream>
#include <queue>
using namespace std;

void display_queue(queue<string>q);
void display_queue(queue<string>q)
{
    while (!q.empty())
    {
        cout << q.front() << " - ";
        q.pop();
    }
}

int main()
{
    int x;
    string y;
    queue<string> clientes;
    cout << "DIGITE 1 para adicionar um novo cliente no final da fila \n";
    cout << "DIGITE 2 para remover o cliente do inicio da fila \n";
    cout << "DIGITE 3 para imprimir todos os clientes da fila \n";
    cout << "DIGITE 4 para imprimir a quantidade de clientes na fila \n";
    cout << "DIGITE 5 para excluir os clientes da fila \n";
    while (x != 5)
    {
        cout << "ESCOLHA ALGUM CASO:" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cout << "digite o nome" << endl;
            cin >> y;
            clientes.push(y);
            cout << "cliente adicionado a fila" << endl;
        }
        break;
        case 2:
        {
            clientes.pop();
            cout << "cliente removido da fila" << endl;
        }
        break;
        case 3:
        {
            cout << "fila atual: ";
            display_queue(clientes);
            cout << endl;
        }
        break;
        case 4:
        {
            cout << "tamanho da fila: " << clientes.size() << endl;
        }
        break;
        case 5:
        {
            terminate;
        }
        break;
        }
    }
}