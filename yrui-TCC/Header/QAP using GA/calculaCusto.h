/*
	Author: Yru� Giovan Neris - yruigneris@gmail.com - 2017
	Universidade Federal da Fronteira Sul - Chapec� - SC
	Trabalho de Conclus�o de Curso:
		- Ci�ncia da Computa��o
		- Problema Quadr�tico de Aloca��o aplicado ao Mapeamento de Topologias de Redes �pticas de Transporte de Telecomunica��es
*/

//Calcula o custo dos individuos, verificando se existe conex�o entre os mesmo, caso existir (valor 1), soma a distancia entre os mesmos
double calculaCusto(int *caminho, int validaCusto) {
	int i, j, totalExecedeMaxima = 0; 
	double custo = 0.0;
	//Utiliza as matrizes F e D para montar o custo
	for (i = 0; i < quantidadeVertices; i++) {
		for (j = 0; j < quantidadeVertices; j++) {
			if (j > i && validaCusto == 1 && matrizF[i * quantidadeVertices + j] * matrizD[caminho[i] * quantidadeVertices + caminho[j]] > distanciaMaxima)
				totalExecedeMaxima++;

			//Quando a quantidade de links exceder a distancia maxima permitida o caminho � inv�lido
			if (totalExecedeMaxima > numeroNosExcedeDistanciaMaxima)
				return 0;

			//Verifica se na matriz existe conex�o entre i e j, se existir soma no custo total o valor presente na matriz D
			//do valor na posi��o D[ij]
			if(j > i)
				custo += matrizF[i * quantidadeVertices + j] * matrizD[caminho[i] * quantidadeVertices + caminho[j]];
		}
	}
	return custo;
}