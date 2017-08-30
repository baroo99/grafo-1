#pragma once
#include <string>
class No
{
private:
	std::string nome;

public:
	No();
	No(std::string _nome);
	std::string mostraNome();
	~No();
};

