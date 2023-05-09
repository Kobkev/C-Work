#include <cstdlib> 
#include <iostream> 

int n;
int arr[25];
int res = 0;
int generadas = 0;

void genera(int i) {
    if (i == n) {
        generadas += 1;
        if (arr[0] == arr[n - 1]) {
            res += 1;
        }
    }
    else if (i == 0) {
        for (int d = 0; d <= 9; ++d) {
            arr[i] = d;
            genera(i + 1);
        }
    }
    else {
        int anterior = arr[i - 1];
        if (anterior != 0) {
            arr[i] = anterior - 1;
            genera(i + 1);
        }
        if (anterior != 9) {
            arr[i] = anterior + 1;
            genera(i + 1);
        }

    }
}

int main() {
    std::cin >> n;
    genera(0);
    std::cout << res << "\n";
    std::cout << generadas << "\n";
}