#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

int changes[3][MAX_N + 1]; // Cow C, Day D
int rates[3][MAX_N + 1];

bool isHighest(int c, int d) {
    int highest = max(max(rates[0][d], rates[1][d]), rates[2][d]);
    return rates[c][d] == highest;
}

int main() {
    int n;
    fin >> n;

    int change = 0;

    for (int i = 0; i < n; i++) {
        int d;
        string c;
        int name = 0;
        int delta;
        fin >> d >> c >> delta;
        if (c == "Mildred") {
            name = 0;
        }
        else if (c == "Elsie") {
            name = 1;
        }
        else {
            name = 2;
        }
        changes[name][d] = delta;
    }

    for (int i = 0; i < 3; i++) {
        rates[i][0] = 7;
    }

    for (int c = 0; c < 3; c++) {
        for (int d = 1; d <= 100; d++) {
            rates[c][d] = rates[c][d - 1] + changes[c][d];
        }
    }

    for (int d = 1; d <= 100; d++) {
        if (isHighest(0, d - 1) != isHighest(0, d) || isHighest(1, d - 1) != isHighest(1, d) || isHighest(2, d - 1) != isHighest(2, d)) {
            change++;
        }
    }

    fout << change << endl;

}