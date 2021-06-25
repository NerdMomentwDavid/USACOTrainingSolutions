/*
ID: davidwa11
TASK: castle
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool wall[20][4];
int a[50][50];
bool vis[50][50];
int area[50][50];
pair<int, int> rooms[50][50];

int bfs(int X, int Y) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(X, Y));
    vis[X][Y] = 1;
    int c = 0;
    int x, y;
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();
        x = u.first, y = u.second;
        
        c++;
        rooms[x][y] = make_pair(X, Y);
        
        if (x>0 && !wall[a[x][y]][0] && !vis[x-1][y]) { // NORTH
            vis[x-1][y]=1;
            Q.push(make_pair(x-1, y));
        }
        if (y>0 && !wall[a[x][y]][1] && !vis[x][y-1]) { // WEST
            vis[x][y-1]=1;
            Q.push(make_pair(x, y-1));
        }
        if (x<n-1 && !wall[a[x][y]][2] && !vis[x+1][y]) { // SOUTH
            vis[x+1][y]=1;
            Q.push(make_pair(x+1, y));
        }
        if (y<m-1 && !wall[a[x][y]][3] && !vis[x][y+1]) { // EAST
            vis[x][y+1]=1;
            Q.push(make_pair(x, y+1));
        }
    }
    
    return c;
}

pair<int, int> maxArea(int a, int b) {
    memset(vis, 0, sizeof(vis));
    int M = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                c++;
                area[i][j] = bfs(i, j);
                M = max(M, area[i][j]);
            }
        }
    }
    
    return make_pair(c, M);
}

int main() {
    ofstream cout("castle.out");
    ifstream cin("castle.in");
    
    memset(wall, 0, sizeof(wall));
    for (int N = 0; N < 2; N++) {
        for (int W = 0; W < 2; W++) {
            for (int S = 0; S < 2; S++) {
                for (int E = 0; E < 2; E++) {
                    int ind = N*2+W*1+S*8+E*4;
                    if (N) wall[ind][0] = 1;
                    if (W) wall[ind][1] = 1;
                    if (S) wall[ind][2] = 1;
                    if (E) wall[ind][3] = 1;
                }
            }
        }
    }
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    pair<int, int> t = maxArea(0, 0);
    cout << t.first << "\n" << t.second << "\n";
    
    int ansX, ansY, x, y;
    string dir;
    int M = 0;
    
    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (i > 0 && wall[a[i][j]][0] && rooms[i][j] != rooms[i-1][j]) {
                int areaSum = area[rooms[i][j].first][rooms[i][j].second] + area[rooms[i-1][j].first][rooms[i-1][j].second];
                if (areaSum > M) {
                    ansX = i, ansY = j;
                    dir = "N";
                    M = areaSum;
                }
            }
            if (j < m-1 && wall[a[i][j]][3] && rooms[i][j] != rooms[i][j+1]) {
                int areaSum = area[rooms[i][j].first][rooms[i][j].second] + area[rooms[i][j+1].first][rooms[i][j+1].second];
                if (areaSum > M) {
                    ansX = i, ansY = j;
                    dir = "E";
                    M = areaSum;
                }
            }
        }
    }
    
    cout << M << "\n";
    cout << ansX+1 << " " << ansY+1 << " " << dir << "\n";
}