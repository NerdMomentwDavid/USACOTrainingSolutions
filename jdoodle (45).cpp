/*
ID:
TASK: holstein
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int V, G;
int v[25], g[15][25];
vector<int> ans;
int M = 1000;
int tmp[25];

void Add(int ind) {
    for (int i = 0; i < V; i++) {
        tmp[i] += g[ind][i];
    }
}

void Remove(int ind) {
    for (int i = 0; i < V; i++) {
        tmp[i] -= g[ind][i];
    }
}

bool Check() {
    for (int i = 0; i < V; i++) {
        if (tmp[i] < v[i]) return 0;
    }
    
    return 1;
}

void search(vector<int> t, int c, int p) {
    if (c >= M) return;
    if (p == G) {
        if (Check()) {
            ans = t;
            M = c;
        }
        return;
    }
    Add(p);
    t.push_back(p);
    search(t, c+1, p+1);
    Remove(p);
    t.pop_back();
    search(t, c, p+1);
}

int main() {
    ofstream cout("holstein.out");
    ifstream cin("holstein.in");
    
    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> v[i];
        tmp[i] = 0;
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < V; j++) {
            cin >> g[i][j];
        }
    }
    
    search({}, 0, 0);
    
    cout << M;
    for (auto i : ans) {
        cout << " " << i+1;
    }
    cout << "\n";
}