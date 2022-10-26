#pragma once
#include <iostream>
using std::string;

class Funcionario {
public:
	Funcionario();
	Funcionario(string, string, string, float);

	void setNome(string nome);
	void setCPF(string CPF);
	void setData(string data_admissao);
	void setSalario(float salario_funcionario);

	string getNome();
	string getCPF();
	string getData();
	float  getSalario();
private:
	string cpf;
	string data;
	string nome;
	float salario;
};
