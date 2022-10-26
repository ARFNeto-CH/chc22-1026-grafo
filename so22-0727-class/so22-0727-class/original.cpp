#include <iostream>
#include <string>

using namespace std;

class Funcionario {
public:
    Funcionario() {}

    // função que define o nome do funcionário
    void setNome(string nome) {
        nomeFuncionario = nome;
    }

    // função que define o cpf
    void setCPF(string CPF) {
        cpf = CPF;
    }

    // função que define a data de admissão
    void setDataAdmissao(string data_admissao) {
        data = data_admissao;
    }

    // função que define o salário
    void setSalarioFuncionario(float salario_funcionario) {
        salario = salario_funcionario;
    }

    // função que obtém o nome do funcionário
    string getNome() {
        return nomeFuncionario;
    }

    // função que obtém o cpf
    string getCPF() {
        return cpf;
    }

    // função que obtém a data de admissão
    string getDataAdmissao() {
        return data;
    }

    // função que obtém o salário
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

    // Chamadas das funções para definir os dados do funcionario
    cout << "Entre com o nome do funcionário:" << endl;
    getline(cin, nomeDoFuncionario);
    funcionario1.setNome(nomeDoFuncionario);

    cout << "Entre com a data de admissão:" << endl;
    cin >> dataAdmissao;
    funcionario1.setDataAdmissao(dataAdmissao);

    cout << "Entre com o cpf do funcionário:" << endl;
    cin >> cpf;
    funcionario1.setCPF(cpf);

    cout << "Entre com o salário do funcionário:" << endl;
    cin >> salario;
    funcionario1.setSalarioFuncionario(salario);

    // Funcionario 2

    Funcionario funcionario2; // cria o objeto RepresentacaoFuncionario chamado Funcionario2

        // Chamadas das funções para definir os dados do funcionario
    cout << "Entre com o nome do funcionário:" << endl;
    getline(cin, nomeDoFuncionario);
    funcionario2.setNome(nomeDoFuncionario);

    cout << "Entre com a data de admissão:" << endl;
    cin >> dataAdmissao;
    funcionario2.setDataAdmissao(dataAdmissao);

    cout << "Entre com o cpf do funcionário:" << endl;
    cin >> cpf;
    funcionario2.setCPF(cpf);

    cout << "Entre com o salário do funcionário:" << endl;
    cin >> salario;
    funcionario2.setSalarioFuncionario(salario);

    return 0;

}