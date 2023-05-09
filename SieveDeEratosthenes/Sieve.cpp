#include <iostream>
#include <string.h>
using namespace std;

int cont = {0};

void SieveDeEratosthenes(int n)
{
    bool primo[n + 1];
    memset(primo, true, sizeof(primo));

    for (int p = 2; p * p <= n; p++)
    {
        if (primo[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                primo[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (primo[p])
        {
            cout << p << " ";
            cont++;
        }
}

int main()
{
    int n = {0};
    cin >> n;

    cout << "Los siguientes numeros primos son menores a " << n << "son:";
    SieveDeEratosthenes(n);
    return 0;
}