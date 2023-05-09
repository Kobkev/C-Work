#include <iostream>
using namespace std;

static void Estrellita5(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		for (int k = i; k <= n; k++) {
			cout << "* ";
		}
		cout << "\n";
	}

	n -= 1;

	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; ++j) {
			cout << " ";
		}
		for (int k = 1; k <= i; ++k) {
			cout << " *";
		}
		cout << "\n";
	}
}

int main() {
	int n;

	cin >> n;

	Estrellita5(n);
}
