#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;


void printOutput(map <string, int> &persons, int &np, vector <string> &order) {
    for (auto it = order.begin(); it != order.end(); it++) {
        fout << *it << " " << persons[*it] << "\n";
    }
}

int main() {
    fin.open("gift1.in");
    fout.open("gift1.out");

    int np;
    fin >> np;

    map <string, int> persons;
    vector <string> order;

    for (int i = 0; i < np; i++) {
        string tempPerson;
        fin >> tempPerson;
        persons[tempPerson] = 0;
        order.push_back(tempPerson);
        // cout << tempPerson << "\n";
    }

    int amount = 1, recipients;
    string giver;
    while (amount != 0) {
        fin >> giver;
        fin >> amount >> recipients;
        int eachAmount = amount / recipients;
        int backToUser = amount - (amount / recipients) * recipients;
        persons[giver] += backToUser;
        persons[giver] -= amount;

        for (int i = 0; i < recipients; i++) {
            string receiver;
            fin >> receiver;
            persons[receiver] += eachAmount;
        }
    }

    printOutput(persons, np, order);

    return 0;
}

