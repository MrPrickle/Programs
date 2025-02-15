#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lostcow.in");
ofstream fout ("lostcow.out");

int main () {
    int x, y;
    fin >> x >> y;

    bool isAfter;
    if (y > x) {
        isAfter = true;
    }
    else {
        isAfter = false;
    }

    bool flag = true;
    int num = 1;
    bool add = true;
    int sum = 0;
    int last = x;
    while (flag) {
        cout << "made it into the while loop" << endl;
        if (add) {
            cout << "add" << endl;
            int r = x + num;
            cout << r << endl;
            if (r >= y && isAfter) {
                flag = false;
                sum += (num + abs(last - x));
                sum -= (r - y);
            }
            else {
                sum += (num + abs(last - x));
            }
            num *= 2;
            add = false;
            last = r;
            cout << sum << endl;
        }
        else {
            cout << "subtract" << endl;
            int r = x - num;
            cout << r << endl;
            if (r <= y && !isAfter) {
                flag = false;
                sum += (num + abs(last - x));
                sum -= abs(r - y);
            }
            else {
                sum += (num + abs(last - x));
            }
            num *= 2;
            add = true;
            last = r;
            cout << sum << endl;
        }
    }

    fout << sum << endl;
    return 0;
}