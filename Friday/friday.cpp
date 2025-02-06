#include <bits/stdc++.h>

using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int main() {
    map <int, int> week;

    int n;
    fin >> n;

    int startingDayOfMonth = 1;
    bool isLeapYear = false;

    for (int i = 0; i < 7; i++) {
        week[i] = 0;
    }

    for (int i = 0; i <= n - 1; i++) {
        if ((i + 1900) % 400 == 0) {
            isLeapYear = true;
        }
        else {
            isLeapYear = ( (i % 4 == 0) && (i != 0) && (i % 100 != 0) );
        }

        for (int j = 1; j <= 12; j++) {
            int startDayOfMonth = startingDayOfMonth;
            week[( startDayOfMonth + 12 ) % 7]++;
            if (isLeapYear && j == 2) {
                startingDayOfMonth = (startDayOfMonth + 29) % 7;
            }
            else if (j == 2) {
                startingDayOfMonth = (startDayOfMonth + 28) % 7;
            }
            else if (j == 9 || j == 4 || j == 6 || j == 11) {
                startingDayOfMonth = (startDayOfMonth + 30) % 7;
            }
            else {
                startingDayOfMonth = (startDayOfMonth + 31) % 7;
            }
        }
    }
    fout << week[6] << " " << week[0];
    for (int i = 1; i <= 5; i++) {
        fout << " " << week[i];
    }

    return 0;
}