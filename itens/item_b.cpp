#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "../src/sistemas.hpp"

using namespace std;

// Função para calcular os deslocamentos (d) usando o método de Gauss-Jordan já implementado por nós em src/sistemas.cpp
vector<double> calcular_deslocamentos(vector<vector<double>>& C, vector<double>& v, int n) {
    return eliminacao_gauss_jordan(C, v);  // importando do cabeçalho
}

// Função para calcular as amplitudes dos pêndulos
vector<double> calcular_amplitudes(const vector<double>& deslocamentos, double a, int n) {
    vector<double> amplitudes(n);
    for (int i = 0; i < n; i++) {
        // A fórmula para a amplitude pode ser ajustada conforme necessário (igual do item anterior)
        amplitudes[i] = deslocamentos[i] * a;  // A amplitude é proporcional ao deslocamento
    }
    return amplitudes;
}

int main() {
    int n;
    double a;

    cout << "Insira o número de pêndulos (n): ";
    cin >> n;
    cout << "Insira o parâmetro a: ";
    cin >> a;

    // Definir a matriz [C] e o vetor [v] com os dados fixos fornecidos pela questão
    vector<vector<double>> C = {
        {10, 1, 1},  
        {1, 10, 1},  
        {1, 1, 10}   
    };
    vector<double> v = {12, 12, 12};

    // Verificar se o número de pêndulos (n) corresponde ao tamanho da matriz e vetor
    if (n != 3) {
        cout << "Erro: Para esta implementação, n deve ser igual a 3." << endl;
        return 1;
    }

    // Calcular os deslocamentos dos pêndulos usando o método de Gauss-Jordan
    vector<double> deslocamentos = calcular_deslocamentos(C, v, n);

    // Calcular as amplitudes dos pêndulos
    vector<double> amplitudes = calcular_amplitudes(deslocamentos, a, n);

    // Exibir os resultados
    cout << "\nDeslocamentos (d):\n";
    for (int i = 0; i < n; i++) {
        cout << "d" << i + 1 << " = " << fixed << setprecision(6) << deslocamentos[i] << " cm\n";
    }

    cout << "\nAmplitudes dos pêndulos:\n";
    for (int i = 0; i < n; i++) {
        cout << "Amplitude " << i + 1 << " = " << fixed << setprecision(6) << amplitudes[i] << " cm\n";
    }

    // Verificar se algum pêndulo rompeu (amplitude > 3 cm)
    cout << "\nVerificando se algum pêndulo rompeu...\n";
    for (int i = 0; i < n; i++) {
        if (amplitudes[i] > 3.0) {
            cout << "O pêndulo " << i + 1 << " rompeu! (Amplitude > 3 cm)\n";
        }
    }

    return 0;
}
