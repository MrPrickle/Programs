#include <bits/stdc++.h>

using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int main() {
    int x1, y1, x2, y2;
    int x11, y11, x22, y22;
    int tx1, ty1, tx2, ty2;

    vector <vector <int>> data;

    for (int i = 0; i < 2; i++) {
        vector <int> temp(4);
        for (int i = 0; i < 4; i++) {
            fin >> temp[i];
        }
        data.push_back(temp);
    }

    fin >> tx1 >> ty1 >> tx2 >> ty2;

    int totalArea = 0;
    
    for (int i = 0; i < 2; i++) {
        int xa, ya, xb, yb;
        xa = data[i][0];
        ya = data[i][1];
        xb = data[i][2];
        yb = data[i][3];

        int xLen, yLen;

        if (xb > tx1 && xa <= tx1 && xb <= tx2) {
            cout << "a" << "\n";
            xLen = xb - tx1;
        }
        else if (xa < tx2 && xa >= tx1 && xb >= tx2) {
            cout << "b" << "\n";
            xLen = tx2 - xa;
        }
        else if (xb <= tx1 || xa >= tx2) {
            cout << "c" << "\n";
            xLen = 0;
        }
        else if (xb >= tx2 && xa <= tx1) {
            cout << "d" << "\n";
            xLen = tx2 - tx1;
        }
        else if (tx2 >= xb && tx1 <= xa) {
            cout << "e" << "\n";
            xLen = xb - xa;
        }

        if (yb > ty1 && ya <= ty1 && yb <= ty2) {
            cout << "a" << "\n";
            yLen = yb - ty1;
        }
        else if (ya < ty2 && ya >= ty1 && yb >= ty2) {
            cout << "b" << "\n";
            yLen = ty2 - ya;
        }
        else if (yb <= ty1 || ya >= ty2) {
            cout << "c" << "\n";
            yLen = 0;
        }
        else if (yb >= ty2 && ya <= ty1) {
            cout << "d" << "\n";
            yLen = ty2 - ty1;
        }
        else if (ty2 >= yb && ty1 <= ya) {
            cout << "e" << "\n";
            yLen = yb - ya;
        }

        int tempArea = (yb - ya) * (xb - xa) - xLen * yLen;

        cout << xLen * yLen << " " << tempArea << "\n";

        totalArea += tempArea;
    }

    fout << totalArea;

    return 0;
}