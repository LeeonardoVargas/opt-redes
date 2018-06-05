// GA Parametros
int MaxItO = 5000;          //% N�mero m�ximo de itera��es
int nPopO = 70;           //% Tamanho da Popula��o

double pcO = 0.8;				  //% Porcentagem de Crossover
int ncO = 2 * round(pcO*nPopO / 2);  //% N�mero de pais

double pmO = 0.8;                 //% Porcentagem que sofrer� muta��o
int nmO = round(pmO*nPopO);         //% N�mero de muta��es

int betaO = 1;                    //% Selection Pressure Utilizado para Roleta


//Fun��o
//bool existe(int *caminhoVet, int valor, int quantidade) {
//	int i;
//	for (i = 0; i < quantidade; i++) {
//		if (caminhoVet[i] == valor)
//			return true;
//	}
//	return false;
//}

//Converte vetor em string separando por ','
char* caminhoParaStringO(int *caminhoVet) {
	int i;
	char cstr[300] = "";
	string caminhoChar;
	caminhoChar.clear();
	for (i = 0; i < quantidadeVertices; i++) {
		caminhoChar += to_string(caminhoVet[i]);

		if (i < quantidadeVertices - 1)
			caminhoChar += ',';
	}
	strcpy(cstr, caminhoChar.c_str());
	return cstr;
}

//Le o caminho separado por ',' e gera um vetor
int *caminhoParaVetorO(int *caminhoVet, char caminho[tamanhoString]) {

	char caminhoChar[tamanhoBloco];

	strcpy(caminhoChar, caminho);
	int posicao = 0;
	char *token;

	token = strtok(caminhoChar, ",");

	while (posicao < quantidadeVertices) {
		caminhoVet[posicao] = atoi(token);
		posicao++;
		token = strtok(NULL, ",");
	}

	return caminhoVet;
}

char* buscaParametrosGAO() {
	char parametros[tamanhoString] = "";

	sprintf(parametros, "\nParametros do GA:\nN� Iteracoes = %d\nTamanho Popula��o = %d\nPorc. de Crossover = %f\nPorc. Muta��o = %f\nPress�o de Sele��o = %d", MaxItO, nPopO, pcO, pmO, betaO);
	return parametros;
}