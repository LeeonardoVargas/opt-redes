#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>  
#include <time.h>  
#include <conio.h>
#include <limits.h>
#include <fstream>
//#include <Windows.h>

using namespace std;

int quantidadeVertices = 0;
int *matrizF;
int numeroLinks = 0;
double distanciaMaxima;
double porcentagemMaiorDistancia = 0.55; // Parametro que permite quantos % do individuo podem ser maior que a distancia maxima
int numeroNosExcedeDistanciaMaxima = 0;

double *matrizD;
#define tamanhoBloco 500
#define tamanhoString 500

clock_t t0, tf;
double tempo_gasto;

//Caminho que contem as arestas, referente ao caminho dos v�rtices

//ARNES
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Arnes\\arnes_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Arnes\\arnes_17_20.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Arnes\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Arnes\\arnes_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Arnes\\arnes_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Arnes\\";


//ARPNET
//char *caminhoVertices = "N�s - Lat Long\\Originais\\ArpNet\\arpanet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\ArpNet\\arpanet_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\ArpNet\\";

//char *caminhoVertices = "N�s - Lat Long\\Harary\\ArpNet\\arpanet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\ArpNet\\arpanet_20_32.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\ArpNet\\";


//AUSTRIA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Austria\\austria_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Austria\\austria_15_22.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Austria\\";
//
//char *caminhoVertices = "N�s - Lat Long\\Originais\\Austria\\austria_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Austria\\austria_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Austria\\";



//CANARIE
//char *caminhoVertices = "N�s - Lat Long\\Originais\\Canarie\\canarie_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Canarie\\canarie_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Canarie\\";
////
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Canarie\\canarie_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Canarie\\canarie_19_26.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Canarie\\";


//CESNET
//char *caminhoVertices = "N�s - Lat Long\\Originais\\Cesnet\\cesnet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Cesnet\\cesnet_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Cesnet\\";

//char *caminhoVertices = "N�s - Lat Long\\Harary\\Cesnet\\cesnet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Cesnet\\cesnet_12_19.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Cesnet\\";


//CoxUSA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\CoxUSA\\coxUsa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\CoxUSA\\cox_24_40.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\CoxUSA\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\CoxUSA\\coxUsa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\CoxUSA\\coxUsa_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\CoxUSA\\";


//EON
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Eon\\eon_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Eon\\eon_19_37.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Eon\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Eon\\eon_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Eon\\eon_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Eon\\";


//GEANT
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Geant\\geant2_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Geant\\geant2_32_51.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Geant\\";

//char *caminhoVertices = "n�s - lat long\\originais\\geant\\geant2_nodes.txt";
//char *caminhoArestas = "n�s - lat long\\originais\\geant\\geant2_links.txt";
//char *caminhoSaida = "n�s - lat long\\originais\\geant\\";
//

//GERMANI
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Germani\\germany_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Germani\\germany_17_26.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Germani\\";
//
//char *caminhoVertices = "N�s - Lat Long\\Originais\\Germani\\germany_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Germani\\germany_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Germani\\";


//INTERNET2 USA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Internet2 USA\\internet2Usa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Internet2 USA\\internet2_56_61.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Internet2 USA\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Internet2Usa\\internet2Usa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Internet2Usa\\internet2Usa_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Internet2Usa\\";


//ITALY
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Italy\\italy_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Italy\\italy_14_29.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Italy\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Italy\\italy_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Italy\\italy_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Italy\\";


//LAMBDARAILUSA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\LAMBDARAILUSA\\lambdaRailUsa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\LAMBDARAILUSA\\lambdaRailUsa_19_23.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\LAMBDARAILUSA\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\LAMBDARAILUSA\\lambdaRailUsa_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\LAMBDARAILUSA\\lambdaRailUsa_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\LAMBDARAILUSA\\";


//MEMOREX
//////////char *caminhoVertices = "N�s - Lat Long\\Harary\\MemorexEurope\\memorexEurope_nodes.txt";
//////////char *caminhoArestas = "N�s - Lat Long\\Harary\\MemorexEurope\\memorex_19_24.txt";
//////////char *caminhoSaida = "N�s - Lat Long\\Harary\\MemorexEurope\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\MemorexEurope\\memorexEurope_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\MemorexEurope\\memorexEurope_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\MemorexEurope\\";


