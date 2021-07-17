/*
ID:
TASK: humble
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int p[100], x[100];
int k, n;

int main() {
    ofstream cout("humble.out");
    ifstream cin("humble.in");
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> p[i];
    
    memset(x, 0, sizeof(x));
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < k; j++) {
            for (; x[j] < i && p[j]*dp[x[j]] <= dp[i-1]; x[j]++);
            dp[i] = min(dp[i], p[j]*dp[x[j]]);
        }
    }
    
    cout << dp[n] << "\n";
}