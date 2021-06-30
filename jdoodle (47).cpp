/*
ID:
TASK: hamming
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int N, B, D;

int dist(int a, int b) {
    bitset<8> bit = a^b;
    int d = 0;
    for (int i = 0; i < B; i++) {
        if (bit[i]) d++;
    }
    return d;
}

int main() {
    ofstream cout("hamming.out");
    ifstream cin("hamming.in");
    
    cin >> N >> B >> D;
    int c = 1;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <  INT_MAX; i++) {
        if (c == N) break;
        bool f = 1;
        for (int j : ans) {
            if (dist(j, i) < D) {
                f = 0;
                break;
            }
        }
        if (f) {
            c++;
            ans.push_back(i);
        }
    }
    
    for (int i = 1; i <= c; i++) {
        cout << ans[i-1];
        if (i%10==0 || i == c) cout << "\n";
        else cout << " ";
    }
}