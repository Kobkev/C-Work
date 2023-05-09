#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long memoria[100 + 1];

long long fibonacci(long long n) {
	if (memoria[n] <= 1) {
		if (n == 0 || n == 1)
			memoria[n] = n;
		else
			memoria[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return memoria[n];
}

int main() {
	int n = { 0 };
	cin >> n;

	for (int i = 1; i <= n; i++)
		memoria[i] = -1;

	auto start = high_resolution_clock::now();
	cout << fibonacci(n);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\n" << "Tiempo transcurrido: " << duration.count() << " microsegundos" << "\n";
}