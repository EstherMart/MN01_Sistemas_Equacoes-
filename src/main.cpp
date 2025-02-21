# include <iostream>
# include <vector>
# include <cmath>
# include <tuple>
# include <functional>
#include <clocale>
#include <iomanip>  // Para definir a largura das colunas
# include "sistemas.hpp"

using namespace std;

int main(){
	// Definir o local para UTF-8
	setlocale(LC_ALL, "pt_BR.UTF-8");

    int escolha;
    cout << "Escolha a opção:\n";
    cout << "1 - Usar matriz matriz padronizada\n";
    cout << "2 - Inserir matriz e vetor\n";
    cout << "Opção: ";
    cin >> escolha;

    vector<vector<double>> A;
    vector<double> b;

    if (escolha == 1) {
        
		// Matriz e vetor padrão (por enquanto é teste, pois é a matriz utilizada na lista da AP2)
		A = {
            {20, 7, 9},
            {7, 30, 8},
            {9, 8, 30}
        };
        b = {16, 38, 38};

    } else if (escolha == 2) {

        // Inserir matriz e vetor personalizados de acordo com os seguintes dados setados pelo usuário:
        int n;
        cout << "Insira o tamanho da matriz quadrada (n x n): ";
        cin >> n;

        A.resize(n, vector<double>(n));
        b.resize(n);

        cout << "Insira os elementos da matriz A linha por linha:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }

        cout << "Insira os elementos do vetor {b}:\n";
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
   
	} else {

        cout << "Error: Opção inválida. Encerrando o programa......\n";
        return 1;

    }

	// Exibir a matriz A com formatação bonitinha
	cout << "\nMatriz A: [" << endl;
	for (const auto& row : A) {
		cout << "    [";
		for (size_t i = 0; i < row.size(); ++i) {
			// Formatar a saída para ter 4 espaços de largura, alinhado à direita
			cout << setw(4) << row[i];
			if (i < row.size() - 1) cout << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	// Exibir o vetor b com formatação bonitinha
	cout << "Vetor b: [";
	for (size_t i = 0; i < b.size(); ++i) {
		cout << b[i];
		if (i < b.size() - 1) cout << " ";
	}
	cout << "]" << endl;

	cout << endl;

    // Realizando o cálculo do determinante 
    double detA = calcular_determinante(A);
    cout << "Determinante de A: " << detA << endl;

    if (detA == 0) {
        cout << "O sistema não pode ser resolvido pois a matriz é singular (det = 0)." << endl;
        return 1;
    }

    // Resolvendo o sistema usando Eliminação de Gauss --> Triangular superior
    vector<double> x_gauss = eliminacao_gauss(A, b);
    cout << "Soluções do sistema (Eliminação de Gauss): ";
    for (double xi : x_gauss) {
        cout << xi << " ";
    }
    cout << endl;

	// Resolvendo o sistema usando Gauss-Jordan --> Matriz Identidade
    vector<double> x_gauss_jordan = eliminacao_gauss_jordan(A, b);
     // Exibindo os resultados
	cout << "Soluções do sistema (Gauss-Jordan): ";
	for (double xi : x_gauss_jordan) {
		cout << fixed << setprecision(3) << xi << " "; 
	 }
	cout << endl;

    return 0;
}