/*
ID:
TASK: job
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int t[2][2][30];
int wait[1000];
int n, m[2];

int getMin(int mach) {
    int ind = -1;
    int mn = INT_MAX;
    for (int i = 0; i < m[mach]; i++) {
        if (t[mach][0][i]+t[mach][1][i] < mn) {
            mn = t[mach][0][i]+t[mach][1][i];
            ind = i;
        }
    }
    t[mach][1][ind] = mn;
    return mn;
}

int main() {
    ofstream cout("job.out");
    ifstream cin("job.in");
    
    cin >> n >> m[0] >> m[1];
    for (int i = 0; i < m[0]; i++) {
        cin >> t[0][0][i];
        t[0][1][i] = 0;
    }
    for (int i = 0; i < m[1]; i++) {
        cin >> t[1][0][i];
        t[1][1][i] = 0;
    }
    
    for (int i = 0; i < n; i++) wait[i] = getMin(0);
    
    int ans = 0;
    for (int i = n-1; i >= 0; i--) ans = max(ans, wait[i]+getMin(1));
    
    cout << wait[n-1] << " " << ans << "\n";
}
