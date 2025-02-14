#include <bits/stdc++.h>

using namespace std;

ifstream fin ("censor.in");
ofstream fout ("censor.out");

int main () {
    string str, t;
    fin >> str >> t;

    bool done = false;
    while (!done) {
        bool found = false;
        for (int i = 0; i <= str.length() - t.length(); i++) {
            if (str.substr(i, t.length()) == t) {
                str.erase(i, t.length());
                found = true;
                break;
            }
        }
        if (!found) {
            done = true;
        }
    }

    fout << str << endl;
    return 0;
}