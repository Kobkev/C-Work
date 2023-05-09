#include <iostream>
using namespace std;

int espacio{ 0 };

void Estrellitas3(int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < espacio; k++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
		espacio--;
	}

}

int main() {
	int n{ 0 };

	cin >> n;

	espacio = n-1;

	Estrellitas3(n);
}