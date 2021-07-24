/*
ID:
TASK: msquare
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

// Original   A:         B:         C:
// 0 1 2 3    7 6 5 4    3 0 1 2    0 6 1 3
// 7 6 5 4    0 1 2 3    4 7 6 5    7 5 2 4
// Count in clockwise order

#define A(x) (_+x[7]+x[6]+x[5]+x[4]+x[3]+x[2]+x[1]+x[0])
#define B(x) (_+x[3]+x[0]+x[1]+x[2]+x[5]+x[6]+x[7]+x[4])
#define C(x) (_+x[0]+x[6]+x[1]+x[3]+x[4]+x[2]+x[5]+x[7])
string _;

unordered_map<string, bool> vis;
queue<tuple<string, string, int>> Q;

pair<int, string> search(string s) {
    Q.push({"12345678", "", 0});
    
    string u, a;
    int c;
    while(!Q.empty()) {
        tie(u, a, c) = Q.front();
        Q.pop();
        
        if (u == s) {
            return {c, a};
        }
        
        c++;
        string b;
        if (!vis[A(u)]) {
            b = a+'A';
            if (c%60 == 0) b += '\n';
            Q.push({A(u), b, c});
            vis[A(u)] = 1;
        }
        if (!vis[B(u)]) {
            b = a+'B';
            if (c%60 == 0) b += '\n';
            Q.push({B(u), b, c});
            vis[B(u)] = 1;
        }
        if (!vis[C(u)]) {
            b = a+'C';
            if (c%60 == 0) b += '\n';
            Q.push({C(u), b, c});
            vis[C(u)] = 1;
        }
    }
}

int main() {
    ofstream cout("msquare.out");
    ifstream cin("msquare.in");
    
    string s = "";
    char c;
    for (int i = 0; i < 8; i++) {
        cin >> c;
        s += c;
    }
    
    pair<int, string> ans = search(s);
    cout << ans.first << "\n" << ans.second << "\n";
}