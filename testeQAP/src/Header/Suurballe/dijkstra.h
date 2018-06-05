/*
	Author: Yru� Giovan Neris - yruigneris@gmail.com - 2017
	Universidade Federal da Fronteira Sul - Chapec� - SC
	Trabalho de Conclus�o de Curso:
		- Ci�ncia da Computa��o
		- Problema Quadr�tico de Aloca��o aplicado ao Mapeamento de Topologias de Redes �pticas de Transporte de Telecomunica��es
*/

//Encontra o menor vertice visinho ainda n�o visitado, e n�o esta na arvore de caminho mais curto
int verticeMenorDistancia(double dist[], bool visitado[])
{
	// Initialize min value
	double min = INT_MAX;
	int vertice;

	for (int v = 0; v < quantidadeVertices; v++) {
		if (visitado[v] == false && dist[v] <= min) {
			min = dist[v];
			vertice = v;
		}
	}

	return vertice;
}

//Fun��o que calcula a dist�ncia d� caminho de uma unica origem
int* dijkstra(int *caminho, double *matrizAdjacencia, int noOrigem, int noDestino)
{
	double *dist = new double[quantidadeVertices];     //Vetor que contem a distancia da origem para o Vertice index
	bool *visitado = new bool[quantidadeVertices];; //Vetor que contem se o n� indice ja foi visitado
	int *caminhoAux = new int[quantidadeVertices];
	int *anterior = new int[quantidadeVertices];


	//Todas as distancias n�o s�o visitadas, e nenhum vertice esta visitado
	for (int i = 0; i < quantidadeVertices; i++) {
		dist[i] = INT_MAX;
		visitado[i] = false;
		anterior[i] = -1;
	}
	//Distancia do vertice para ele mesmo � 0
	dist[noOrigem] = 0.0;

	//Encontra o menor caminho do vertice origem para os demais
	for (int count = 0; count < quantidadeVertices - 1; count++)
	{
		//Pega o vertice de distancia minima n�o visitado, onde na primeira vez � sempre o vertice de origem
		int u = verticeMenorDistancia(dist, visitado);

		//O vertice com a distancia minima � marcado como visitado
		visitado[u] = true;

		// Atualize o valor dist dos v�rtices adjacentes do v�rtice escolhido.
		for (int v = 0; v < quantidadeVertices; v++) {

			//Atualiza a distancia do vertice vizinho caso o vertice n�o foi visitado, existe conex�o entre os vertices
			//e a distancia do caminho � menor que a distancia do vizinho. Atualizando o vetor dos v�rtices anteriores
			if (!visitado[v] && matrizAdjacencia[u * quantidadeVertices + v] && dist[u] != INT_MAX	&& dist[u] + matrizAdjacencia[u * quantidadeVertices + v] < dist[v]) {
				dist[v] = dist[u] + matrizAdjacencia[u * quantidadeVertices + v];
				anterior[v] = u;
			}
		}
	}
	//printf("Caminho: ");
	int posicao = 0;
	int v, h = 0;
	for (v = noDestino; v != -1; v = anterior[v], posicao++) {
		caminhoAux[posicao] = v;

	}

	for (v = posicao - 1; v >= 0; v--, h++) {
		caminho[h] = caminhoAux[v];
	}

	free(dist);
	free(visitado);
	free(caminhoAux);
	free(anterior);

	return caminho;
}
