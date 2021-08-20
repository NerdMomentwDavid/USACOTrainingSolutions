/*
ID:
TASK: schlnet
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x))

bool adj[105][105];
int g[105];
bool vis[105];
bool outdeg[105], indeg[105];
int c = 1;
int n;
stack<int> st;

void bfs(int src) {
    MEM(vis, 0);
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        g[u] = c;
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !vis[v]) {
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !vis[v]) dfs(v);
    }
    st.push(u);
}

void dfs2(int u) {
    g[u] = c;
    for (int v = 1; v <= n; v++) {
        if (adj[v][u] && !g[v]) dfs2(v);
    }
}

void bfs2(int src) {
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                if (g[u] != g[v]) {
                    outdeg[g[u]] = 1;
                    indeg[g[v]] = 1;
                }
                if (!vis[v]) {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}

int getSCC() {
    MEM(vis, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    MEM(g, 0);
    c = 1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!g[u]) {
            dfs2(u);
            c++;
        }
    }
    c--;
    if (c == 1) return 0;
    
    MEM(outdeg, 0); MEM(indeg, 0);
    MEM(vis, 0);
    int totin = 0, totout = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
           bfs2(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        totin += indeg[i];
        totout += outdeg[i];
    }
    return max(c-totin, c-totout);
}

int main() {
    ofstream cout("schlnet.out");
    ifstream cin("schlnet.in");

    MEM(adj, 0); MEM(g, 0);
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        while (v) {
            adj[u][v] = 1;
            cin >> v;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!g[i]) {
            bfs(i);
            c++;
        }
    }

    MEM(vis, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[g[i]]) {
            vis[g[i]] = 1;
            cnt++;
        }
    }
    
    cout << cnt << "\n" << getSCC() << "\n";

    return 0;
}

