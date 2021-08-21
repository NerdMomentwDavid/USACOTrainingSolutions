/*
ID:
TASK: bigbrn
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002];
bool a[1002][1002];
int n, t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ifstream cin("bigbrn.in");
    ofstream cout("bigbrn.out");

    cin >> n >> t;
    memset(a, 0, sizeof(a));
    for (int i = 0, r, c; i < t; i++) {
        cin >> r >> c;
        a[r][c] = 1;
    }

    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

