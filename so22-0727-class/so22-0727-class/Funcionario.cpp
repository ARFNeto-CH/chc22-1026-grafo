#include "Funcionario.h"

void Funcionario::setNome(string nome) {
	nome = nome;
}

void Funcionario::setCPF(string CPF) {
	cpf = CPF;
}

void Funcionario::setData(string data_admissao) {
	data = data_admissao;
}

void Funcionario::setSalario(float salario_funcionario) {
	salario = salario_funcionario;
}

string Funcionario::getNome() {
	return nome;
}

string Funcionario::getCPF() {
	return cpf;
}

string Funcionario::getData() {
	return data;
}

float Funcionario::getSalario() {
	return salario;
}

//Funcionario::Funcionario() : salario(0.) {}

Funcionario::Funcionario()
{	// gera um funcionario com
	// "Nome n" "CPF n" "Data n" e salario n
	char nm[20];
	static int num = 0;
	num += 1;
	sprintf(nm, "Nome %d", num);
	nome = nm;
	sprintf(nm, "Data %d", num);
	data = nm;
	sprintf(nm, "CPF %3d.123.456-78", num);
	cpf = nm;
	salario = (float)num + num / 100.f;
};

Funcionario::Funcionario(string n, string cpf, string d, float salario) :
	nome(n), cpf(cpf), data(d), salario(salario) {}
