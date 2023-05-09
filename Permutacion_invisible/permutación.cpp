#include <algorithm> 
#include <iostream> 

int n;
int arr[20];

void genera(int i) {
    if (i == n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        for (int j = i; j < n; ++j) {
            std::swap(arr[i], arr[j]);
            if (i == 0 || (arr[i - 1] + arr[i]) % (i + 1) == 0) {
                genera(i + 1);
            }
            std::swap(arr[i], arr[j]);
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    genera(0);
}