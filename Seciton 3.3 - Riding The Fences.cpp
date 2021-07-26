/*
ID: 
TASK: fence
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> g[505];
int f;
vector<int> ans;

void euler(int u) {
    while(g[u].size()) {
        int v = g[u].back();
        g[u].pop_back();
        g[v].erase(find(g[v].begin(), g[v].end(), u));
        euler(v);
    }
    ans.push_back(u);
}

int main() {
    ofstream cout("fence.out");
    ifstream cin("fence.in");
    
    cin >> f;
    for (int i = 0, u, v; i < f; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= 500; i++) {
        sort(g[i].begin(), g[i].end(), greater<int>());
    }
    
    for (int i = 1; i <= 500; i++) {
        if (g[i].size()%2 == 1) {
            euler(i);
            break;
        }
    }
    
    if (ans.size() == 0) {
        for (int i = 1; i <= 500; i++) {
            if (g[i].size()) {
                euler(i);
                break;
            }
        }
    }
    
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
}