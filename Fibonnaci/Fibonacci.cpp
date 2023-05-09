#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


int fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n = { 0 };
	cin >> n;
	auto start = high_resolution_clock::now();
	cout << fibonacci(n);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\n" << "Tiempo transcurrido: " << duration.count() << " microsegundos" << "\n";
}