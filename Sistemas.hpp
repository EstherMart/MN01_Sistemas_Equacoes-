# include <cmath>
# include <tuple>
# include <vector>
# include <functional>

using namespace std;
// Declarando as funcoes

 // Funcao para calcular a determinante de uma matriz
double calcular_determinante(vector<vector<double>>& A);

/* Funcao para resolver o sistema de uma matriz triangular superior
Obs.: Estou usando ela por enquanto porque ainda nao tenho a resolucao por regra de cramer */
vector<double> substituicao_retroativa(vector<vector<double>> A, vector<double> b);

// Eliminacao de gauss com substituicao retroativa
vector<double> eliminacao_gauss(vector<vector<double>> A, vector<double> b);
