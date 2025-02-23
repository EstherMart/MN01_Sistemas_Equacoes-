# include <cmath>
# include <tuple>
# include <vector>

using namespace std;
// Declarando as funcoes

// pretty print matriz
void print_matriz(vector<vector<double>>& m);

// pretty print vetor
void print_vetor(vector<double>& v);

 // Funcao para calcular a determinante de uma matriz
double calcular_determinante(vector<vector<double>>& A);

// Funcao para calcular a solucao de um sistema por meio da regra de Cramer
vector<double> cramer(vector<vector<double>> A, vector<double> b);

// Eliminacao de gauss com substituicao retroativa
vector<double> eliminacao_gauss(vector<vector<double>> A, vector<double> b);

// Eliminação usando o Método de Gauss-Jordan 
vector<double> eliminacao_gauss_jordan(vector<vector<double>> A, vector<double> b);

// Funcao para realizar o calculo de amplitude e verificacao
vector<double> calibracao(vector<double> solucao, double a);
tuple<bool, double> verificacao_rompimento(vector<double> solucao, vector<double> solucao_calibrada, double limite);
