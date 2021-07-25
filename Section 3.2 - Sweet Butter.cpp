/*
ID: 
TASK: butter
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

vector<pii> adj[810];
int dist[810];
int pas[510];
int n, p, c;

int bfs(int src) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, src});
    dist[src] = 0;
    
    int s, u;
    int v, d;
    while(!Q.empty()) {
        tie(s, u) = Q.top();
        Q.pop();
        if (s > dist[u]) continue;
        for (auto e : adj[u]) {
            tie(v, d) = e;
            if (dist[v] > s+d) {
                dist[v] = s+d;
                Q.push({dist[v], v});
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dist[pas[i]] >= INF) return INF;
        cnt += dist[pas[i]];
    }
    return cnt;
}

int main() {
    ofstream cout("butter.out");
    ifstream cin("butter.in");
    
    cin >> n >> p >> c;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pas[i] = x;
    }
    
    for (int i = 0, u, v, l; i < c; i++) {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    
    int ans = INT_MAX;
    for (int x = 1; x <= p; x++) {
        ans = min(ans, bfs(x));
    }
    
    cout << ans << "\n";
}