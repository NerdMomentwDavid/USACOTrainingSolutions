/*
ID:
TASK: fence6
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adjl[105], adjr[105];
int L[105];
char pos[105][105];
int n;

bool vis[105];
int dfs(int u, char p) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int opt = INT_MAX;
    if (p == 'R') {
        for (auto v : adjl[u]) {
            opt = min(opt, dfs(v, pos[v][u])+L[u]);
        }
    } else {
        for (auto v : adjr[u]) {
            opt = min(opt, dfs(v, pos[v][u])+L[u]);
        }
    }
    vis[u] = 0;
    return opt;
}

int main() {
    ofstream cout("fence6.out");
    ifstream cin("fence6.in");
    
    cin >> n;
    for (int i = 0, s, n1, n2; i < n; i++) {
        cin >> s >> L[s] >> n1 >> n2;
        for (int j = 0, v; j < n1; j++) {
            cin >> v;
            adjl[s].push_back(v);
            pos[s][v] = 'L';
        }
        for (int j = 0, v; j < n2; j++) {
            cin >> v;
            adjr[s].push_back(v);
            pos[s][v] = 'R';
        }
    }
    
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        int tmp = dfs(i, 'L');
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
}