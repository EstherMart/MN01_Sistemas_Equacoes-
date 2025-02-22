# include <iostream>
# include <vector>
# include <cmath>
# include <tuple>
#include <clocale>
#include <iomanip>  // Para definir a largura das colunas
# include "sistemas.hpp"

using namespace std;

int main(){

  // Gerando a matriz das incognitas
  std::vector<vector<double>> A = {
    {10, 2, 2},
    {1, 10, 2},
    {2, -7, -10}
  };

  // Gerando o vetor solucao das equacoes
  std::vector<double> b = {
    28, 7, -17
  };

  // Tres solucoes diferentes
  std::vector<double> solucao_gauss = eliminacao_gauss(A, b); // Por eliminacao de gauss
  std::vector<double> solucao_gauss_jordan = eliminacao_gauss_jordan(A, b); // Pelo metodo de gauss-jordan
  std::vector<double> solucao_cramer = cramer(A, b); // Por regra de cramer

  // Printando as tres solucoes iniciais
  cout << "Soluções do sistema (Eliminação de Gauss): ";
  for (double xi : solucao_gauss) {
    cout << xi << " ";
  }
  cout << endl;

  cout << "Soluções do sistema (Gauss-Jordan): ";
  for (double xi : solucao_gauss_jordan) {
    cout << fixed << setprecision(3) << xi << " ";
  }
  cout << endl;

  cout << "Soluções do sistema (Cramer): ";
  for (double xi : solucao_cramer) {
    cout << fixed << setprecision(3) << xi << " ";
  }
  cout << endl;

  // Calibrando
  vector<double> solucao_calibrada = calibracao(solucao_cramer, 2);
  cout << "Soluções do sistema calibrada: ";
  for (double xi : solucao_calibrada) {
    cout << fixed << setprecision(3) << xi << " ";
  }
  cout << endl;

  // Verificando se rompera
  tuple<bool, double> rompera = verificacao_rompimento(solucao_cramer, solucao_calibrada, 3);

  if (std::get<0>(rompera) == true){
    cout << "Possivelmente rompera, devido ao deslocamento " << std::get<1>(rompera) << endl;
  }

  else{
    cout << "Possivelmente NAO rompera, estamos seguros :)" << endl;
  }

  return 0;
}