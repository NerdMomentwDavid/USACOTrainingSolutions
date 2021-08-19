/*
ID: 
TASK: window
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct Window {
    int x, y, X, Y;
    int level;
    Window() {}
    Window(int a, int b, int c, int d, int e) : x(a), y(b), X(c), Y(d), level(e) {}

    double area() {
        return (X-x)*(Y-y);
    }
};

unordered_map<char, Window> win;
vector<Window> w;
int cnt = 0, btm = 0;

bool checkOverlap(Window a, Window b) {
    if (a.x >= b.X || a.X <= b.x || a.y >= b.Y || a.Y <= b.y) return 0;
    return 1;
}

double getArea(Window &cur, int ind) {
    while (ind < w.size() && !checkOverlap(cur, w[ind])) ind++;
    if (ind == w.size()) return cur.area();
    double a = 0;
    Window tmp;
    if (cur.x < w[ind].x) {
        tmp = Window(cur.x, cur.y, w[ind].x, cur.Y, 0);
        a += getArea(tmp, ind+1);
        cur.x = w[ind].x;
    }
    if (cur.X > w[ind].X) {
        tmp = Window(w[ind].X, cur.y, cur.X, cur.Y, 0);
        a += getArea(tmp, ind+1);
        cur.X = w[ind].X;
    }
    if (cur.y < w[ind].y) {
        tmp = Window(cur.x, cur.y, cur.X, w[ind].y, 0);
        a += getArea(tmp, ind+1);
        cur.y = w[ind].y;
    }
    if (cur.Y > w[ind].Y) {
        tmp = Window(cur.x, w[ind].Y, cur.X, cur.Y, 0);
        a += getArea(tmp, ind+1);
        cur.Y = w[ind].Y;
    }
    return a;
}

double getPercent(char I) {
    double totalArea = win[I].area();
    int lv = win[I].level;
    vector<Window> overlaps;
    for (auto i : win) {
        char J = i.first;
        if (win[J].level > lv) {
            if (checkOverlap(win[I], win[J])) {
                int x = max(win[I].x, win[J].x);
                int y = max(win[I].y, win[J].y);
                int X = min(win[I].X, win[J].X);
                int Y = min(win[I].Y, win[J].Y);
                overlaps.push_back(Window(x, y, X, Y, 0));
            }
        }
    }

    w = overlaps;
    double coverArea = 0;
    for (int i = 0; i < w.size(); i++) {
        coverArea += getArea(w[i], i+1);
    }
    return (1 - coverArea/totalArea)*100;
}

int main() {
    ofstream cout("window.out");
    ifstream cin("window.in");

    char t;
    char I;
    int x, y, X, Y;
    cout << fixed << setprecision(3);

    while (cin >> t) {
        if (t == 'w') {
            cin >> t >> I >> t >> x >> t >> y >> t >> X >> t >> Y >> t;
            cnt++;
            win[I] = Window(min(x, X), min(y, Y), max(x, X), max(y, Y), cnt);
        } else if (t == 't') {
            cin >> t >> I >> t;
            cnt++;
            win[I].level = cnt;
        } else if (t == 'b') {
            cin >> t >> I >> t;
            btm--;
            win[I].level = btm;
        } else if (t == 'd') {
            cin >> t >> I >> t;
            win.erase(I);
        } else {
            cin >> t >> I >> t;
            cout << getPercent(I) << "\n";
        }
    }
    return 0;
}
