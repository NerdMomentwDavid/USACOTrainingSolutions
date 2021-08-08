/*
ID:
TASK: buylow
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct BigNum {
    int sz;
    int dig[100];
    BigNum() {
        sz = 1;
        memset(dig, 0, sizeof(dig));
    }
    BigNum(int s) {
        sz = 1;
        memset(dig, 0, sizeof(dig));
        dig[0] = s;
    }
};

void add(BigNum& a, BigNum b) {
    BigNum sum;
    int inc = 0;
    int len = max(a.sz, b.sz);
    for (int i = 0; i < len; i++) {
        int tmp = a.dig[i]+b.dig[i]+inc;
        if (tmp >= 10) {
            sum.dig[i] = tmp-10;
            inc = 1;
        } else {
            inc = 0;
            sum.dig[i] = tmp;
        }
    }
    sum.sz = len;
    if (inc) {
        sum.dig[len] = 1;
        sum.sz++;
    }
    a = sum;
}

int price[5005];
int dp[5005];
BigNum ans;
int len = 0;
BigNum cnt[5005];
int n;
unordered_map<int, bool> vis;

int main() {
    ofstream cout("buylow.out");
    ifstream cin("buylow.in");
    cin >> n;
    for (int i = 0; i < n; i++) cin >> price[i];
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (price[j] > price[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        len = max(len, dp[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == 1) {
            cnt[i] = BigNum(1);
        } else {
            vis.clear();
            for (int j = i-1; j >= 0; j--) {
                if (vis.count(price[j])) continue;
                if (price[j] > price[i] && dp[i] == dp[j]+1) {
                    vis[price[j]] = 1;
                    add(cnt[i], cnt[j]);
                }
            }
        }
    }
    
    vis.clear();
    int prev = -1;
    for (int i = n-1; i >= 0; i--) {
        if (vis.count(price[i])) continue;
        if (dp[i] == len) {
            vis[price[i]] = 1;
            add(ans, cnt[i]);
        }
    }
    
    cout << len << " ";
    for (int i = ans.sz-1; i >= 0; i--) {
        cout << ans.dig[i];
    }
    cout << "\n";
}
