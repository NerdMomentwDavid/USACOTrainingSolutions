/*
ID: 
TASK: tour
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;
bool g[100][100];
int dp[100][100];
int n, m;

int main() {
    ofstream cout("tour.out");
    ifstream cin("tour.in");

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        um[s] = i;
    }

    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        g[um[a]][um[b]] = 1;
        g[um[b]][um[a]] = 1;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (g[k][j] && dp[i][k]) dp[i][j] = max(dp[i][j], dp[i][k]+1);
            }
            dp[j][i] = dp[i][j];
        }
        if (g[i][n-1]) {
            ans = max(ans, dp[i][n-1]);
        }
    }

    cout << ans << "\n";

    return 0;
}

