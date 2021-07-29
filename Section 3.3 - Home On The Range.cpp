/*
ID: 
TASK: range
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int dp[255][255];
int n;
char g;
map<int, int> cnt;

int main() {
    ofstream cout("range.out");
    ifstream cin("range.in");
    
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g;
            if (g == '1') {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                if (dp[i][j] > 1) {
                    for (int k = 2; k <= dp[i][j]; k++) cnt[k]++;
                }
            }
        }
    }
    
    for (auto i : cnt) {
        cout << i.first << " " << i.second << "\n";
    }
}