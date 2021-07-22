/*
ID: 
TASK: spin
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int spd[5], wed[5], ang[5][5], ext[5][5];

bool check(int t) {
    int cnt[360];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < wed[i]; j++) {
            int a = (ang[i][j] + t*spd[i])%360;
            int m = (a + ext[i][j])%360;
            
            for (int k = a; k != m; k = (k+1)%360) {
                cnt[k]++;
            }
            cnt[m]++;
        }
    }
    
    for (int i = 0; i < 360; i++) {
        if (cnt[i] >= 5) return 1;
    }
    return 0;
}

int main() {
    ofstream cout("spin.out");
    ifstream cin("spin.in");
    
    for (int i = 0; i < 5; i++) {
        cin >> spd[i] >> wed[i];
        for (int j = 0; j < wed[i]; j++) {
            cin >> ang[i][j] >> ext[i][j];
        }
    }
    
    int ans;
    for (ans = 0; ans < 360 && !check(ans); ans++) {}
    
    if (ans == 360) cout << "none\n";
    else cout << ans << "\n";
    return 0;
}