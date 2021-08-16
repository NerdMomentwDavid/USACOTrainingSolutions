/*
ID:
TASK: snail
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n, b;
int g[125][125];
int m[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans = 0;

int dfs(int r, int c, int d, bool f) {
    int tr = r+m[d][0], tc = c+m[d][1];
    g[r][c] = 2;
    int res = 1;
    if (tr >= 0 && tr < n && tc >= 0 && tc < n) {
        if (g[tr][tc] == 0) res = 1+dfs(tr, tc, d, 0);
        else if (g[tr][tc] == 1) {
            if (!f) res = max(dfs(r, c, (d+1)%4, 1), dfs(r, c, (d+3)%4, 1));
        }
    } else if (!f) res = max(dfs(r, c, (d+1)%4, 1), dfs(r, c, (d+3)%4, 1));
    g[r][c] = 0;
    return res;
}

int main() {
    ofstream cout("snail.out");
    ifstream cin("snail.in");
    memset(g, 0, sizeof(g));
    cin >> n >> b;
    char x;
    int y;
    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        g[x-'A'][y-1] = 1;
    }
    
    cout << max(dfs(0, 0, 0, 0), dfs(0, 0, 1, 0)) << "\n";
}
