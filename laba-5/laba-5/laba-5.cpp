#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 10;
    int graph[MAX_SIZE][MAX_SIZE];
    int dostijimost[MAX_SIZE][MAX_SIZE];
    int vershina;

    do {
        cout << "Введите количество вершин (1-" << MAX_SIZE << "): ";
        cin >> vershina;
    } while (vershina < 1 || vershina > MAX_SIZE);

    cout << "Введите матрицу смежности (" << vershina << "x" << vershina << "):\n";
    cout << "(0 - нет ребра, 1 - есть ребро)\n";
    for (int i = 0; i < vershina; i++) {
        for (int j = 0; j < vershina; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < vershina; i++) {
        for (int j = 0; j < vershina; j++) {
            dostijimost[i][j] = (graph[i][j] > 0 || i == j) ? 1 : 0;
        }
    }
   
    for (int k = 0; k < vershina; k++) {
        for (int i = 0; i < vershina; i++) {
            for (int j = 0; j < vershina; j++) {
                if (dostijimost[i][k] && dostijimost[k][j]) {
                    dostijimost[i][j] = 1;
                }
            }
        }
    }

    cout << "\nМатрица достижимости:\n";
    for (int i = 0; i < vershina; i++) {
        for (int j = 0; j < vershina; j++) {
            cout << dostijimost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}