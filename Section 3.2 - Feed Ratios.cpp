/*
ID: 
TASK: ratios
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int x, y, z;
int a[3], b[3], c[3];

int DIV(int v, int d) {
    if (d == 0) {
        if (v == 0) return -2;
        return -1;
    }
    return v/d;
}

int check(int d, int e, int f) {
    if (DIV(d, x) == -1 || DIV(e, y) == -1 || DIV(f, z) == -1) return -1;
    if (DIV(d, x) == 0 || DIV(e, y) == 0 || DIV(f, z) == 0) return -1;
    int r;
    if (DIV(d, x) == -2) {
        if (DIV(e, y) == -2) {
            if (DIV(f, z) == -2) return 0;
            r = f/z;
            return ((z*r == f) ? r : -1);
        }
        r = e/y;
        return ((y*r == e && z*r == f) ? r : -1);
    }
    r = d/x;
    return ((x*r == d && y*r == e && z*r == f) ? r : -1);
}

int main() {
    ofstream cout("ratios.out");
    ifstream cin("ratios.in");
    
    cin >> x >> y >> z;
    for (int i = 0; i < 3; i++) cin >> a[i] >> b[i] >> c[i];
    
    int ans[] = {100, 100, 100, 100};
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                int d = a[0]*i + a[1]*j + a[2]*k;
                int e = b[0]*i + b[1]*j + b[2]*k;
                int f = c[0]*i + c[1]*j + c[2]*k;
                
                int r = check(d, e, f);
                if (r != -1) {
                    if (ans[0]+ans[1]+ans[2] > i+j+k) {
                        ans[0] = i; ans[1] = j; ans[2] = k;
                        ans[3] = r;
                    }
                }
                
            }
        }
    }
    
    if (ans[0] == 100) cout << "NONE\n";
    else {
        for (int i = 0; i < 3; i++) cout << ans[i] << " ";
        cout << ans[3] << "\n";
    }
}