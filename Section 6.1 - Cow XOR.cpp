/*
ID: 
TASK: cowxor
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int trie[1000005][2];
int val[100005];
unordered_map<int, int> ind;
int cnt = 1;

int main() {
    ofstream cout("cowxor.out");
    ifstream cin("cowxor.in");
    
    int n;
    cin >> n;
    memset(trie, 0, sizeof(trie));
    val[0] = 0;
    int p = 1;
    for (int i = 20; i >= 0; i--) {
        cnt++;
        trie[p][0] = cnt;
        p = trie[p][0];
    }
    ind[p] = 0;
    
    int ans = 0, l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        val[i] ^= val[i-1];
        p = 1;
        for (int j = 20; j >= 0; j--) {
            int bit = (val[i]>>j) & 1;
            if (!trie[p][!bit]) p = trie[p][bit];
            else p = trie[p][!bit];
        }
        
        int xval = val[i]^val[ind[p]];
        if (xval > ans) {
            ans = xval;
            l = ind[p]+1;
            r = i;
        }
        
        p = 1;
        for (int j = 20; j >= 0; j--) {
            int bit = (val[i]>>j) & 1;
            if (!trie[p][bit]) {
                cnt++;
                trie[p][bit] = cnt;
            }
            p = trie[p][bit];
        }
        ind[p] = i;
    }
    cout << ans << " " << l << " " << r << "\n";
}
