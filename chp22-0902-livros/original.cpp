#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#define max 10

int leiaresp();
void leiaquant(int n, int quant[]);
void leianome(int& n, string acervo[]);
void leiautor(string autores[], int n);
void leiaisbn(string isbn[], int n);
void ordenar(string acervo[], int n);
int procurar(string isbn[], int n, int& proc);

int leiaresp() {

    int resp;

    do {
        cout << "qual acao deseja realizar ??" << endl << "1 Cadrastar um livro" << endl << "2 Procurar um livro" << endl << "3 Excluir um livro " << endl << "4 Aquisicao " << endl << "5 Relatorio" << endl << "0 Encerrar programa" << endl;
        cin >> resp;
        cin.ignore();
    } while (resp < 0 && resp >5);

    return resp;
}

void leianome(int& n, string acervo[]) {
    string nome;
    do {
        cout << "Digite o nome do livro " << endl;
        getline(cin, nome);

    } while (nome.size() == 0);
    acervo[n] = nome;
    n++;
}

void leiautor(string autores[], int n) {
    string nome;
    do {
        cout << "Digite o nome completo do autor: " << endl;
        getline(cin, nome);
    } while (nome.size() == 0);
    autores[n] = nome;
}

void leiaisbn(string isbn[], int n) {
    string codigo;
    do {
        cout << "Digite o ISBN do livro, contendo 13 digitos e '-' " << endl;
        getline(cin, codigo);
        for (int j = 0; j <= codigo.size(); j++) {
            if (!isdigit(codigo[j]) && codigo[j] != '-') {
                cout << "Esse ISBN nao e valido " << endl;
                break;
            }
        }
    } while (codigo.size() == 0);

    for (int i = 0; i <= n; i++) {
        if (codigo == isbn[i]) {
            cout << "Esse livro ja existe " << endl;

            break;
        }
    }

}

void leiaquant(int n, int quant[]) {
    int qtnd;
    do {
        cout << "Digiti a quantidade " << endl;
        cin >> qtnd;
        cin.ignore();
    } while (qtnd <= 0);
    quant[n] = qtnd;
}

void ordenar(string acervo[], int n) {

    string nome, aux;
    int i, j, k;

    for (int p = 0; p <= n; p++) {
        nome = acervo[p];
        for (int k = 1; k <= n; k++) {
            aux = acervo[k];
            for (int i = 0; i <= nome.size(); i++) {
                for (int j = 0; j <= aux.size(); j++) {
                    if (nome[i] < aux[j]) {
                        acervo[p] = nome;
                        acervo[k] = aux;
                    }
                    else {
                        acervo[p] = aux;
                        acervo[k] = nome;

                    }
                }
            }
        }
    }
}

int procurar(string isbn[], int n, int& proc) {

    string codigo;

    do {
        cout << "Digite o ISBN  " << endl;
        getline(cin, codigo);
    } while (codigo.size() == 0);

    for (int i = 0; i <= n; i++) {
        if (codigo == isbn[i]) {
            proc = i;
        }
        else {
            proc = 1;
        }
    }
    return 0;
}

int main()
{

    string nome, acervo[max] = {}, autores[max] = {}, codigo, isbn[max] = {};
    int qtnd = 0, quant[max],  proc;
    int n = 0;
    int resp = 0;


    do {
        int resp = leiaresp();
        switch (resp) {

        case 1: {

            leiaisbn(isbn, n);
            leianome(n, acervo);
            leiautor(autores, n);
            leiaquant(n, quant);
            ordenar(acervo, n);
            //system("pause");
            break;
        }

        case 2: {

            procurar(isbn, n, proc);

            cout << isbn[proc] << endl << acervo[proc] << endl << autores[proc] << endl << quant[proc] << endl;
            if (proc == -1) {
                cout << "Este Livro nao esta nos registros. " << endl;
            }
            system("pause");
            break;
        }


        }
        system("clear||cls");
    } while (resp != 0);

    return 0;

}
