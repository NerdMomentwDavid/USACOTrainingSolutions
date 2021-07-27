/*
ID: 
TASK: shopping
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

struct Item {
    int id;
    int a;
};

struct Offer {
    int n;
    Item item[5];
    int c;
};

int s;
Offer ofr[110];
int b;
int ans[6][6][6][6][6];
int itm[1000];
int ID[1000];
int t = 0;

int main() {
    ofstream cout("shopping.out");
    ifstream cin("shopping.in");
    
    memset(ans, INF, sizeof(ans));
    memset(ID, -1, sizeof(ID));
    
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> ofr[i].n;
        for (int j = 0, x, y; j < ofr[i].n; j++) {
            cin >> x >> y;
            if (ID[x] == -1) {
                ID[x] = t;
                t++;
            }
            ofr[i].item[ID[x]].id = x;
            ofr[i].item[ID[x]].a = y;
        }
        cin >> ofr[i].c;
    }
    cin >> b;
    
    int r[5] = {0, 0, 0, 0, 0};
    for (int i = s, x; i < s+b; i++) {
        ofr[i].n = 1;
        cin >> x;
        if (ID[x] == -1) {
            ID[x] = t;
            t++;
        }
        cin >> r[ID[x]] >> ofr[i].c;
        ofr[i].item[ID[x]].id = x;
        ofr[i].item[ID[x]].a = 1;
    }
    s += b;
    
    ans[0][0][0][0][0] = 0;
    for (int i = 0; i < s; i++) {
        int k[5] = {0, 0, 0, 0, 0};
        for (int j = 0; j < 5; j++) {
            k[j] = ofr[i].item[j].a;
        }
        
        for (int a = k[0]; a <= r[0]; a++) {
            for (int b = k[1]; b <= r[1]; b++) {
                for (int c = k[2]; c <= r[2]; c++) {
                    for (int d = k[3]; d <= r[3]; d++) {
                        for (int e = k[4]; e <= r[4]; e++) {
                            ans[a][b][c][d][e] = min(ans[a][b][c][d][e], ans[a-k[0]][b-k[1]][c-k[2]][d-k[3]][e-k[4]] + ofr[i].c);
                        }
                    }
                }
            }
        }
    }
    
    cout << ans[r[0]][r[1]][r[2]][r[3]][r[4]] << "\n";
}