#include <bits/stdc++.h>

using namespace std;

ifstream fin ("blist.in");
ofstream fout ("blist.out");



int main () {
    map <int, pair <int, int>> input;
    map <int, int> end_bucket;
    int n;

    fin >> n;

    for (int i = 0; i < n; i++) {
        pair <int, int> newPair;
        int startDay, endDay, buckets;
        fin >> startDay >> endDay >> buckets;
        newPair.first = endDay;
        newPair.second = buckets;
        input[startDay] = newPair;
    }

    int totalBucketsNeeded = 0;

    cout << "reached lin 26" << endl;

    for (auto it = input.begin(); it != input.end(); it++) {
        if (end_bucket.empty()) {
            cout << "reached start\n";
            totalBucketsNeeded += it->second.second;
            end_bucket[it->second.first] = it->second.second;
            cout << "reached endStart\n";
        }
        else {
            int bucketsNeeded = it->second.second;
            while (bucketsNeeded > 0) {
                if (end_bucket.empty() || end_bucket.begin()->first > it->first) {
                    // No available buckets to reuse
                    totalBucketsNeeded += bucketsNeeded;
                    end_bucket[it->second.first] = it->second.second;
                    break;
                }
                
                // Collect all available buckets from completed milkings
                int availableBuckets = 0;
                vector<map<int,int>::iterator> toErase;
                
                for (auto itt = end_bucket.begin(); itt != end_bucket.end() && itt->first <= it->first; itt++) {
                    availableBuckets += itt->second;
                    toErase.push_back(itt);
                }
                
                // Use available buckets
                if (availableBuckets >= bucketsNeeded) {
                    // We have enough buckets to reuse
                    end_bucket[it->second.first] = it->second.second;
                    
                    // Remove used ending times and update last one if partial use
                    int remaining = availableBuckets - bucketsNeeded;
                    for (auto itt : toErase) {
                        end_bucket.erase(itt);
                    }
                    if (remaining > 0) {
                        end_bucket[toErase.back()->first] = remaining;
                    }
                    break;
                } else {
                    // Use what we can and continue loop for remaining needed
                    bucketsNeeded -= availableBuckets;
                    for (auto itt : toErase) {
                        end_bucket.erase(itt);
                    }
                }
            }
        }
    }

    fout << totalBucketsNeeded << endl;

    return 0;
}