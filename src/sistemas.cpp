# include "sistemas.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void print_matriz(vector<vector<double>>& m) {
	cout << "[" << endl;
	for (const auto& row : m) {
		cout << "    [";
		for (size_t i = 0; i < row.size(); ++i) {
			// Formatar a saída para ter 4 espaços de largura, alinhado à direita
			cout << setw(4) << row[i];
			if (i < row.size() - 1) cout << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void print_vetor(vector<double>& v) {
	cout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i < v.size() - 1) cout << " ";
	}
	cout << "]" << endl;
}

// Funcao para calcular a determinante das matrizes
// Função de arredondamento com precisão especificada para evitar números muito pequenos na saída do Gauss-Jordan
double arredondar(double valor, int casas_decimais = 3) {
    double fator = pow(10, casas_decimais);
    double resultado = round(valor * fator) / fator;

    // Se o valor arredondado for muito pequeno (perto de zero), definimos explicitamente como zero
    if (fabs(resultado) < pow(10, -casas_decimais)) {
        resultado = 0.0;
    }

    return resultado;
}

double calcular_determinante(vector<vector<double>>& A){

	int n = A.size();

	// Caso base: se a matriz for 2x2, realizamos um calculo mais intuitivo (simples)
	if (n == 2){
		return A[0][0]*A[1][1] - A[0][1]*A[1][0];
	}

	// Para um caso mais amplo, usaremos expansão de Laplace
	double determinante = 0;

	// Criação das submatrizes da matriz original
	for (int i = 0; i < n; i++){

		// Declarando a submatriz menor
		vector<vector<double>> menor(n - 1, vector<double>(n - 1));
		
		// Preenchendo a submatriz
		for (int j = 1; j < n; j++){

			int coluna = 0;
			for (int k = 0; k < n; k++){

				if (k != i){
					menor[j-1][coluna] = A[j][k];
					coluna++;
				}

			}

		}

		// Realizando o calculo do determinante de forma recursiva
		determinante += (i % 2 == 0 ? 1 : -1) * A[0][i] * calcular_determinante(menor);

	}

	return determinante;

}

vector<double> cramer(vector<vector<double>> A, vector<double> b){

	// Guardando o determinante da matriz A
	double determinante = calcular_determinante(A);
	double determinante_i;

	// Criando o vetor solucao
	vector<double> solucao;

	// Criando um vetor que vai ser usado para calcular as determinantes
	vector<vector<double>> matriz_deti = A;

	// Percorrendo as colunas e modificando a mesma
	int n = A.size();
	for (int i = 0; i < n; i++){

		for (int j = 0; j < n; j++){

			// Alterando a matriz para calcular a deti
			matriz_deti[j][i] = b[j];

		}

		// Calculando a determinante para aquela coluna
		determinante_i = calcular_determinante(matriz_deti);

		// Calculando o valor para xi
		solucao.push_back(determinante_i / determinante);

		// Retomando o valor original da matriz
		matriz_deti = A;

	}

	// Retornando o vetor com a solucao do sistema
	return solucao;

}



// Esta funcao gera o vetor solucao, dada a sua matriz na forma triangular superior.
// --> Método da substituição retroativa (Back Substitution) para resolver um sistema triangular superior
vector<double> substituicao_retroativa(vector<vector<double>> A, vector<double> b){

	// Criando a variavel x
	vector<double> x(A.size(), 0);

	// Calculo para obter o vetor solucao
	for (int i = A.size() - 1; i >= 0; i--){

		double S = 0;
		for (size_t j = i + 1; j < A.size(); j++){
			S += A[i][j] * x[j];
		}

		// O valor referente a Xi
		x[i] = (b[i] - S)/A[i][i];

	}

	return x;

}

// Criando o metodo da eliminacao de gauss, que vai transformar a matriz aumentada [A|b] em sua forma triangular superior
vector<double> eliminacao_gauss(vector<vector<double>> A, vector<double> b){

	for (size_t k = 0; k < A.size() - 1; k++){

		for (size_t i = k + 1; i < A.size(); i++){

			double m = -A[i][k]/A[k][k];
			for (size_t j = k + 1; j < A.size(); j++){
				A[i][j] = m * A[k][j] + A[i][j];
			}

			b[i] = m * b[k] + b[i];
			A[i][k] = 0;

		}

	}

	vector<double> x = cramer(A, b);
	// Extraindo a solução com precisão
    	for (int i = 0; i < x.size(); i++) {
        	x[i] = arredondar(x[i]);  // Arredondar a solução para evitar números muito pequenos
    	}
	return x;

}

// Método de Gauss-Jordan para resolver sistemas lineares. A ideia é construir a matriz aumentada [A | b], normalizando as linhas de fforma que a diagonal principal tenha 1s (Matriz identidade)
vector<double> eliminacao_gauss_jordan(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    
    // Criando a matriz aumentada [A | b]
    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }

    // Aplicando o método de Gauss-Jordan
    for (int i = 0; i < n; i++) {
        // Pivô: Normalizando a linha i de forma que tenhamos 1s
        double pivot = A[i][i];
        for (int j = 0; j <= n; j++) {
            A[i][j] /= pivot;
        }

        // Zerando os outros elementos da coluna i para gerar a matriz identidade
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j <= n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }

    // Extraindo a solução com precisão
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = arredondar(A[i][n]);  // Arredondar a solução para evitar números muito pequenos
    }

    return x;
}

// Implementando a funcao para calibrar o sistema
vector<double> calibracao(vector<double> solucao, double a){

  vector<double> solucao_calibrada;
  for (size_t i = 0; i < solucao.size(); i++){
    solucao_calibrada.push_back(solucao[i] * a);
  }

  return solucao_calibrada;

 }

 // Implementando a funcao para verificar se, com os pendulos calibrados, rompera
tuple<bool, double> verificacao_rompimento(vector<double> solucao, vector<double> solucao_calibrada, double limite){
  for (size_t i = 0; i < solucao_calibrada.size(); i++){
    if (solucao_calibrada[i] > limite){
      return make_tuple(true, solucao[i]); // true = possivelmente rompera com d = solucao[i]
    }
  }

  return make_tuple(false, -1);
}
