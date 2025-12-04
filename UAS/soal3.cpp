#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    char tujuan;
    int jarak;
};

struct Node {
    char nama;
    vector<Edge> edges;
};

void BFS(char start, char end, Node graf[], int size) {
    queue<vector<char>> q;
    q.push({start});

    bool visited[26] = {false};
    visited[start - 'A'] = true;

    while (!q.empty()) {
        vector<char> path = q.front();
        q.pop();
        char last = path.back();

        if (last == end) {
            cout << "JALUR TERCEPAT:\n";
            int totalJarak = 0;

            for (int i = 0; i < path.size(); i++) {
                if (path[i] == 'Medan ') cout << "Tebing Tinggi \n";
                else if (path[i] == 'Medan ') cout << "Berastagi\n";
                else if (path[i] == 'Tebing Tinggi') cout << "Pematangsiantar\n";
                else if (path[i] == 'Brastagi') cout << "Sidikalang\n";
                else if (path[i] == 'Brastagi') cout << "Pematangsiantar\n";
                else if (path[i] == 'Pematangsiantar') cout << "Parapat\n";
                else if (path[i] == 'Sidikalang') cout << "Parapat\n";

                if (i < path.size() - 1) {
                    char from = path[i];
                    char to = path[i + 1];

                    for (int j = 0; j < size; j++) {
                        if (graf[j].nama == from) {
                            for (auto e : graf[j].edges) {
                                if (e.tujuan == to) {
                                    cout << e.jarak << "m\n";
                                    totalJarak += e.jarak;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            cout << "\nJalur terpendek: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << "\nTotal langkah: " << path.size() - 1 << " edge";
            cout << "\nTotal jarak: " << totalJarak << " meter\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            if (graf[i].nama == last) {
                for (auto e : graf[i].edges) {
                    if (!visited[e.tujuan - 'A']) {
                        visited[e.tujuan - 'A'] = true;
                        vector<char> newPath = path;
                        newPath.push_back(e.tujuan);
                        q.push(newPath);
                    }
                }
            }
        }
    }
}

int main() {
    Node graf[4];

    graf[0].nama = 'A';
    graf[0].edges = {{'C', 2}, {'B', 4}};

    graf[1].nama = 'B';
    graf[1].edges = {{'D', 5}};

    graf[2].nama = 'C';
    graf[2].edges = {{'D', 1}};

    graf[3].nama = 'D';
    graf[3].edges = {{'E', 3}};

    tampilDFS();
    BFS('A', 'E', graf, 4);
    return 0;
}