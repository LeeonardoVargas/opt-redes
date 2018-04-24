/*
	Author: Yru� Giovan Neris - yruigneris@gmail.com - 2017
	Universidade Federal da Fronteira Sul - Chapec� - SC
	Trabalho de Conclus�o de Curso:
		- Ci�ncia da Computa��o
		- Problema Quadr�tico de Aloca��o aplicado ao Mapeamento de Topologias de Redes �pticas de Transporte de Telecomunica��es
*/

int roletaSeleciona(double *P) {
	int i;

	double valorRand;
	double somaP = 0.0;
	valorRand = ((double)rand() / (double)RAND_MAX);
	//Sorteia um valor double 
	for (i = 0; i < nPop; i++) {
		somaP += P[i];
		//P � a popula��o, cada um da popula��o recebe um valo, quando o valor sorteado for menor que a soma, traz o ultimo i
		//Exemplo: i = 0 tem valor 10 e i = 1 tem valor 15, e o sorteado foi o 20, no primeiro caso vai comaparar 15 > 20,
		//na proxima intera��o vai somar 10 + 15 e vai comparar com 25 > 20, e vai traz o i = 1, pois o valor sorteado,
		//esta no intervalo de i = 1;
		if (somaP > valorRand) {
			return i;
		}
	}

	return i - 1;
}