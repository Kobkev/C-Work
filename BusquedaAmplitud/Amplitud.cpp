// https://omegaup.com/arena/problem/Divulgando-las-noticias#problems 

#include <algorithm> 
#include <iostream> 
#include <vector> 

int main() {
    int n;
    std::cin >> n;

    std::vector<int> adyacencia[n];
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int a;
            std::cin >> a;
            adyacencia[i].push_back(a);
        }
    }

    int k;
    std::cin >> k;

    bool visitados[n] = { };
    visitados[k] = true;
    std::vector<int> actual = { k };
    int res = 0;

    do {
        std::vector<int> siguiente;
        for (int vertice : actual) {
            for (int amigo : adyacencia[vertice]) {
                if (!visitados[amigo]) {
                    visitados[amigo] = true;
                    siguiente.push_back(amigo);
                }
            }
        }
        res = std::max(res, int(siguiente.size()));
        actual = siguiente;
    } while (!actual.empty());

    std::cout << res << "\n";
}