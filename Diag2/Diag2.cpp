#include <iostream>
using namespace std;


int main() {
	unsigned int M{ 0 }, N{ 0 }, Cont{ 0 }, num{ 0 };

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		Cont = Cont + num;
		if (Cont <= M)
			cout << "pasa\n";
		else {
			Cont = Cont - num;
			cout << "espera\n";
		}
	}

	return 0;
}