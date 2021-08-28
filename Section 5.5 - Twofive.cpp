/*
ID:
TASK: twofive
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

int dp[6][6][6][6][6];
string tmp(25, ' ');
int a[6];

int countPos(char l) {
    if (dp[a[1]][a[2]][a[3]][a[4]][a[5]]) return dp[a[1]][a[2]][a[3]][a[4]][a[5]];
    int cnt = 0;
    for (int i = 1; i <= 5; i++) {
        if (a[i] < a[i-1]) {
            if (tmp[a[i]+((i-1)*5)] == ' ' || tmp[a[i]+((i-1)*5)] == l) {
                a[i]++;
                cnt += countPos(l+1);
                a[i]--;
            }
        }
    }
    dp[a[1]][a[2]][a[3]][a[4]][a[5]] = cnt;
    return cnt;
}

int main() {
    ofstream cout("twofive.out");
    ifstream cin("twofive.in");
    
    char c;
    cin >> c;
    if (c == 'W') {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < 25; i++) {
            for (char ch = 'A'; ch < s[i]; ch++) {
                tmp[i] = ch;
                MEM(a, 0);
                a[0] = 5;
                MEM(dp, 0);
                dp[5][5][5][5][5] = 1;
                ans += countPos('A');
            }
            tmp[i] = s[i];
        }
        cout << ans+1 << "\n";
    } else {
        int x;
        cin >> x;
        int t = 0;
        for (int i = 0; i < 25; i++) {
            for (char ch = 'A'; ch <= 'Y'; ch++) {
                tmp[i] = ch;
                MEM(a, 0);
                a[0] = 5;
                MEM(dp, 0);
                dp[5][5][5][5][5] = 1;
                int y = countPos('A');
                if (t + y < x) t += y;
                else break;
            }
        }
        cout << tmp << "\n";
    }
    
    return 0;
}
