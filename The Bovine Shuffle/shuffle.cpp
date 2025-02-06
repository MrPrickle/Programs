#include <bits/stdc++.h>

using namespace std;


ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

int main () {
    int n;
    fin >> n;

    vector <int> order(n);
    for (int i = 0; i < n; i++) {
        int temp;
        fin >> temp;
        order[i] = temp - 1;
    }
    vector <int> line(n);
    for (int i = 0; i < n; i++) {
        fin >> line[i];
    }

    for (int i = 1; i <= 3; i++) {
        vector <int> copy = line;
        for (int j = 0; j < n; j++) {
            line[j] = copy[order[j]];
        }
    }

    for (int i = 0; i < n; i++) {
        fout << line[i] << "\n";
    }

    return 0;
}