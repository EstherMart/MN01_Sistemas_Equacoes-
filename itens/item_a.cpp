#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "../src/sistemas.hpp"  // Incluindo as funções auxiliares, como o cálculo do determinante e substituição retroativa

using namespace std;

// Adicional............
// Função para calcular os deslocamentos dos pêndulos usando a Regra de Cramer
vector<double> calcular_deslocamentos_cramer(vector<vector<double>>& C, vector<double>& v, int n) {
    
    // Cada deslocamento é cálculado da seguinte forma: di = detCi/detC
    // detC é o determinante da matriz dos coeficientes C
    // detCi é o determinante da matriz obtida trocando-se a coluna i da matriz C pelo vetor v dos termos independentes.

    vector<double> deslocamentos(n);

    // Calcular o determinante de C (detC)
    double detC = calcular_determinante(C);

    if (detC == 0) {
        cout << "Erro: A matriz C é singular (determinante = 0), não é possível calcular os deslocamentos." << endl;
        return {};
    }

    // Calcular os deslocamentos usando a Regra de Cramer: d_i = det(C_i) / det(C)
    for (int i = 0; i < n; i++) {

        // Criar a matriz C_i, trocando a i-ésima coluna de C pelo vetor v
        vector<vector<double>> C_i = C;

        for (int j = 0; j < n; j++) {
            C_i[j][i] = v[j];
        }

        // Calcular o determinante de C_i (det(C_i))
        double detCi = calcular_determinante(C_i);

        // Calcular o deslocamento d_i
        deslocamentos[i] = detCi / detC;
    }

    return deslocamentos;
}

// Função para calcular os deslocamentos dos pêndulos usando o método de Gauss normal
vector<double> calcular_deslocamentos(vector<vector<double>>& C, vector<double>& v, int n) {
    // Resolvendo o sistema linear usando Eliminação de Gauss
    vector<double> deslocamentos = eliminacao_gauss(C, v);
    return deslocamentos;
}


// Função para calcular as amplitudes a partir dos deslocamentos (a questão exige esse cálculo)
vector<double> calcular_amplitudes(vector<double>& deslocamentos, double a, int n) {

    vector<double> amplitudes(n);
    for (int i = 0; i < n; i++) {
        amplitudes[i] = a * deslocamentos[i];  // A amplitude é dada por a * d_i
    }

    return amplitudes;
}

int main() {
    // Leitura dos dados de entrada
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

    // Calcular os deslocamentos dos pêndulos usando o método de Gauss normal
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