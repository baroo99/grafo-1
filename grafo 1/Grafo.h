#pragma once
#include "No.h"
#include <iostream>
#include<limits>
#include <list>
#define INF 999999
class Grafo
{
private:
	
	int tamanho = 0;
	bool membro = true;
	bool naoMembro = false;
	int** matriz;
	bool **m_fechamento;
	int *caminho;
	No* vertices;
public:
	Grafo();
	void criaGrafo(int _nos);
	void criaAdjacente(int x, int y, int _peso);
	void imprimeGrafo();
	void removeAdjacencia(int x, int y);
	void setaInformacao(int i, std::string _nome);
	void imprimeVertices();
	int retAdjacentes(int x, int* _adjacentes);
	int retPeso(int x, int j);
	bool **fechamento();
	void warshall();
	int melhorCaminho(int orig, int dest);
	void imprimeCaminho(int orig, int dest);
	void imprimeMatriz();
	~Grafo();
};

