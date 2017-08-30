#include "No.h"



No::No()
{
}

No::No(std::string _nome)
{
	nome = _nome;
}

std::string No::mostraNome()
{
	return this->nome;
}


No::~No()
{
}
