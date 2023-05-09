#include <iostream>
using namespace std;

int main() {
	int N{ 0 }, Dist[10] = { 0 }, P{ 0 }, Cont{ 0 };

	cin >> N; //Numero de personas en la fila

	for (int i = 0; i < N-1; i++) { //Agarra valores de Distancia
		cin >> Dist[i];
	}
	

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++){
			if (Dist[i] + P < 150)
				Cont += 1;

		}

	}

	//cout << Dist[0] << "\n" << Dist[1];

	return 0;
}