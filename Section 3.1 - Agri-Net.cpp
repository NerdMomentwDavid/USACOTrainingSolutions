/*
ID: 
TASK: agrinet
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int g[100][100];
bool vis[100];
int dist[100];
//int p[100];    // uncomment to see construction of the mst
int n;

int minD() {
    int ind = -1, m = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dist[i] < m && !vis[i]) {
            ind = i;
            m = dist[i];
        }
    }
    return ind;
}

int mst() {
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[0] = 0;
    int c = 0;
    //p[0] = 0;    // uncomment to see construction of the mst
    int u = minD();
    while (u != -1) {
        c += dist[u];
        //cout << "from " << p[u] << " to " << u << " add: " << dist[u] << "\n";    // uncomment to see construction of the mst
        vis[u] = 1;
        for (int i = 0; i < n; i++) {
            if (g[u][i] && g[u][i] < dist[i]) {
                dist[i] = g[u][i];
                //p[i] = u;    // uncomment to see construction of the mst
            }
        }
        
        u = minD();
    }
    
    return c;
}

int main() {
   ofstream cout("agrinet.out");   // Comment these 2 lines
   ifstream cin("agrinet.in");     // to print to stdio
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    cout << mst() << "\n";
}