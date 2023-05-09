#include <iostream>
using namespace std;

void Estrellita4(int n) {
    for (int i = n; 0 < i; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    int n;

    cin >> n;

    Estrellita4(n);
}