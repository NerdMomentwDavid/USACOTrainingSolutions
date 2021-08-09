/*
ID:
TASK: race3
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[55], rev[55];
bool vis[55], vis2[55];
int n = 0;
bool p[55][55];

bool bfs1(int mid, int en) {
    memset(vis, 0, sizeof(vis));
    vis[mid] = 1;
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == en) return 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    
    return 0;
}

void bfs2(int src) {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : rev[u]) {
            if (!vis[v]) {
                p[v][src] = 1;
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}

bool bfs3(int src) {
    memset(vis2, 0, sizeof(vis));
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (p[u][src]) {
            if (bfs1(src, u)) return 0;
        }
        for (int v : adj[u]) {
            if (!vis2[v]) {
                vis2[v] = 1;
                Q.push(v);
            }
        }
    }
    return 1;
}

int main() {
    ofstream cout("race3.out");
    ifstream cin("race3.in");
    
    int x, mx = 0;
    cin >> x;
    while (x != -1) {
        mx = max(x, mx);
        if (x == -2) n++;
        else {
            adj[n].push_back(x);
            rev[x].push_back(n);
        }
        cin >> x;
    }
    
    n = max(n, mx+1);
    
    vector<int> a1, a2;
    for (int i = 1; i < n-1; i++) {
        if (!bfs1(i, n-1)) a1.push_back(i);
    }
    
    memset(p, 0, sizeof(p));
    
    for (int i : a1) {
        bfs2(i);
        if (bfs3(i)) a2.push_back(i);
    }
    
    cout << a1.size();
    for (int i : a1) cout << " " << i;
    cout << "\n" << a2.size();
    for (int i : a2) cout << " " << i;
    cout << "\n";
    
}
