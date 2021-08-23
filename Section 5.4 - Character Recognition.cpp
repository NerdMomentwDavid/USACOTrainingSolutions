/*
ID: 
TASK: charrec
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x))
#define INF 0x3f3f3f3f

int font[545];
int rec[1205];
int n, m;
bitset<20> bin;
int dif[1205][545];
int mn[1205];
int skip[1205];
char pc[1205];

string ch = " abcdefghijklmnopqrstuvwxyz";

int getDiff(int a, int b) {
    return __builtin_popcount(a^b);
}

int main() {
    ifstream fin("font.in");
    fin >> m;
    for (int i = 0; i < m; i++) {
        fin >> bin;
        font[i] = (int)bin.to_ulong();
    }
    fin.close();
    
    ofstream cout("charrec.out");
    ifstream cin("charrec.in");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bin;
        rec[i] = (int)bin.to_ulong();
        for (int j = 0; j < m; j++) {
            dif[i][j] = getDiff(rec[i], font[j]);
        }
    }

    MEM(mn, INF);
    string ans = "";
    mn[0] = 0;
    for (int i = 0; i <= n-19; i++) {
        if (i+19 <= n) {
            for (int j = 0; j < m; j+=20) {
                for (int k = 0; k < 20; k++) {
                    int c = 0, x = 0;
                    for (int l = 0; l < 20; l++) {
                        if (l == k) continue;
                        c += dif[i+x][j+l];
                        x++;
                    }
                    if (c+mn[i] < mn[i+19]) {
                        mn[i+19] = c+mn[i];
                        skip[i+19] = 19;
                        pc[i+19] = ch[j/20];
                    }
                }
            }
        }
        if (i+20 <= n) {
            for (int j = 0; j < m; j+=20) {
                int c = 0;
                for (int k = 0; k < 20; k++) {
                    c += dif[i+k][j+k];
                }
                if (c+mn[i] < mn[i+20]) {
                    mn[i+20] = c+mn[i];
                    skip[i+20] = 20;
                    pc[i+20] = ch[j/20];
                }
            }
        }
        if (i+21 <= n) {
            for (int j = 0; j < m; j+=20) {
                for (int k = 0; k < 20; k++) {
                    int c = 0, y = 0;
                    for (int l = 0; l < 20; l++) {
                        if (l == k) y++;
                        c += dif[i+y][j+l];
                        y++;
                    }
                    if (c+mn[i] < mn[i+21]) {
                        mn[i+21] = c+mn[i];
                        skip[i+21] = 21;
                        pc[i+21] = ch[j/20];
                    }
                }
            }
        }
    }

    for (int i = n; i > 0; i-=skip[i]) {
        ans = pc[i]+ans;
    }
    cout << ans << "\n";

    return 0;
}

