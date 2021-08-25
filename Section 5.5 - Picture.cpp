/*
ID:
TASK: picture
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

struct HLine {
    int y, x1, x2, l;
};

struct VLine {
    int x, y1, y2, l;
};

bool compH(HLine a, HLine b) {
    if (a.y == b.y) {
        return a.l < b.l;
    }
    return a.y < b.y;
}

bool compV(VLine a, VLine b) {
    if (a.x == b.x) {
        return a.l < b.l;
    }
    return a.x < b.x;
}

vector<HLine> h;
vector<VLine> v;
int n;
int cnt[200005];

int main() {
    ofstream cout("picture.out");
    ifstream cin("picture.in");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        h.push_back({y1, x1, x2, 0});
        h.push_back({y2, x1, x2, 1});
        v.push_back({x1, y1, y2, 0});
        v.push_back({x2, y1, y2, 1});
    }
    
    sort(h.begin(), h.end(), compH);
    sort(v.begin(), v.end(), compV);
    
    int ans = 0;
    MEM(cnt, 0);
    for (HLine s : h) {
        int d = 1;
        if (s.l) d = -1;
        for (int i = s.x1+100000; i < s.x2+100000; i++) {
            if (cnt[i] == s.l) ans++;
            cnt[i] += d;
        }
    }
    
    MEM(cnt, 0);
    for (VLine s : v) {
        int d = 1;
        if (s.l) d = -1;
        
        for (int i = s.y1+100000; i < s.y2+100000; i++) {
            if (cnt[i] == s.l) ans++;
            cnt[i] += d;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}

