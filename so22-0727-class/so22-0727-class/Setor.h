#pragma once
#include "Funcionario.h"
class Setor
{
public:
	unsigned n;
	string nome;
	Funcionario* f;

	Setor(string nome, unsigned n) : nome(nome), n(n)
	{ f = new Funcionario[n]; }

	~Setor()
	{ delete[] f; } // apaga os funcionarios
};

