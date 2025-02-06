#include <bits/stdc++.h>

using namespace std;

ifstream fin("mixmilk.in");
ofstream fout("mixmilk.out");

void solve(int m1, int c1, int m2, int c2, int m3, int c3) {
    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            int diff = c2 - m2;
            if (m1 <= diff) {
                m2 += m1;
                m1 = 0;
            }
            else {
                m2 = c2;
                m1 -= diff;
            }
        }
        else if (i % 3 == 1) {
            int diff = c3 - m3;
            if (m2 <= diff) {
                m3 += m2;
                m2 = 0;
            }
            else {
                m3 = c3;
                m2 -= diff;
            }
        }
        else {
            int diff = c1 - m1;
            if (m3 <= diff) {
                m1 += m3;
                m3 = 0;
            }
            else {
                m1 = c1;
                m3 -= diff;
            }
        }
    }

    fout << m1 << endl << m2 << endl << m3 << endl;
}

int main () {
    int c1, m1, c2, m2, c3, m3;
    fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    if (c1 == m1 && c2 == m2 && c3 == m3) {
        fout << m1 << endl << m2 << endl << m3 << endl;
    }

    else {
        solve(m1, c1, m2, c2, m3, c3);
    }

    
    return 0;
}