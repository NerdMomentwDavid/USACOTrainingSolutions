/*
ID: 
TASK: stamps
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

const int MM = int(2e6)+10;

int dp[MM];
int a[60];
int k, n;

int main() {
    ofstream cout("stamps.out");
    ifstream cin("stamps.in");
    
    cin >> k >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a+n);
    memset(dp, -1, sizeof(dp));
    
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i < MM; i++) {
        int m = INT_MAX;
        
        for (int j = 0; j < n; j++) {
            if (a[j] > i) break;
            int v = i-a[j];
            if (dp[v] != -1 && dp[v] < k) m = min(m, dp[v]+1);
        }
        
        if (m == INT_MAX) break;
        dp[i] = m;
        ans++;
    }
    
    cout << ans << "\n";
}