//METRONA
//////////char *caminhoVertices = "N�s - Lat Long\\Harary\\Metrona\\metrona_UK_nodes.txt";
//////////char *caminhoArestas = "N�s - Lat Long\\Harary\\Metrona\\metrona_33_41.txt";
//////////char *caminhoSaida = "N�s - Lat Long\\Harary\\Metrona\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Metrona\\metrona_UK_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Metrona\\metrona_UK_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Metrona\\";


//MZIMA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Mzima\\mzima_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Mzima\\mzima_15_19.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Mzima\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Mzima\\mzima_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Mzima\\mzima_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Mzima\\";


//NEWNET
//char *caminhoVertices = "N�s - Lat Long\\Harary\\NewNet\\newnet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\NewNet\\newnet_26_31.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\NewNet\\";

char *caminhoVertices = "N�s - Lat Long\\Originais\\NewNet\\newnet_nodes.txt";
char *caminhoArestas = "N�s - Lat Long\\Originais\\NewNet\\newnet_links.txt";
char *caminhoSaida = "N�s - Lat Long\\Originais\\NewNet\\";


//NSFNET
//char *caminhoVertices = "N�s - Lat Long\\Harary\\NsfNet\\nsfnet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\NsfNet\\nsfnet_14_21.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\NsfNet\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\NsfNet\\nsfnet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\NsfNet\\nsfnet_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\NsfNet\\";


//ONMINICONEUROPE
//char *caminhoVertices = "N�s - Lat Long\\Harary\\OnminiconEurope\\OmnicomEurope_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\OnminiconEurope\\omnicom_38_54.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\OnminiconEurope\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\OnminiconEurope\\OmnicomEurope_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\OnminiconEurope\\OmnicomEurope_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\OnminiconEurope\\";


//PIONIER
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Pionier\\pionier_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Pionier\\pionier_21_25.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Pionier\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Pionier\\pionier_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Pionier\\pionier_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Pionier\\";


//PORTUGAL
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Portugal\\portugal_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Portugal\\portugal_26_36.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Portugal\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Portugal\\portugal_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Portugal\\portugal_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Portugal\\";


//RENATER
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Renater\\renater_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Renater\\renater_27_35.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Renater\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Renater\\renater_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Renater\\renater_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Renater\\";


//RNP
//char *caminhoVertices = "N�s - Lat Long\\Harary\\RnpBrasil\\rnpBrazil_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\RnpBrasil\\rnp_10_12.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\RnpBrasil\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\RnpBrasil\\rnpBrazil_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\RnpBrasil\\rnpBrazil_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\RnpBrasil\\";


//SANET
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Sanet\\sanet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Sanet\\sanet_25_28.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Sanet\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Sanet\\sanet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Sanet\\sanet_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Sanet\\";


//SPAIN
//char *caminhoVertices = "N�s - Lat Long\\Harary\\Spain\\spain_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\Spain\\redirisnet_17_28.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\Spain\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\Spain\\spain_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\Spain\\spain_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\Spain\\";

//USA
//char *caminhoVertices = "N�s - Lat Long\\Originais\\UsaGde\\usaGde_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\UsaGde\\usaGde_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\UsaGde\\";

//char *caminhoVertices = "N�s - Lat Long\\Harary\\UsaGde\\usaGde_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\UsaGde\\H_usa100.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\UsaGde\\";


//VBNS
//char *caminhoVertices = "N�s - Lat Long\\Harary\\VBns\\vbns_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\VBns\\vbns_12_17.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\VBns\\";

//char *caminhoVertices = "N�s - Lat Long\\Originais\\VBns\\vbns_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\VBns\\vbns_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\VBns\\"; 


//VIA
//char *caminhoVertices = "N�s - Lat Long\\Harary\\ViaDataCenterNet\\viaDatacenterNet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Harary\\ViaDataCenterNet\\viaDatacenterNet_9_12.txt";
//char *caminhoSaida = "N�s - Lat Long\\Harary\\ViaDataCenterNet\\";

//
//char *caminhoVertices = "N�s - Lat Long\\Originais\\ViaDataCenterNet\\viaDatacenterNet_nodes.txt";
//char *caminhoArestas = "N�s - Lat Long\\Originais\\ViaDataCenterNet\\viaDatacenterNet_links.txt";
//char *caminhoSaida = "N�s - Lat Long\\Originais\\ViaDataCenterNet\\";