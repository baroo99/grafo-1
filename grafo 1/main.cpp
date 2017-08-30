#pragma once
#include <iostream>
#include "Grafo.h"
using namespace std;

int main() {
	Grafo* g = new Grafo();
	int tamanho = 6;
	int* v = new int[tamanho];
	// cria grafo de tamanho tamanho
	g->criaGrafo(tamanho);

	// cria uma adjacência entre i e j com custo P;
	g->criaAdjacente(0, 1, 1);
	g->criaAdjacente(0, 3, 3);
	g->criaAdjacente(0, 5, 10);
	g->criaAdjacente(1, 2, 1);
	g->criaAdjacente(1, 3, 5);
	g->criaAdjacente(2, 4, 2);
	g->criaAdjacente(2, 5, 4);
	g->criaAdjacente(3, 4, 4);
	g->criaAdjacente(4, 5, 1);
	g->criaAdjacente(1, 0, 1);
	g->criaAdjacente(3, 0, 3);
	g->criaAdjacente(5, 0, 10);
	g->criaAdjacente(3, 1, 5);
	g->criaAdjacente(2, 1, 1);
	g->criaAdjacente(4, 2, 2);
	g->criaAdjacente(5, 2, 4);
	g->criaAdjacente(4, 3, 4);
	g->criaAdjacente(5, 4, 1);
	g->criaAdjacente(2, 1, 1);
	
	g->imprimeGrafo();			//Imprime a matriz de adjacencias
	cout << endl;

	// retorna o número de adjacentes ao vértice i no grafo e os armazena no vetor v
	///cout <<"Numero de adjacencias nessa linha: " << g->retAdjacentes(2, v) << endl;
	// atualiza a informação do nó i com o valor V que é uma string
	g->setaInformacao(0, "0 ");
	g->setaInformacao(1, "1 ");
	g->setaInformacao(2, "2 ");
	g->setaInformacao(3, "3 ");
	g->setaInformacao(4, "4 ");
	g->setaInformacao(5, "5 ");
	cout << "Vertices do grafo: ";
	g->imprimeVertices();
	cout << endl;
	cout << endl;
	// remove a adjacência entre i e j no grafo;
	///g->removeAdjacencia(2, 1);
	cout << "Valor do melhor caminho: ";
	cout << g->melhorCaminho(3,5);
	cout << endl;
	cout << endl;
	cout << "Melhor caminho: ";
	g->imprimeCaminho(3, 5);
	cout << endl;
	cout << endl;
	///for (size_t i = 0; i < tamanho; i++)
	///{
	///	cout << v[i] << " ";
	///}

}