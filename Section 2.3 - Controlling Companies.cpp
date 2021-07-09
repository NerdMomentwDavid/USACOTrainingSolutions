/*
ID:
TASK: concom
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int adj[105][105];
bool vis[105];
int share[105];
int n;

void dfs(int i) {
    vis[i] = 1;
    for (int j = 1; j <= 100; j++) {
        if (adj[i][j] && !vis[j]) {
            share[j] += adj[i][j];
            if (share[j] > 50) dfs(j);
        }
    }
}

int main() {
    ofstream cout("concom.out");
    ifstream cin("concom.in");
    
    memset(adj, 0, sizeof(adj));
    cin >> n;
    while (n--) {
        int i, j, p;
        cin >> i >> j >> p;
        adj[i][j] += p;
    }
    
    for (int i = 1; i <= 100; i++) {
        memset(vis, 0, sizeof(vis)); memset(share, 0, sizeof(share));
        share[i] = 100;
        dfs(i);
        for (int j = 1; j <= 100; j++) {
            if (share[j] > 50 && j != i) {
                cout << i << " " << j << "\n";
            }
        }
    }
}
