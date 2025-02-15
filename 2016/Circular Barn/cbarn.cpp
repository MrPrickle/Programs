#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cbarn.in");
ofstream fout ("cbarn.out");


int main () {
    int n;
    fin >> n;
    vector <int> cows(n);

    int totalCows = 0;

    for (int i = 0; i < n; i++) {
        fin >> cows[i];
        totalCows += cows[i];
    }

    // cout << "\n" << totalCows << "\n";

    int prevTotal = 0;
    int minTotal = INT_MAX;

    for (int i = 0; i < n; i++) {
        prevTotal += i * cows[i];
        // cout << prevTotal << "\n";
    }

    minTotal = min(minTotal, prevTotal);

    // cout << "\n";
    // cout << minTotal << "\n";
    // cout << "\n";

    for (int i = 1; i < n; i++) {
        int currTotal = prevTotal + cows[i - 1] * n - totalCows;
        // cout << currTotal << " ";
        minTotal = min(minTotal, currTotal);
        // cout << minTotal << "\n";
        prevTotal = currTotal;
    }

    fout << minTotal << "\n";
    return 0;
} 