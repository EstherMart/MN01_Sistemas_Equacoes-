# include "sistemas.hpp"
#include <iostream>
#include <iomanip>  // Para arredondamento e formatação
#include <cmath>
#include <vector>

using namespace std;

// Funcao para calcular a determinante das matrizes
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


// Esta funcao gera o vetor solucao, dada a sua matriz na forma triangular superior.
// --> Método da substituição retroativa (Back Substitution) para resolver um sistema triangular superior
vector<double> substituicao_retroativa(vector<vector<double>> A, vector<double> b){

	// Criando a variavel x
	vector<double> x(A.size(), 0);

	// Calculo para obter o vetor solucao
	for (int i = A.size() - 1; i >= 0; i--){

		double S = 0;
		for (int j = i + 1; j < A.size(); j++){
			S += A[i][j] * x[j];
		}

		// O valor referente a Xi
		x[i] = (b[i] - S)/A[i][i];

	}

	return x;

}

// Criando o metodo da eliminacao de gauss, que vai transformar a matriz aumentada [A|b] em sua forma triangular superior
vector<double> eliminacao_gauss(vector<vector<double>> A, vector<double> b){

	for (int k = 0; k < A.size() - 1; k++){

		for (int i = k + 1; i < A.size(); i++){

			double m = -A[i][k]/A[k][k];
			for (int j = k + 1; j < A.size(); j++){
				A[i][j] = m * A[k][j] + A[i][j];
			}

			b[i] = m * b[k] + b[i];
			A[i][k] = 0;

		}

	}

	vector<double> x = substituicao_retroativa(A, b);
	return x;

}

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