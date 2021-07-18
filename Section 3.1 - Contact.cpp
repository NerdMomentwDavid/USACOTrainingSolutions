/*
ID: 
TASK: contact
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct binS{
    int freq, len, dec;
};

int cnt[13][(1<<12)+5];
vector<binS> ans;
int a, b, n, l;
string s = "";

bool comp(binS x, binS y) {
    if (x.freq == y.freq) {
        if (x.len == y.len) return (x.dec < y.dec);
        return (x.len < y.len);
    }
    return (x.freq > y.freq);
}

int main() {
    ofstream cout("contact.out");
    ifstream cin("contact.in");
    
    cin >> a >> b >> n;
    string tmp;
    while(cin >> tmp) {
        s += tmp;
    }
    l = s.size();
    s += "0";
    
    for (int i = 0; i <= l-a; i++) {
        int m = 0;
        for (int j = 0; j < a; j++) m = (m << 1) + (s[i+j]-'0');
        
        for (int j = a; j <= b && i+j <= l; j++) {
            cnt[j][m]++;
            m = (m << 1) + (s[i+j]-'0');
        }
    }
    
    
    for (int i = a; i <= b; i++) {
        int len = 1<<i;
        for (int j = 0; j < len; j++) {
            if (cnt[i][j] > 0) ans.push_back({cnt[i][j], i, j});
        }
    }
    
    sort(ans.begin(), ans.end(), comp);
    int c = 0, m = ans.size();
    
    for (int i = 0; i < n && c < m; i++) {
        cout << ans[c].freq << "\n";
        
        auto binary = bitset<12>(ans[c].dec);
        for (int i = ans[c].len-1; i >= 0; i--) cout << binary[i];
        
        c++;
        int t = 1;
        while(c < m && ans[c].freq == ans[c-1].freq) {
            if (t != 0) cout << " ";
            
            binary = bitset<12>(ans[c].dec);
            for (int i = ans[c].len-1; i >= 0; i--) cout << binary[i];
            
            c++;
            t++;
            if (t == 6) {
                cout << "\n";
                t = 0;
            }
        }
        if (t != 0) cout << "\n";
    }
}