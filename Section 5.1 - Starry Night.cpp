/*
ID:
TASK: starry
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct Cood {
    int r, c;
};

bool comp(Cood a, Cood b) {
    if (a.r == b.r) return (a.c < b.c);
    return (a.r < b.r);
}

int w, h;
char a[100][100];
int x[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int y[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int cx[4] = {1, 1, -1, -1};
int cy[4] = {1, -1, 1, -1};

bool vis[100][100];
vector<Cood> v;
char cnt = 'a';

void dfs(int r, int c) {
    v.push_back({r, c});
    vis[r][c] = 1;
    for (int i = 0; i < 8; i++) {
        int tr = r+x[i], tc = c+y[i];
        if (tr >= 0 && tr < h && tc >= 0 && tc < w && !vis[tr][tc] && a[tr][tc] == '1') dfs(tr, tc);
    }
}

void dfs(int r, int c, char g) {
    a[r][c] = g;
    for (int i = 0; i < 8; i++) {
        int tr = r+x[i], tc = c+y[i];
        if (tr >= 0 && tr < h && tc >= 0 && tc < w && a[tr][tc] == '1') dfs(tr, tc, g);
    }
}

string convert(vector<Cood> co) {
    sort(co.begin(), co.end(), comp);
    string s = "";
    for (auto i : co) {
        s += to_string(i.r-co[0].r); s += " ";
        s += to_string(i.c-co[0].c); s += " ";
    }
    return s;
}

unordered_map<string, char> mp;
vector<Cood> tmp1, tmp2;

int main() {
    ofstream cout("starry.out");
    ifstream cin("starry.in");
    
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    
    string s;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '1') {
                memset(vis, 0, sizeof(vis));
                dfs(i, j);
                s = convert(v);
                if (mp.count(s)) {
                    dfs(i, j, mp[s]);
                } else {
                    dfs(i, j, cnt);
                    int l = v.size();
                    tmp1.resize(l); tmp2.resize(l);
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < l; j++) {
                            tmp1[j] = {v[j].r*cx[i], v[j].c*cy[i]};
                            tmp2[j] = {v[j].c*cx[i], v[j].r*cy[i]};
                        }
                        mp[convert(tmp1)] = cnt;
                        mp[convert(tmp2)] = cnt;
                    }
                    cnt++;
                }
                v.clear();
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}
