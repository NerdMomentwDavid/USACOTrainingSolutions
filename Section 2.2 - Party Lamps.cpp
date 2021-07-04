/*
ID:
TASK: lamps
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

bitset<101> on, off;
vector<bitset<101>> ans;
int n, c;

bool check(bitset<101> l) {
    for (int i = 1; i <= n; i++) {
        if (l[i] && off[i]) return 0;
        if (!l[i] && on[i]) return 0;
    }
    return 1;
}

void search(bitset<101> l, int k, int pre) {
    if (k == c) {
        if (check(l)) ans.push_back(l);
        return;
    }
    
    bitset<101> tmp1 = l;
    bitset<101> tmp2 = l;
    bitset<101> tmp3 = l;
    
    l.flip();
    if (pre == 1) search(l, k+1, 1);
    for (int i = 1; i <= n; i++) {
        if (i%2) {
            tmp1[i] = ~tmp1[i];
        } else {
            tmp2[i] = ~tmp2[i];
        }
    }
    
    for (int i = 1; i <= n; i+=3) {
        tmp3[i] = ~tmp3[i];
    }
    
    if (pre <= 2) search(tmp1, k+1, 2);
    if (pre <= 3) search(tmp2, k+1, 3);
    search(tmp3, k+1, 4);
}

bool comp(bitset<101> a, bitset<101> b) {
    for (int i = 1; i <= n; i++) if (a[i] != b[i]) return a[i]<b[i];
    return 0;
}

int main() {
    ofstream cout("lamps.out");
    ifstream cin("lamps.in");
    
    cin >> n >> c;
    int t;
    cin >> t;
    while(t != -1) {
        on[t] = 1;
        cin >> t;
    }
    cin >> t;
    while(t != -1) {
        off[t] = 1;
        cin >> t;
    }
    if (c > 4) {
        if (c%2) c = 3;
        else c = 4;
    }
    
    bitset<101> light;
    light.set();
    search(light, 0, 1);
    sort(ans.begin(), ans.end(), comp);
    for (int k = 0; k < ans.size(); k++) {
        if (k > 0 && ans[k] == ans[k-1]) continue;
        bitset<101> i = ans[k];
        for (int j = 1; j <= n; j++) {
            cout << i[j];
        }
        cout << "\n";
    }
    
    if (ans.empty()) cout << "IMPOSSIBLE\n";
}
