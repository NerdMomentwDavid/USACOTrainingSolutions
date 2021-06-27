/*
ID:
TASK: numtri
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int a[1001][1001];
int n;

int search(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == n-1) return a[x][y];
    dp[x][y] = a[x][y] + max(search(x+1, y), search(x+1, y+1));
    return dp[x][y];
}

int main() {
    ofstream cout("numtri.out");
    ifstream cin("numtri.in");
    
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << search(0, 0) << "\n";
}
