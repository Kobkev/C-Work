#include <algorithm> 
#include <iostream> 

int n;
int arr[12];
int res = 0;

void genera(int i) {
    if (i == n) {
        res += 1;
    }
    else {
        for (int j = i; j < n; ++j) {
            std::swap(arr[i], arr[j]);
            if (i == 0 || std::abs(arr[i] - arr[i - 1]) != 1) {
                genera(i + 1);
            }
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
    std::cout << res << "\n";
}