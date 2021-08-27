/*
ID:
TASK: hidden
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

int a[200005];

int main() {
    ofstream cout("hidden.out");
    ifstream cin("hidden.in");
    
    int n;
    string s = "", t;
    cin >> n;
    while (cin >> t) {
        s += t;
    }
    s += s;
    n *= 2;
    MEM(a, -1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int p = a[i-ans-1];
        while (p != -1 && s[i] != s[ans+p+1]) {
            if (s[i] < s[ans+p+1]) {
                ans = i - p - 1;
            }
            p = a[p];
        }
        if (p == -1 && s[i] != s[ans]) {
            if (s[i] < s[ans]) {
                ans = i;
            }
            a[i-ans] = -1;
        } else {
            a[i-ans] = p+1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}

