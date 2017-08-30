#include "Grafo.h"

Grafo::Grafo(){}

void Grafo::criaGrafo(int _tamanho){
	tamanho = _tamanho;
	
	matriz = new int*[tamanho];
	for (size_t i = 0; i < tamanho; i++)
	{
		matriz[i] = new int[tamanho];
	}

	vertices = new No[tamanho];

	for (size_t i = 0; i < tamanho; i++)
	{
		for (size_t j = 0; j < tamanho; j++)
		{
			matriz[i][j] = INF;
		}
	}

	m_fechamento = new bool*[tamanho];
	for (size_t i = 0; i < tamanho; i++)
	{
		m_fechamento[i] = new bool[tamanho];
	}
	caminho = new int[tamanho];
}

void Grafo::criaAdjacente(int x, int y, int _peso)
{
	matriz[x][y] = _peso;
}

void Grafo::imprimeGrafo()
{
	for (size_t i = 0; i < tamanho; i++)
	{
		for (size_t j = 0; j < tamanho; j++)
		{
			std::cout << matriz[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Grafo::removeAdjacencia(int x, int y)
{
	matriz[x][y] = INF;
}

void Grafo::setaInformacao(int i,std::string _nome)
{
	No* no = new No(_nome);
	vertices[i] = *no;
}

void Grafo::imprimeVertices()
{
	for (size_t j = 0; j < tamanho; j++)
	{
		std::cout << vertices[j].mostraNome();
	}
}

int Grafo::retAdjacentes(int x, int* _adj)
{
	int count = 0;
	
	for (size_t j = 0; j < tamanho; j++)
	{
		if (matriz[x][j] != INF) {
			_adj[count] = j;
			count++;
		}
		
	}

	return count;
}

int Grafo::retPeso(int x, int y) {
	if (matriz[x][y] != INF) {
		return matriz[x][y];
	}
	return INF;
}

bool **Grafo::fechamento()
{
		for (size_t i = 0; i < tamanho; i++)		
		{											
			for (size_t j = 0; j < tamanho; j++)
			{
				if (matriz[i][j] != INF) {
					m_fechamento[i][j] = true;
				}
				else {
					m_fechamento[i][j] = false;
				}
			}
		}
	return m_fechamento;
}

// algoritmo de Warshall
void Grafo::warshall() {
	bool **matrizboolaux = fechamento();
	for (size_t k = 0; k < tamanho; k++)
	{
		for (size_t i = 0; i < tamanho; i++)
		{
			if (matrizboolaux[i][k])
				for (size_t j = 0; j < tamanho; j++)
					matrizboolaux[i][j] = matrizboolaux[i][j] || matrizboolaux[k][j];
		}
	}
}

int Grafo::melhorCaminho(int orig, int dest)
{
	int *distancia = new int[tamanho];
	bool *perm = new bool[tamanho];
	int corrente, dc, j;
	int k = orig;
	int menorDist, novaDist;

	//inicialização
	for (size_t i = 0; i < tamanho; i++)
	{
		perm[i] = naoMembro;
		distancia[i] = INF;
		caminho[i] = -1;
	}
	perm[orig] = membro;
	distancia[orig] = 0;
	corrente = orig;
	while (corrente != dest) {
		menorDist = INF;
		dc = distancia[corrente];
		for (size_t i = 0; i < tamanho; i++) {
			if (!perm[i]) {
				novaDist = dc + retPeso(corrente, i);
				if (novaDist < distancia[i]) {
					distancia[i] = novaDist;
					caminho[i] = corrente;
				}
				if (distancia[i] < menorDist) {
					menorDist = distancia[i];
					k = i;
				//std::cout << k;
				}
			}
		}
		corrente = k;
		perm[corrente] = membro;
	}
	return distancia[dest];
}
void Grafo::imprimeCaminho(int orig, int dest) {
	std::list<std::string> l_caminho (tamanho);
	std::list<std::string>::iterator it;
	int i = caminho[dest];
	it = l_caminho.begin();
	l_caminho.insert(it, vertices[dest].mostraNome());
	
	while (i != orig) {
		l_caminho.push_back(vertices[i].mostraNome());
		i = caminho[i];
	}
	it = l_caminho.end();
	l_caminho.insert (it, vertices[i].mostraNome());

	l_caminho.reverse();
	for (it = l_caminho.begin(); it != l_caminho.end(); ++it)
		std::cout << *it;
}

void Grafo::imprimeMatriz() {
	for (size_t i = 0; i < tamanho; i++)
	{
		for (size_t j = 0; j < tamanho; j++)
		{
			std::cout << m_fechamento[i][j] << " ";
		}
		std::cout << std::endl;

	}
}




Grafo::~Grafo()
{
}
