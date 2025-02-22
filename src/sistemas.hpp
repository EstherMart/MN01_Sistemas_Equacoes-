# include <cmath>
# include <tuple>
# include <vector>
# include <functional>

using namespace std;
// Declarando as funcoes

 // Funcao para calcular a determinante de uma matriz
double calcular_determinante(vector<vector<double>>& A);

// Funcao para calcular a solucao de um sistema por meio da regra de Cramer
vector<double> cramer(vector<vector<double>> A, vector<double> b);

/* Funcao para resolver o sistema de uma matriz triangular superior
Obs.: Estou usando ela por enquanto porque ainda nao tenho a resolucao por regra de cramer */
// Cada deslocamento é cálculado da seguinte forma: di = detCi/detC
// detC é o determinante da matriz dos coeficientes C
// detCi é o determinante da matriz obtida trocando-se a coluna i da matriz C pelo vetor v dos termos independentes.
vector<double> substituicao_retroativa(vector<vector<double>> A, vector<double> b);

// Eliminacao de gauss com substituicao retroativa
vector<double> eliminacao_gauss(vector<vector<double>> A, vector<double> b);

// Eliminação usando o Método de Gauss-Jordan 
vector<double> eliminacao_gauss_jordan(vector<vector<double>> A, vector<double> b);

// Funcao para realizar o calculo de amplitude e verificacao
vector<double> calibracao(vector<double> solucao, double a);
tuple<bool, double> verificacao_rompimento(vector<double> solucao, vector<double> solucao_calibrada, double limite);
