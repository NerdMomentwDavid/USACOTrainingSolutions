/*
ID:
TASK: maze1
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

string grid[205];
int dist[205][80];
int w, h;

void dfs(int i, int j, int c) {
    if (i<0 || j<0 || i>2*h || j>2*w || (dist[i][j] && c >= dist[i][j])) return;
    
    if (dist[i][j] == 0 || c < dist[i][j]) dist[i][j] = c;
    if (grid[i-1][j] == ' ') dfs(i-2, j, c+1);
    if (grid[i][j-1] == ' ') dfs(i, j-2, c+1);
    if (grid[i+1][j] == ' ') dfs(i+2, j, c+1);
    if (grid[i][j+1] == ' ') dfs(i, j+2, c+1);
}

int main() {
    ofstream cout("maze1.out");
    ifstream cin("maze1.in");
    
    cin >> w >> h;
    getline(cin, grid[0]);
    for (int i = 0; i < 2*h+1; i++) {
        getline(cin, grid[i]);
    }
    
    int ei[2], ej[2];
    int c = 0;
    for (int i = 1; i < h*2; i+=2) {
        if (grid[i][0] == ' ') {
            ei[c] = i, ej[c] = 1;
            c++;
        }
        if (grid[i][2*w] == ' ') {
            ei[c] = i, ej[c] = 2*w-1;
            c++;
        }
    }
    for (int j = 1; j < w*2; j+=2) {
        if (grid[0][j] == ' ') {
            ei[c] = 1, ej[c] = j;
            c++;
        }
        if (grid[2*h][j] == ' ') {
            ei[c] = 2*h-1, ej[c] = j;
            c++;
        }
    }
    
    dfs(ei[0], ej[0], 1);
    dfs(ei[1], ej[1], 1);
    
    int ans = 0;
    for (int i = 1; i < 2*h+1; i+= 2) {
        for (int j = 1; j < 2*w+1; j+= 2) {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << "\n";
}