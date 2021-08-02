/*
ID: 
TASK: rockers
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int a[25];

int main() {
    ofstream cout("rockers.out");
    ifstream cin("rockers.in");
    
    int n, t, m;
    cin >> n >> t >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int l = 1 << n;
    int ans = 0;
    for (int i = 1; i < l; i++) {
        bitset<20> c(i);
        if (c.count() < ans) continue;
        int sum[m];
        memset(sum, 0, sizeof(sum));
        int ind = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            if (c[j]) {
                if (a[j]+sum[ind] > t) ind++;
                if (a[j] > t || ind == m) break;
                sum[ind] += a[j];
                cnt++;
            }
        }
        
        if (cnt == c.count()) ans = cnt;
    }
    
    cout << ans << "\n";
}