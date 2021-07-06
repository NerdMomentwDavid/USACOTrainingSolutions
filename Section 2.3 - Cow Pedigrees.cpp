/*
ID:
TASK: nocows
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int dp[201][101];
int n, k;

int main() {
    ofstream cout("nocows.out");
    ifstream cin("nocows.in");
    
    cin >> n >> k;
    for (int i = 1; i <= k; i++) dp[1][i] = 1;
    for (int i = 3; i <= n; i+=2) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= i-2; l++) {
                dp[i][j] += dp[l][j-1]*dp[i-l-1][j-1];
                dp[i][j] %= 9901;
            }
        }
    }
    
    cout << (dp[n][k]-dp[n][k-1]+9901)%9901 << "\n";
}
