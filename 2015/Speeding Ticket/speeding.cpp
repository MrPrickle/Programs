#include <bits/stdc++.h>

using namespace std;

ifstream fin("speeding.in");
ofstream fout("speeding.out");

void solve(int n, int m, int bessie[100], int road[100]) {
    int startNum = 0;
    for (int i = 1; i <= n; i++) {
        int ctr = 1;
        int distance, limit;
        fin >> distance >> limit;
        for (int j = startNum; j < startNum + distance; j++) {
            road[j] = limit;
            cout << j << " " << limit << " " << ctr << "\n";
            ctr++;
        }
        startNum += distance;
    }
    startNum = 0;
    cout << "\n";
    for (int i = 1; i <= m; i++) {
        int ctr = 1;
        int distance, speed;
        fin >> distance >> speed;
        for (int j = startNum; j < startNum + distance; j++) {
            bessie[j] = speed;
            cout << j << " " << speed << " " << ctr << "\n";
            ctr++;
        }
        startNum += distance;
    }

    set <int> differences;

    for (int i = 0; i < 100; i++) {
        // cout << bessie[i] << " " << road[i] << "\n";
        differences.insert(bessie[i] - road[i]);
    }

    int answer = *--differences.end();

    if (answer <= 0) {
        fout << 0 << "\n";
    }
    else {
        fout << *--differences.end() << "\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    int road[100];
    int bessie[100];

    fin >> n >> m;

    solve(n, m, road, bessie);

    return 0;
}