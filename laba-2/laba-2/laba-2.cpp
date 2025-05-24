#include <iostream>
#include <string>
#include <sstream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");
    int elementi[10], schetElementov = 0;
    cout << "Введите элементы множества через пробел: ";

    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> elementi[schetElementov]) {
        schetElementov++;
        if (schetElementov >= 10) break;
    }

    int para[10][2], schetPar = 0;
    cout << "Введите пары по одной на строку:\n";

    while (true) {
        getline(cin, line);
        if (line.empty()) break;

        stringstream pariStrok(line);
        if (pariStrok >> para[schetPar][0] >> para[schetPar][1]) {
            schetPar++;
            if (schetPar >= 100) break;
        }
    }

    bool refleksia = true;
    bool symmetria = true;
    bool antisymmeria = true;
    bool tranzitivnost = true;

    for (int i = 0; i < schetElementov; i++) {
        bool found = false;
        for (int j = 0; j < schetPar; j++) {
            if (para[j][0] == elementi[i] && para[j][1] == elementi[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            refleksia = false;
            break;
        }
    }

    for (int i = 0; i < schetPar; i++) {
        bool found = false;
        for (int j = 0; j < schetPar; j++) {
            if (para[i][0] == para[j][1] && para[i][1] == para[j][0]) {
                found = true;
                break;
            }
        }
        if (!found) {
            symmetria = false;
            break;
        }
    }

    for (int i = 0; i < schetPar; i++) {
        if (para[i][0] != para[i][1]) {
            for (int j = 0; j < schetPar; j++) {
                if (para[i][0] == para[j][1] && para[i][1] == para[j][0]) {
                    antisymmeria = false;
                    break;
                }
            }
        }
        if (!antisymmeria) break;
    }

    for (int i = 0; i < schetPar; i++) {
        for (int j = 0; j < schetPar; j++) {
            if (para[i][1] == para[j][0]) {
                bool found = false;
                for (int k = 0; k < schetPar; k++) {
                    if (para[k][0] == para[i][0] && para[k][1] == para[j][1]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    tranzitivnost = false;
                    break;
                }
            }
        }
        if (!tranzitivnost) break;
    }

    cout << "\nРезультаты анализа:\n";
    cout << "1. Рефлексивность: " << (refleksia ? "Да" : "Нет") << endl;
    cout << "2. Симметричность: " << (symmetria ? "Да" : "Нет") << endl;
    cout << "3. Антисимметричность: " << (antisymmeria ? "Да" : "Нет") << endl;
    cout << "4. Транзитивность: " << (tranzitivnost ? "Да" : "Нет") << endl;

    return 0;
}