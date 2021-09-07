/*
ID:
TASK: cryptcow
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

typedef long long ll;

unordered_map<ll, bool> vis;
hash<string> hs;
string o = "Begin the Escape execution at the Break of Dawn";
unordered_map<char, int> cntO, cntS;
int tot;

bool check(string s) {
    // Checking prefix
    int l = min(sz(s), sz(o));
    for (int i = 0; i < l; i++) {
        if (s[i] == 'C') break;
        if (s[i] != o[i]) {
            return 0;
        }
    }
    
    // Checking suffix
    l = sz(s);
    int t = sz(o)-1;
    for (int i = l-1; i >= 0; i--) {
        if (s[i] == 'W') break;
        if (s[i] != o[t]) {
            return 0;
        }
        t--;
    }
    
    // Checking middle
    t = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'C' || s[i] == 'O' || s[i] == 'W') {
            string tmp = s.substr(t, i-t);
            if (o.find(tmp) == string::npos) {
                return 0;
            }
            t = i+1;
        }
    }
    
    return 1;
}

bool search(string s, int cnt) {
    if (cnt == tot) return s == o;
    
    int l = sz(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'C') {
            for (int j = i+1; j < l; j++) {
                if (s[j] == 'O') {
                    for (int k = j+1; k < l; k++) {
                        if (s[k] == 'W') {
                            string tmp = s.substr(0, i) + s.substr(j+1, k-j-1) + s.substr(i+1, j-i-1) + s.substr(k+1, l-k-1);
                            
                            if (check(tmp)) {
                                ll x = hs(tmp);
                                if (vis[x]) continue;
                                vis[x] = 1;
                                bool res = search(tmp, cnt+1);
                                if (res) return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

int main() {
    ofstream cout("cryptcow.out");
    ifstream cin("cryptcow.in");
    
    string s;
    getline(cin, s);
    pair<bool, int> ans;
    
    for (char ch : o) cntO[ch]++;
    for (char ch : s) cntS[ch]++;
    bool f = 1;
    for (char ch : o) {
        if (cntO[ch] != cntS[ch]) {
            f = 0;
            break;
        }
    }
    if (cntS['C'] != cntS['O'] || cntS['C'] != cntS['W'] || cntS['O'] != cntS['W']) f = 0;
    tot = (sz(s)-sz(o))/3;
    
    if (f == 0) ans = {0, 0};
    else ans = {search(s, 0), tot};
    
    if (!ans.first) ans.second = 0;
    cout << ans.first << " " << ans.second << "\n";
    
    return 0;
}
