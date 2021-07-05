/*
ID:
TASK: prefix
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

string pr[201];
string s;
bool vis[200001];
int n = 0;

int main() {
    ofstream cout("prefix.out");
    ifstream cin("prefix.in");
    
    cin >> pr[0];
    while (pr[n] != ".") {
        n++;
        cin >> pr[n];
    }
    string tmp;
    while(cin >> tmp) {
        s += tmp;
    }
    
    int l = s.size();
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    
    vis[0] = 1;
    
    for (int i = 0; i <= l; i++) {
        if (vis[i]) {
            ans = i;
            for (int j = 0; j < n; j++) {
                int k = 0;
                while (k < l-i && pr[j][k] && pr[j][k] == s[i+k]) k++;
                if (!pr[j][k]) vis[i+k] = 1;
            }
        }
    }
    
    cout << ans << "\n";
}