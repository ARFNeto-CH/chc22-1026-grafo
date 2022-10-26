// https://pt.stackoverflow.com/questions/560165/%c3%89-poss%c3%
// advel-criar-um-objeto-automaticamente-em-c
#include <iostream>
#include <string>
#include "Funcionario.h"
#include "Setor.h"

using namespace std;

int main(void)
{

    string nome;
    string cpf;
    string data;
    float salario;

    //// Funcionario 1
    //cout << "Entre com o nome do funcionário: " << endl;
    //getline(cin, nome);
    //cout << "Entre com a data de admissão:" << endl; 
    //cin >> data;
    //cout << "Entre com o cpf do funcionário:" << endl;
    //cin >> cpf;
    //cout << "Entre com o salário do funcionário:" << endl;
    //cin >> salario;
    //
    //Funcionario f1(nome, cpf, data, salario); // primeiro

    //// Funcionario 2
    //cout << "Entre com o nome do funcionário: " << endl;
    //getline(cin, nome);
    //cout << "Entre com a data de admissão:" << endl;
    //cin >> data;
    //cout << "Entre com o cpf do funcionário:" << endl;
    //cin >> cpf;
    //cout << "Entre com o salário do funcionário:" << endl;
    //cin >> salario;

    //Funcionario f2(nome, cpf, data, salario); // segundo

    Setor ctn("Contabilidade", 10);
    cout << "Setor " << ctn.nome << " tem " << ctn.n << "  funcionarios:\n"
        "  Nome\t\tSalario\n";
    for (auto i = 0; i < ctn.n; i += 1)
        cout << ctn.f[i].getNome() <<
            "\t\t" << ctn.f[i].getSalario() << "\n";
    cout << endl;
    return 0;

}