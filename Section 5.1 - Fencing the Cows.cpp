/*
ID:
TASK: fc
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x = 0, y = 0, z = 0;
};

struct Vec {
    double x, y, z;
    Vec(double a, double b, double c) : x(a), y(b), z(c) {}
    Vec(Point a, Point b) {
        x = a.x-b.x;
        y = a.y-b.y;
        z = a.z-b.z;
    }
    
    double length() {
        double i = x*x;
        double j = y*y;
        double k = z*z;
        return sqrt(i+j+k);
    }
};

Vec crossProduct (Vec u, Vec v) {
    double i = u.y*v.z - u.z*v.y;
    double j = u.z*v.x - u.x*v.z;
    double k = u.x*v.y - u.y*v.x;
    return Vec(i, j, k);
}

Point p[10005];
int n;
vector<pair<double, int>> sp;
vector<Point> ans;

int main() {
    ofstream cout("fc.out");
    ifstream cin("fc.in");
    
    cin >> n;
    int s;
    double my = 1e6+5, mx = 1e6+5;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        if (p[i].y < my) {
            my = p[i].y;
            mx = p[i].x;
            s = i;
        } else if (p[i].y == my && p[i].x < mx) {
            mx = p[i].x;
            s = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        double dx = p[i].x-p[s].x;
        double dy = p[i].y-p[s].y;
        sp.push_back({atan2(dy, dx), i});
    }
    
    sort(sp.begin(), sp.end());
    
    ans.push_back(p[s]);
    ans.push_back(p[sp[0].second]);
    sp.push_back({0, s});
    for (int i = 1; i < sp.size(); i++) {
        Point t = p[sp[i].second];
        int l = ans.size();
        Vec mult = crossProduct(Vec(ans[l-2], ans[l-1]), Vec(ans[l-1], t));
        while (mult.z <= 0 && ans.size() > 1) {
            ans.pop_back();
            l--;
            mult = crossProduct(Vec(ans[l-2], ans[l-1]), Vec(ans[l-1], t));
        }
        ans.push_back(t);
    }
    
    double cnt = 0;
    Vec tmp(0, 0, 0);
    for (int i = 1; i < ans.size()-1; i++) {
        tmp = Vec(ans[i], ans[i-1]);
        cnt += tmp.length();
    }
    tmp = Vec(ans[0], ans[ans.size()-2]);
    cnt += tmp.length();
    cout << fixed << setprecision(2) << cnt << "\n";
}
