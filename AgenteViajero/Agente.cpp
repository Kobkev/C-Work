#include <algorithm> 
#include <climits> 
#include <iostream> 

int n;
int arr[15];
int costos[15][15];
int res_global = INT_MAX;  // la mejor completa 
int res_local = 0;  // lo que llevo de la actual 

void genera(int i) {
    if (i == n) {
        res_global = res_local;
    }
    else {
        for (int j = i; j < n; ++j) {
            std::swap(arr[i], arr[j]);
            res_local += (i == 0 ? 0 : costos[arr[i - 1]][arr[i]]);
            if (res_local < res_global) {
                genera(i + 1);
            }
            res_local -= (i == 0 ? 0 : costos[arr[i - 1]][arr[i]]);
            std::swap(arr[i], arr[j]);
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> costos[i][j];
        }
    }

    genera(0);
    std::cout << res_global << "\n";
}