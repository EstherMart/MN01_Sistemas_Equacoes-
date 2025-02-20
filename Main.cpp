# include <iostream>
# include <vector>
# include <cmath>
# include <tuple>
# include <functional>
# include "Sistemas.hpp"

using namespace std;

int main(){

	vector<vector<double>> A = {
		{20, 7, 9},
		{7, 30, 8},
		{9, 8, 30}
	};

	vector<double> b = {16, 38, 38};
	vector<double> x = eliminacao_gauss(A, b);
	for (double xi : x) {
    cout << xi << " ";
}
cout << endl;

cout << "DETERMINANTE: " << calcular_determinante(A) << endl; 

	return 0;
}