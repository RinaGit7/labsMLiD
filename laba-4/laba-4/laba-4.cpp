#include <iostream>
#include <climits>
#include <locale.h>

using namespace std;

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    int vershina, start, end;
    int maxInt = 100;

    cout << "Количество вершин: ";
    cin >> vershina;

    int graph[10][10];

    cout << "Матрица смежности (" << vershina << "x" << vershina << "):\n";
    for (int i = 0; i < vershina; i++) {
        for (int j = 0; j < vershina; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Стартовая вершина (0-" << vershina - 1 << "): ";
    cin >> start;
    cout << "Конечная вершина (0-" << vershina - 1 << "): ";
    cin >> end;

    int dist[10];
    bool visited[10];
    int path[10];

    for (int i = 0; i < vershina; i++) {
        dist[i] = maxInt;
        visited[i] = false;
        path[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < vershina - 1; count++) {
        int min_dist = maxInt, u;
        for (int n = 0; n < vershina; n++) {
            if (!visited[n] && dist[n] < min_dist) {
                min_dist = dist[n];
                u = n;
            }
        }

        if (min_dist == maxInt) break;
        visited[u] = true;

        for (int n = 0; n < vershina; n++) {
            if (!visited[n] && graph[u][n] && dist[u] != maxInt
                && dist[u] + graph[u][n] < dist[n]) {
                dist[n] = dist[u] + graph[u][n];
                path[n] = u;
            }
        }
    }

    if (dist[end] == maxInt) {
        cout << "Пути нет\n";
    }
    else {
        cout << "Кратчайший путь: ";

        int p[10], len = 0;
        for (int n = end; n != -1; n = path[n]) {
            p[len++] = n;
        }

        for (int i = len - 1; i >= 0; i--) {
            cout << p[i];
            if (i != 0) cout << "->";
        }

        cout << "\nДлина пути: " << dist[end] << endl;
    }

    return 0;
}