#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int maxSize = 10;
    char A[maxSize], B[maxSize];
    int sizeA, sizeB;

    cout << "Введите размерность множества A: ";
    cin >> sizeA;

    cout << "Вводи элементы A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
        if (isalpha(A[i])) {
            A[i] = tolower(A[i]);
        }
    }

    cout << "Введите размерность множества B: ";
    cin >> sizeB;

    cout << "Вводи элементы B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
        if (isalpha(B[i])) {
            B[i] = tolower(B[i]);
        }
    }

    cout << "\nA = { ";
    for (int i = 0; i < sizeA; i++)
        cout << A[i] << " ";
    cout << "}";

    cout << "\nB = { ";
    for (int i = 0; i < sizeB; i++)
        cout << B[i] << " ";
    cout << "}\n";

    cout << "\nОбъединение A и B = { ";
    for (int i = 0; i < sizeA; i++)
        cout << A[i] << " ";

    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << B[i] << " ";
    }
    cout << "}";

    cout << "\nПересечение A и B = { ";
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                cout << A[i] << " ";
                break;
            }
        }
    }
    cout << "}";

    cout << "\nДополнение A / B = { ";
    for (int i = 0; i < sizeA; i++) {
        bool found = false;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << A[i] << " ";
    }
    cout << "}";

    cout << "\nДополнение B / A = { ";
    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << B[i] << " ";
    }
    cout << "}";

    cout << "\nСимметрическая разность = { ";
    for (int i = 0; i < sizeA; i++) {
        bool found = false;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << A[i] << " ";
    }
    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << B[i] << " ";
    }
    cout << "}\n";

}