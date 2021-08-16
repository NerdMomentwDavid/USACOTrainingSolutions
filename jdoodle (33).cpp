/*
ID: davidwa11
TASK: theme
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int a[5005], dif[5005];
vector<int> dp, tmp;
int n;

int main() {
    ofstream cout("theme.out");
    ifstream cin("theme.in");
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp.resize(n+1, 0); tmp.resize(n+1);
    
    int st = 40;
    
    /*for (int i = st; i <= n; i++) {
        cout << i << "  ";
        if (i < 10) cout << " ";
    }
    cout << "\n";
    for (int i = st; i <= n; i++) {
        cout << a[i] << "  ";
        if (a[i] < 10) cout << " ";
    }
    cout << "\n";*/
    
    dif[1] = 99;
    for (int i = 1; i <= n; i++) {
        dif[i] = a[i]-a[i-1];
    }
    
    /*for (int i = st; i <= n; i++) {
        if (i > st && dif[i] >= 0) cout << " ";
        cout << dif[i] << " ";
        if (abs(dif[i]) < 10) cout << " ";
    }
    cout << "\n";*/
    
    int m = 0;
    for (int i = 1; i <= n; i++) {
        fill(tmp.begin(), tmp.end(), 0);
        for (int j = i+1; j <= n; j++) {
            if (dif[i] == dif[j] && dp[j-1] < (j-i)) {
                //if (i >= 50 && i <= 59) cout << j << " - " << i << " : " << dp[j-1]+1 << "\n";
                tmp[j] = dp[j-1]+1;
                int t = tmp[j];
                if (tmp[j] < (j-i) && tmp[j] < i) t++;
                m = max(m, t);
            }
        }
        dp = tmp;
    }
    if (m < 5) cout << "0\n";
    else cout << m << "\n";
}