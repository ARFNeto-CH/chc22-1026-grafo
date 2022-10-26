#include <iostream>
#include <string>

using namespace std;

class Funcionario {
public:
    Funcionario() {}

    // fun��o que define o nome do funcion�rio
    void setNome(string nome) {
        nomeFuncionario = nome;
    }

    // fun��o que define o cpf
    void setCPF(string CPF) {
        cpf = CPF;
    }

    // fun��o que define a data de admiss�o
    void setDataAdmissao(string data_admissao) {
        data = data_admissao;
    }

    // fun��o que define o sal�rio
    void setSalarioFuncionario(float salario_funcionario) {
        salario = salario_funcionario;
    }

    // fun��o que obt�m o nome do funcion�rio
    string getNome() {
        return nomeFuncionario;
    }

    // fun��o que obt�m o cpf
    string getCPF() {
        return cpf;
    }

    // fun��o que obt�m a data de admiss�o
    string getDataAdmissao() {
        return data;
    }

    // fun��o que obt�m o sal�rio
    float getSalarioFuncionario() {
        return salario;
    }


private:
    string nomeFuncionario, cpf, data;
    float salario;
};

int main() {

    string nomeDoFuncionario, dataAdmissao, cpf;
    float salario;

    // Funcionario 1

    Funcionario funcionario1; // cria o objeto RepresentacaoFuncionario chamado Funcionario1

    // Chamadas das fun��es para definir os dados do funcionario
    cout << "Entre com o nome do funcion�rio:" << endl;
    getline(cin, nomeDoFuncionario);
    funcionario1.setNome(nomeDoFuncionario);

    cout << "Entre com a data de admiss�o:" << endl;
    cin >> dataAdmissao;
    funcionario1.setDataAdmissao(dataAdmissao);

    cout << "Entre com o cpf do funcion�rio:" << endl;
    cin >> cpf;
    funcionario1.setCPF(cpf);

    cout << "Entre com o sal�rio do funcion�rio:" << endl;
    cin >> salario;
    funcionario1.setSalarioFuncionario(salario);

    // Funcionario 2

    Funcionario funcionario2; // cria o objeto RepresentacaoFuncionario chamado Funcionario2

        // Chamadas das fun��es para definir os dados do funcionario
    cout << "Entre com o nome do funcion�rio:" << endl;
    getline(cin, nomeDoFuncionario);
    funcionario2.setNome(nomeDoFuncionario);

    cout << "Entre com a data de admiss�o:" << endl;
    cin >> dataAdmissao;
    funcionario2.setDataAdmissao(dataAdmissao);

    cout << "Entre com o cpf do funcion�rio:" << endl;
    cin >> cpf;
    funcionario2.setCPF(cpf);

    cout << "Entre com o sal�rio do funcion�rio:" << endl;
    cin >> salario;
    funcionario2.setSalarioFuncionario(salario);

    return 0;

}