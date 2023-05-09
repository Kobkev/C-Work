#include <iostream>
using namespace std;

int espacio{ 0 };
int k{ 0 };

void Estrellita3(int n) {
	for (int i = n; 0 < i; i--) {
		int k{ 0 };

		for(k; k < espacio; k++){
			cout << " ";
		}

		for (int j = 0; j < i; j++) {
			cout << "*";
		}

		espacio++;
		cout << "\n";
	}
}

int main() {
	int n{ 0 };

	cin >> n;

	Estrellita3(n);
}