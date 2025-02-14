#include <bits/stdc++.h>

using namespace std;

ifstream fin ("censor.in");
ofstream fout ("censor.out");

bool checkStack (string &stack, string &t) {
    if (stack.length() < t.length()) {
        return true;
    }
    if (stack.substr(stack.length() - t.length()) == t) {
        return false;
    }
    return true;
}

int main () {
    string str, t;
    fin >> str >> t;

    string stack;

    for (char c : str) {
        stack += c;
        if (!checkStack(stack, t)) {
            stack.resize(stack.length() - t.length());
        }
    }

    fout << stack << endl;
    return 0;
}