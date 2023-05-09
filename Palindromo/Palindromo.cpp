#include <iostream>
using namespace std;


int generarP(int N) {
	if (N == 0 || N == 2) {
		return 1;
	}
	else if (N == 1) {
		return 2;
	}
	else if((N % 2 == 0) && (N > 2)){
		return generarP(N - 4) + generarP(N - 2);
	}
	else {
		return generarP(N - 2) + generarP(N - 1);
	}
}

int main() {
	int N;
	cin >> N;

	//if (N >= 0 && N <= 75) {
		cout << generarP(N);
	//}

}