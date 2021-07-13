/*
ID: davidwa11
TASK: comehome
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef long long ll;

int g['z'+1]['z'+1];
int dist['z'+1];
bool vis['z'+1];

int minD() {
    int m = INT_MAX, ind = -1;
    for (int i = 'A'; i <= 'z'; i++) {
        if (dist[i] < m && !vis[i]) {
            m = dist[i];
            ind = i;
        }
    }
    return ind;
}

void dijkstra() {
    dist['Z'] = 0;
    for (int i = 'Z'+1; i <= 'a'-1; i++) vis[i] = 1;
    for (int i = 'A'; i <= 'z'; i++) {
        int x = minD();
        if (x == -1) break;
        vis[x] = 1;
        for (int y = 'A'; y <= 'z'; y++) {
            if (x != y && !vis[y] && dist[y] > dist[x] + g[x][y]) {
                dist[y] = dist[x] + g[x][y];
            }
        }
    }
}

void floyd() { // both works but floyd takes O(n^3) and dijkstra takes O(n^2)
    for (int k = 'A'; k <= 'z'; k++) {
        for (int i = 'A'; i <= 'z'; i++) {
            for (int j = 'A'; j <= 'z'; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[j][i] = g[i][k] + g[k][j];
                }
            }
        }
    }
    
    for (int i = 'A'; i <= 'Y'; i++) dist[i] = g['Z'][i];
}

int main() {
    ofstream cout("comehome.out");
    ifstream cin("comehome.in");
    
    memset(g, INF, sizeof(g));
    memset(dist, INF, sizeof(dist));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int d;
        cin >> a >> b >> d;
        if (d < g[a][b]) g[a][b] = g[b][a] = d;
    }
    
    //dijkstra();
                      // You can use either Dijkstra or Floyd algorithm because the graph has a very small range
    floyd();
    
    int m = INF;
    char u;
    for (int i = 'A'; i <= 'Y'; i++) {
        if (dist[i] < m) {
            m = dist[i];
            u = i;
        }
    }
    cout << u << " " << m << "\n";
}