/*
ID: 
TASK: inflate
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int dp[10005];
int m, n;
int w[10005], v[10005];

int main() {
    ofstream cout("inflate.out");
    ifstream cin("inflate.in");
    
    cin >> m >> n;
    
    fill(dp, dp+m+1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (w[j] <= i) dp[i] = max(dp[i], dp[i-w[j]]+v[j]);
        }
    }
    
    cout << dp[m] << "\n";
}