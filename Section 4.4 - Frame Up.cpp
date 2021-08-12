/*
ID:
TASK: frameup
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int g[30][30];
int adj[27][27];
bool f[27];
int pos[4][27];
// 0 - top most position
// 1 - bottom most position
// 2 - left most position
// 3 - right most position
int h, w;
int n = 0;

bool vis[27];
int p[27];

void printPath(int v, ofstream &cout) {
    if (v == 0) return;
    printPath(p[v], cout);
    cout << (char)(v+'A'-1);
}

bool check(int v) {
    for (int u = 1; u <= 26; u++) {
        if (!vis[u] && adj[u][v] == 2) return 0;
    }
    return 1;
}

void dfs(int u, int l, ofstream &cout) {
    if (!check(u)) return;
    if (l == n) {
        printPath(u, cout);
        cout << "\n";
        return;
    }
    
    vis[u] = 1;
    for (int v = 1; v <= 26; v++) {
        if (f[v] && adj[u][v] && !vis[v]) {
            p[v] = u;
            dfs(v, l+1, cout);
            p[v] = 0;
        }
    }
    vis[u] = 0;
}

int main() {
    ofstream cout("frameup.out");
    ifstream cin("frameup.in");
    cin >> h >> w;
    char ch;
    int c;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (c = 1; c <= 26; c++) {
        pos[0][c] = 30;
        pos[1][c] = -1;
        pos[2][c] = 30;
        pos[3][c] = -1;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> ch;
            if (ch == '.') continue;
            c = ch-'A'+1;
            if (!f[c]) n++;
            f[c] = 1;
            pos[0][c] = min(pos[0][c], i);
            pos[1][c] = max(pos[1][c], i);
            pos[2][c] = min(pos[2][c], j);
            pos[3][c] = max(pos[3][c], j);
            g[i][j] = c;
        }
    }
    
    for (char a = 1; a <= 26; a++) {
        adj[0][a] = 1;
        for (char b = 1; b <= 26; b++) {
            adj[a][b] = 1;
        }
    }
    
    for (c = 1; c <= 26; c++) {
        if (!f[c]) continue;
        int sr = pos[0][c], tr = pos[1][c];
        int sc = pos[2][c], tc = pos[3][c];
        for (int i = sr; i <= tr; i++) {
            if (g[i][sc] != c) {
                adj[g[i][sc]][c] = 0;
                adj[c][g[i][sc]] = 2;
            }
            if (g[i][tc] != c) {
                adj[g[i][tc]][c] = 0;
                adj[c][g[i][tc]] = 2;
            }
        }
        for (int j = sc; j <= tc; j++) {
            if (g[sr][j] != c) {
                adj[g[sr][j]][c] = 0;
                adj[c][g[sr][j]] = 2;
            }
            if (g[tr][j] != c) {
                adj[g[tr][j]][c] = 0;
                adj[c][g[tr][j]] = 2;
            }
        }
    }
    
    memset(vis, 0, sizeof(vis));
    memset(p, 0, sizeof(p));
    dfs(0, 0, cout);
}
