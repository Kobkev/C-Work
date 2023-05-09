#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


long long fibonacciVariable(long long n) {
	long long a = { 0 }, b{ 1 }, c{ 0 };


	for (int i = 2; i <= n; i++) {
		c = b;
		b = a + b;
		a = c;
	}
	return b;
}

int main() {
	int n = { 0 };
	cin >> n;

	auto start = high_resolution_clock::now();
	cout << fibonacciVariable(n);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\n" << "Tiempo transcurrido: " << duration.count() << " microsegundos" << "\n";
}