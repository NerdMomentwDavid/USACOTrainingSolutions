/*
ID: 
TASK: fence8
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

int original_board[50];
int board[50];
int rail[129] = {0};
int cnt[129];
int n, m;
int sum, mx;

bool check(int cur, int p, int waste) {
    if (waste > mx) return 0;
    if (p == n) return 1;
    
    for (int i = cur; i >= 1; i--) {
        if (cnt[i] && i <= board[p]) {
            cnt[i]--;
            board[p] -= i;
            if (check(i, p, waste)) return 1;
            board[p] += i;
            cnt[i]++;
        }
    }
    
    return check(128, p+1, waste+board[p]);
}

void reset() {
    for (int i = 0; i < n; i++) board[i] = original_board[i];
    MEM(cnt, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ofstream cout("fence8.out");
    ifstream cin("fence8.in");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> original_board[i];
        sum += original_board[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        rail[x]++;
    }
    
    sort(original_board, original_board+n);
    
    int l = 0, r = m;
    while (l < r) {
        int mid = (l+r+1)/2;
        reset();
        int c = 0;
        int tmp = 0;
        for (int i = 1; i <= 128 && c < mid; i++) {
            cnt[i] += min(rail[i], mid-c);
            tmp += min(rail[i], mid-c)*i;
            c += rail[i];
        }
        
        mx = sum-tmp;
        
        if (check(128, 0, 0)) l = mid;
        else r = mid-1;
    }
    
    cout << l << "\n";
    
    return 0;
}
