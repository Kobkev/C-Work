#include <algorithm> 
#include <iostream> 

int n;
int arr[10];

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
            genera(i + 1);
            std::swap(arr[i], arr[j]);
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    genera(0);
}