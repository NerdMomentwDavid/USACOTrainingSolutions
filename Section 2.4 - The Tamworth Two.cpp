/*
ID:
TASK: ttwo
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

char grid[10][10];
int fi, fj, ci, cj;
int fdir = 0, cdir = 0;
//  N E S W
//  0 1 2 3
int vis[10][10][10][10][4][4];

int search(int m) {
    if (fi == ci && fj == cj) return m;
    if (vis[fi][fj][ci][cj][fdir][cdir]) return 0;
    
    vis[fi][fj][ci][cj][fdir][cdir] = 1;
    
    if (fdir == 0) {
        if (fi == 0 || grid[fi-1][fj] == '*') fdir = 1;
        else fi--;
    } else if (fdir == 1) {
        if (fj == 9 || grid[fi][fj+1] == '*') fdir = 2;
        else fj++;
    } else if (fdir == 2) {
        if (fi == 9 || grid[fi+1][fj] == '*') fdir = 3;
        else fi++;
    } else {
        if (fj == 0 || grid[fi][fj-1] == '*') fdir = 0;
        else fj--;
    }
    
    if (cdir == 0) {
        if (ci == 0 || grid[ci-1][cj] == '*') cdir = 1;
        else ci--;
    } else if (cdir == 1) {
        if (cj == 9 || grid[ci][cj+1] == '*') cdir = 2;
        else cj++;
    } else if (cdir == 2) {
        if (ci == 9 || grid[ci+1][cj] == '*') cdir = 3;
        else ci++;
    } else {
        if (cj == 0 || grid[ci][cj-1] == '*') cdir = 0;
        else cj--;
    }
    
    return search(m+1);
}

int main() {
    ofstream cout("ttwo.out");
    ifstream cin("ttwo.in");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') {
                fi = i;
                fj = j;
                grid[i][j] = '.';
            } else if (grid[i][j] == 'C') {
                ci = i;
                cj = j;
                grid[i][j] = '.';
            }
        }
    }
    
    memset(vis, 0, sizeof(vis));
    cout << search(0) << "\n";
}
