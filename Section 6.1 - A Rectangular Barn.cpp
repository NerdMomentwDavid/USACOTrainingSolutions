/*
ID: 
TASK: rectbarn
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MEM(x, v) memset(x, v, sizeof(x));

bool a[3005][3005];
int r, c, p;

int getRect(vector<int> v) {
    v.pb(0);
    stack<int> st;
    int m = 0;
    for (int i = 0; i <= c; i++) {
        while (!st.empty() && v[st.top()] >= v[i]) {
            int ind = st.top(); st.pop();
            int w = i;
            if (!st.empty()) w = i - st.top() - 1;
            m = max(m, w*v[ind]);
        }
        st.push(i);
    }
    
    return m;
}

int main() {
    ofstream cout("rectbarn.out");
    ifstream cin("rectbarn.in");
    
    cin >> r >> c >> p;
    int x, y;
    MEM(a, 0);
    while (p--) {
        cin >> x >> y;
        a[x-1][y-1] = 1;
    }
    
    vector<int> v(c, 0);
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j]) v[j] = 0;
            else v[j]++;
        }
        ans = max(ans, getRect(v));
    }
    cout << ans << "\n";
    
    return 0;
}
