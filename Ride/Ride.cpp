#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("Ride.in");
    fout.open("Ride.out");

    string commet, group;

    fin >> commet >> group;

    int commetProduct = 1, groupProduct = 1;

    for (char c : commet) {
        commetProduct *= (c - 64);
    }
    for (char g : group) {
        groupProduct *= (g - 64);
    }

    if (commetProduct % 47 == groupProduct % 47) {
        fout << "GO" << "\n";
    }
    else {
        fout << "STAY" << "\n";
    }
    
    return 0;
}