/*
ID: 
TASK: milk6
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int u, v, c, x;
};

int cap[35][35], rescap[35][35];
int n, m;
int p[35];
int dist[35];
bool vis[35];
Edge edge[1005];

int getMaxDist() {
    int mx = -1, ind = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx && !vis[i]) {
            mx = dist[i];
            ind = i;
        }
    }
    return ind;
}

bool dijkstra() {
    memset(p, -1, sizeof(p));
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1] = INT_MAX;
    while (1) {
        int u = getMaxDist();
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (cap[u][v] && !vis[v] && dist[v] < cap[u][v]) {
                dist[v] = cap[u][v];
                p[v] = u;
            }
        }
    }
    
    if (p[n] == -1) return 0;
    return 1;
}

int getMaxFlow() {
    int flow = 0;
    while (dijkstra()) {
        int v = n;
        int mn = INT_MAX;
        while (p[v] != -1) {
            int u = p[v];
            mn = min(mn, cap[u][v]);
            v = u;
        }
        
        v = n;
        while (p[v] != -1) {
            int u = p[v];
            cap[u][v] -= mn;
            cap[v][u] += mn;
            v = u;
        }
        
        flow += mn;
    }
    
    return flow;
}

void restoreCap() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cap[i][j] = rescap[i][j];
        }
    }
}

bool comp(Edge a, Edge b) {
    return a.c > b.c;
}

int main() {
    ofstream cout("milk6.out");
    ifstream cin("milk6.in");
    
    memset(cap, 0, sizeof(cap));
    cin >> n >> m;
    ll flow = 0;
    for (int i = 0;  i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
        edge[i].x = i+1;
        rescap[edge[i].u][edge[i].v] += edge[i].c;
    }
    
    sort(edge, edge+m, comp);
    restoreCap();
    int oflow = getMaxFlow();
    
    vector<int> ans;
    int s = 0;
    for (int i = 0; i < m; i++) {
        restoreCap();
        cap[edge[i].u][edge[i].v] -= edge[i].c;
        int tmp = getMaxFlow();
        if (oflow - edge[i].c == tmp) {
            ans.push_back(edge[i].x);
            s += edge[i].c;
            if (s == oflow) break;
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << oflow << " " << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }
}
