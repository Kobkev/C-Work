#include <iostream> 

int n;
int arr[10];

void genera(int i) {
    if (i == n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i];
        }
        std::cout << "\n";
    }
    else {
        arr[i] = 0;
        genera(i + 1);
        arr[i] = 1;
        genera(i + 1);
    }
}

int main() {
    std::cin >> n;
    genera(0);
}