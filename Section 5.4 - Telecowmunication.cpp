/*
ID:
TASK: telecow
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

int n, m, s, t;
int g[205][205], o[205][205];
int p[205];

bool bfs() {
    queue<int> Q;
    MEM(p, 0);
    p[s] = s;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t-1) return 1;
        for (int v = 1; v <= n; v++) {
            if (!p[v] && g[u][v] > 0) {
                Q.push(v);
                p[v] = u;
            }
        }
    }
    return 0;
}

int getMaxFlow() {
    int f = 0;
    while (bfs()) {
        int mn = 10000;
        int cur = t-1;
        while (cur != s) {
            int u = p[cur];
            mn = min(mn, g[u][cur]);
            cur = u;
        }
        cur = t-1;
        while (cur != s) {
            int u = p[cur];
            g[u][cur] -= mn;
            g[cur][u] += mn;
            cur = u;
        }
        f += mn;
    }
    return f;
}

void resetGraph() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g[i][j] = o[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ofstream cout("telecow.out");
    ifstream cin("telecow.in");
    
    cin >> n >> m >> s >> t;
    s *= 2;
    t *= 2;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        o[u*2][v*2-1] = 1;
        o[v*2][u*2-1] = 1;
    }
    
    n *= 2;
    for (int i = 2; i <= n; i+=2) {
        o[i-1][i] = 1;
    }
    
    resetGraph();
    int c = getMaxFlow();
    vector<int> ans;
    
    for (int i = 2; i <= n; i += 2) {
        if (i == s || i == t) continue;
        o[i-1][i]--;
        resetGraph();
        int f = getMaxFlow();
        if (f < c) {
            ans.push_back(i/2);
            c = f;
            continue;
        }
        o[i-1][i]++;
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
    
    return 0;
}

