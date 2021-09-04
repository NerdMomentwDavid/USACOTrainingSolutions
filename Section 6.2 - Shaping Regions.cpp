/*
ID:
TASK: rect1
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int a, b, n;

struct Rect {
    int x1, y1, x2, y2, c;
    int area() {
        return (x2-x1)*(y2-y1);
    }
};

Rect rect[1005];
int cnt[2505] = {0};
vector<Rect> o;

bool overlap(Rect r1, Rect r2) {
    if (r1.x1 >= r2.x2 || r1.x2 <= r2.x1 || r1.y1 >= r2.y2 || r1.y2 <= r2.y1) return 0;
    return 1;
}

int getArea(Rect &cur, int p) {
    while (p < o.size() && !overlap(cur, o[p])) p++;
    if (p == o.size()) return cur.area();
    Rect tmp;
    int tot = 0;
    if (o[p].x1 > cur.x1) {
        tmp = {cur.x1, cur.y1, o[p].x1, cur.y2, 0};
        tot += getArea(tmp, p+1);
        cur.x1 = o[p].x1;
    }
    if (o[p].x2 < cur.x2) {
        tmp = {o[p].x2, cur.y1, cur.x2, cur.y2, 0};
        tot += getArea(tmp, p+1);
        cur.x2 = o[p].x2;
    }
    if (o[p].y1 > cur.y1) {
        tmp = {cur.x1, cur.y1, cur.x2, o[p].y1, 0};
        tot += getArea(tmp, p+1);
        cur.y1 = o[p].y1;
    }
    if (o[p].y2 < cur.y2) {
        tmp = {cur.x1, o[p].y2, cur.x2, cur.y2, 0};
        tot += getArea(tmp, p+1);
        cur.y2 = o[p].y2;
    }
    return tot;
}

void calcArea(int ind) {
    Rect r = rect[ind];
    o.clear();
    for (int i = ind+1; i <= n; i++) {
        if (overlap(r, rect[i])) {
            int x1 = max(rect[i].x1, r.x1);
            int y1 = max(rect[i].y1, r.y1);
            int x2 = min(rect[i].x2, r.x2);
            int y2 = min(rect[i].y2, r.y2);
            o.pb({x1, y1, x2, y2, rect[i].c});
        }
    }
    
    int res = r.area();
    for (int i = 0; i < o.size(); i++) {
        int tmpa = getArea(o[i], i+1);
        res -= tmpa;
    }
    
    cnt[r.c] += res;
}

int main() {
    ofstream cout("rect1.out");
    ifstream cin("rect1.in");
    
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        rect[i] = {x1, y1, x2, y2, c};
    }
    
    rect[0] = {0, 0, a, b, 1};
    
    for (int i = n; i >= 0; i--) {
        calcArea(i);
    }
    
    for (int i = 1; i <= 2500; i++) {
        if (cnt[i]) cout << i << " " << cnt[i] << "\n";
    }
    
    return 0;
}
