/*
	Author: Yru� Giovan Neris - yruigneris@gmail.com - 2017
	Universidade Federal da Fronteira Sul - Chapec� - SC
	Trabalho de Conclus�o de Curso:
		- Ci�ncia da Computa��o
		- Problema Quadr�tico de Aloca��o aplicado ao Mapeamento de Topologias de Redes �pticas de Transporte de Telecomunica��es
*/

//Classe que cont�m os caminhos e seus custos
class Caminho {
public:
	char caminho[tamanhoString];
	double custoCaminho;

	//Fun��o utilizada no SORT dos melhores caminhos
	double getCusto() const {
		return custoCaminho;
	}

};

//Fun��es Globais
bool comparaCusto(Caminho a, Caminho b) {
	return a.getCusto() < b.getCusto();
}
