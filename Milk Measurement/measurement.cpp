#include <bits/stdc++.h>

using namespace std;


ifstream fin("measurement.in");
ofstream fout("measurement.out");

struct cow {
    string name;
    int change;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    fin >> n;
    map <int, cow> input;
    map <string, int> cows;


    for (int i = 0; i < n; i++) {
        cow temp;
        int d;
        string n;
        int c;
        fin >> d >> n >> c;
        temp.name = n;
        temp.change = c;
        input[d] = temp;

        cows[n] = 0;
    }

    set <string> leaders;
    set <string> lastLeaders;
    int leaderAmt = INT_MIN;
    int lastLeaderAmt = INT_MIN;
    int timesChanged = 0;

    for (auto it = input.begin(); it != input.end(); it++) {
        cows[it->second.name] += it->second.change;
        if (cows[it->second.name] > leaderAmt && leaders.count(it->second.name) && leaders.size() > 1) {
            cout << "case 1" << "\n";
            lastLeaders = leaders;
            lastLeaderAmt = leaderAmt;
            leaderAmt = max(leaderAmt, cows[it->second.name]);
            set <string> newSet;
            leaders = newSet;
            if (leaders.insert(it->second.name).second) {
                timesChanged++;
            }
            else {
                ; // Already leader
            }
        }
        else if (cows[it->second.name] > leaderAmt && leaders.count(it->second.name) && leaders.size() == 1) {
            cout << "case 2" << "\n";
            set <string> newSet;
            leaders = newSet;
            lastLeaderAmt = leaderAmt;
            leaderAmt = max(leaderAmt, cows[it->second.name]);
            if (leaders.insert(it->second.name).second) {
                ;
            }
            else {
                ; // Already leader
            }
        }
        else if (cows[it->second.name] > leaderAmt) {
            cout << "case 3" << "\n";
            if (!(it == input.begin())) {
                lastLeaders = leaders;
                lastLeaderAmt = leaderAmt;
            }
            set <string> newSet;
            leaders = newSet;
            if (leaders.insert(it->second.name).second) {
                timesChanged++;
                leaderAmt = max(leaderAmt, cows[it->second.name]);
            }
            else {
                ; // Already leader
            }
            if (it == input.begin()) {
                lastLeaders = leaders;
                lastLeaderAmt = leaderAmt;
            }
        }
        else if (cows[it->second.name] == leaderAmt) {
            cout << "case 4" << "\n";
            lastLeaders = leaders;
            if (leaders.insert(it->second.name).second) {
                timesChanged++;
                leaderAmt = max(leaderAmt, cows[it->second.name]);
            }
            else {
                ; // Already leader
            }
        }
        else if (it->second.change < 0 && leaders.count(it->second.name) && leaders.size() > 1) {
            cout << "case 5" << "\n";
            lastLeaders = leaders;
            leaders.erase(it->second.name);
            timesChanged++;
        }
        else if (it->second.change < 0 && leaders.count(it->second.name) && leaders.size() == 1) {
            cout << "case 6" << "\n";
            if (cows[it->second.name] <= lastLeaderAmt) {
                timesChanged++;
                leaders = lastLeaders;
                leaderAmt = lastLeaderAmt;
            }
            else {
                leaderAmt = cows[it->second.name];
            }
        }
    }

    fout << timesChanged << "\n";

    return 0;
}