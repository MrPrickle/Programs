#include <bits/stdc++.h>

using namespace std;

ifstream fin ("blocks.in");
ofstream fout ("blocks.out");

int main () {
    int n;
    fin >> n;

    map <char, int> alphabet;

    string alphie = "abcdefghijklmnopqrstuvwxyz";

    for (char c : alphie) {
        alphabet[c] = 0;
    }

    map <char, int> alphabetCopy = alphabet;

    for (int i = 0; i < n; i++) {
        string a, b;
        fin >> a >> b;

        map <char, int> alphas1 = alphabetCopy;
        map <char, int> alphas2 = alphabetCopy;

        vector <int> betas1;
        vector <int> betas2;

        for (char c : a) {
            alphas1[c]++;
        }
        for (char c : b) {
            alphas2[c]++;
        }

        for (auto it = alphas1.begin(); it != alphas1.end(); it++) {
            betas1.push_back(it->second);
        }

        for (auto it = alphas2.begin(); it != alphas2.end(); it++) {
            betas2.push_back(it->second);
        }

        int n = 0;
        for (auto it = alphas1.begin(); it != alphas1.end(); it++) {
            alphabet[it->first] += max(betas1[n], betas2[n]);
            n++;
        }
    }

    for (auto it = alphabet.begin(); it != alphabet.end(); it++) {
        fout << it->second << endl;
    }
    return 0;
}