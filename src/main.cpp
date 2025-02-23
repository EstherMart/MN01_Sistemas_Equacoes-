# include <iostream>
# include <vector>
# include <cmath>
#include <clocale>
#include <iomanip>  // Para definir a largura das colunas
# include "sistemas.hpp"

using namespace std;

int main(){
	// Definir o local para UTF-8
	setlocale(LC_ALL, "pt_BR.UTF-8");

    int escolha;
    cout << "Escolha a opção:\n";
    cout << "1 - Usar matriz padronizada\n";
    cout << "2 - Inserir matriz e vetor\n";
    cout << "Opção: ";
    cin >> escolha;

    vector<vector<double>> matriz_A;
    vector<double> vetor_b;

    if (escolha == 1) {
        
		// Matriz e vetor padrão (por enquanto é teste, pois é a matriz utilizada na lista da AP2)
		matriz_A = {
            {20, 7, 9},
            {7, 30, 8},
            {9, 8, 30}
        };
        vetor_b = {16, 38, 38};

    } else if (escolha == 2) {

        // Inserir matriz e vetor personalizados de acordo com os seguintes dados setados pelo usuário:
        int n;
        cout << "Insira o tamanho da matriz quadrada (n x n): ";
        cin >> n;

        matriz_A.resize(n, vector<double>(n));
        vetor_b.resize(n);

        cout << "Insira os elementos da matriz A linha por linha:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz_A[i][j];
            }
        }

        cout << "Insira os elementos do vetor {b}:\n";
        for (int i = 0; i < n; i++) {
            cin >> vetor_b[i];
        }
   
	} else {

        cout << "Error: Opção inválida. Encerrando o programa......\n";
        return 1;

    }

	// Exibir a matriz A com formatação bonitinha
    cout << "\n====input====" << endl;
	cout << "Matriz A: ";
	print_matriz(matriz_A);

	// Exibir o vetor b com formatação bonitinha
	cout << "Vetor b: ";
    print_vetor(vetor_b);
    cout << "=============" << endl;

    cout << endl;

    // Realizando o cálculo do determinante 
    double detA = calcular_determinante(matriz_A);
    cout << "Determinante de A: " << detA << endl;

    if (detA == 0) {
        cout << "O sistema não pode ser resolvido pois a matriz é singular (det = 0)." << endl;
        return 1;
    }

    // Resolvendo o sistema usando Eliminação de Gauss --> Triangular superior
    vector<double> x_gauss = eliminacao_gauss(matriz_A, vetor_b);
    cout << "Soluções do sistema (Eliminação de Gauss): ";
    for (double xi : x_gauss) {
        cout << fixed << setprecision(10) << xi << " ";
    }
    cout << endl;

	// Resolvendo o sistema usando Gauss-Jordan --> Matriz Identidade
    vector<double> x_gauss_jordan = eliminacao_gauss_jordan(matriz_A, vetor_b);
     // Exibindo os resultados
	cout << "Soluções do sistema (Gauss-Jordan): ";
	for (double xi : x_gauss_jordan) {
		cout << fixed << setprecision(10) << xi << " "; 
	 }
	cout << endl;

    return 0;
}