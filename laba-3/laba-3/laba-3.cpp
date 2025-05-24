#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    int matrica[10][10];
    cout << "Введите n и m: ";
    cin >> n >> m;

    cout << "Введите матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrica[i][j];
        }
    }

    bool funkcia = true;
    for (int i = 0; i < n; i++) {
        int chislo = 0;
        for (int j = 0; j < m; j++) {
            if (matrica[i][j] == 1) chislo++;
        }
        if (chislo != 1) {
            funkcia = false;
            break;
        }
    }

    if (funkcia) {
        cout << "Это функция\n";
    }
    else {
        cout << "Это НЕ функция\n";
    }

    return 0;
}