/*
ID: 
TASK: subset
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[1000];
int n;

int main() {
    ofstream cout("subset.out");
    ifstream cin("subset.in");
    
    memset(dp, 0, sizeof(dp));
    cin >> n;
    dp[0] = 1;
    int sum = n*(n+1)/2;
    
    if (sum%2) cout << "0\n";
    else {
        sum /= 2;
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= i; j--) {
                dp[j] += dp[j-i];
            }
        }
        cout << dp[sum]/2 << "\n";
    }
}