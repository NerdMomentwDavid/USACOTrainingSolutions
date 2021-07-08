/*
ID:
TASK: money
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int coin[25];
long long dp[10005];

int main() {
    ofstream cout("money.out");
    ifstream cin("money.in");
    
    int v, n;
    cin >> v >> n;
    for (int i = 0; i < v; i++) cin >> coin[i];
    
    dp[0] = 1;
    for (int i = 0; i < v; i++) {
        for (int j = 1; j <= n; j++) {
            if (coin[i] <= j) {
                dp[j] += dp[j-coin[i]];
            }
        }
    }
    
    cout << dp[n] << "\n";
}