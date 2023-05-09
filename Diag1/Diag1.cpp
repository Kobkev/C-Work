#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float Xa{ 0 }, Ya{ 0 }, Xb{ 0 }, Yb{ 0 }; //Son tomados como cm
	
	//cout << "Introduce las coordenadas (Xa, Ya) y luego (Xb, Yb), sean ambos en cm: ";
	cin >> Xa >> Ya >> Xb >> Yb;

	float distancia = sqrt(((Xb - Xa) * (Xb - Xa)) + ((Yb - Ya) * (Yb - Ya)));

	//cout << "La distancia total es: "<< distancia << endl; Unidades obtenidas

	if (distancia < 150) {
		cout << "insana" << endl;
	}
	else{
		cout << "sana" << endl;
	}

	return 0;
}