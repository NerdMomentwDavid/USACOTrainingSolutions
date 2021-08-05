/*
ID:
TASK: ditch
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int cap[205][205];
int flow[205];
bool vis[205];
int n, m;

int getMax() {
    int ind = -1;
    int mx = -1;
    for (int i = 1; i <= m; i++) {
        if (!vis[i] && flow[i] > mx) {
            mx = flow[i];
            ind = i;
        }
    }
    return ind;
}

int getCap() {
    memset(vis, 0, sizeof(vis));
    memset(flow, 0, sizeof(flow));
    flow[1] = INT_MAX;
    int p[m+1]; memset(p, -1, sizeof(p));
    
    while (1) {
        int u = getMax();
        if (u == m) break;
        vis[u] = 1;
        for (int v = 1; v <= m; v++) {
            if (min(flow[u], cap[u][v]) > flow[v]) {
                flow[v] = min(flow[u], cap[u][v]);
                p[v] = u;
            }
        }
    }
    
    int node = m;
    while (p[node] != -1) {
        cap[p[node]][node] -= flow[m];
        cap[node][p[node]] += flow[m];
        node = p[node];
    }
    
    return flow[m];
}

int getMaxFlow() {
    int cur = getCap();
    int ans = 0;
    while (cur != 0) {
        ans += cur;
        cur = getCap();
    }
    return ans;
}

int main() {
    ofstream cout("ditch.out");
    ifstream cin("ditch.in");
    
    memset(cap, 0, sizeof(cap));
    cin >> n >> m;
    for (int i = 0, u, v, f; i < n; i++) {
        cin >> u >> v >> f;
        cap[u][v] += f;
    }
    
    cout << getMaxFlow() << "\n";
}