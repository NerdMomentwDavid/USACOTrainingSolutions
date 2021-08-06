/*
ID: 
TASK: stall4
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int cap[410][410];
int n, m;
bool vis[410];
int p[410];

int getMaxFlow() {
    memset(vis, 0, sizeof(vis)); memset(p, -1, sizeof(p));
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v = 1; v <= 405; v++) {
            if (v > n && v <= 200) v = 201;
            if (v > 200+m) v = 405;
            if (!vis[v] && cap[u][v] > 0) {
                p[v] = u;
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    
    int cur = 405;
    int mn = 0;
    while (p[cur] != -1) {
        int u = p[cur];
        mn = min(mn, cap[u][cur]);
        if (mn == 0) mn = cap[u][cur];
        cur = u;
    }
    
    cur = 405;
    while (p[cur] != -1) {
        int u = p[cur];
        cap[u][cur] -= mn;
        cap[cur][u] += mn;
        cur = u;
    }
    
    return mn;
}

int main() {
    ofstream cout("stall4.out");
    ifstream cin("stall4.in");
    
    memset(cap, 0, sizeof(cap));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cap[0][i] = 1;
        int s;
        cin >> s;
        for (int j = 0, x; j < s; j++) {
            cin >> x;
            cap[i][x+200] = 1;
        }
    }
    for (int i = 201; i <= 200+m; i++) {
        cap[i][405] = 1;
    }
    
    int ans = 0;
    int flow = getMaxFlow();
    while (flow) {
        ans += flow;
        flow = getMaxFlow();
    }
    cout << ans << "\n";
}
