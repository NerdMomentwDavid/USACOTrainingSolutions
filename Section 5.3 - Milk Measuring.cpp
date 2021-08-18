/*
ID:
TASK: milk4
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

bool dp[200005];
vector<int> ans;
int q, p;
int pail[100005];

bool dfs(int l, int ind) {
    if (ans.size() == l) {
        memset(dp, 0, sizeof(dp));
        dp[ans[0]] = 1;
        for (int i = ans[0]; i < q; i++) {
            if (dp[i]) {
                for (auto j : ans) {
                    if (i+j < 200005) {
                        dp[i+j] = 1;
                    }
                }
            }
        }
        return dp[q];
    }
    
    if (ind == p) return 0;
    
    ans.push_back(pail[ind]);
    if (dfs(l, ind+1)) return 1;
    ans.pop_back();
    return dfs(l, ind+1);
}

int main() {
    ofstream cout("milk4.out");
    ifstream cin("milk4.in");
    
    cin >> q >> p;
    for (int i = 0; i < p; i++) {
        cin >> pail[i];
    }
    sort(pail, pail+p);
    
    for (int i = 1; i <= p; i++) {
        ans.clear();
        if (dfs(i, 0)) {
            cout << i << " ";
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << " \n"[j==(ans.size()-1)];
            }
            break;
        }
    }
}
