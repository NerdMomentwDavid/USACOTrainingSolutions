/*
ID: 
TASK: fracdec
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int vis[1000005];
string ans = "";
int a, b, n;

int main() {
    ofstream cout("fracdec.out");
    ifstream cin("fracdec.in");
    
    memset(vis, -1, sizeof(vis));
    
    cin >> a >> b;
    ans += to_string(a/b);
    ans += ".";
    
    n = ans.size();
    if (a%b == 0) {
        ans += "0";
        n++;
    }
    
    int x = a%b*10;
    while (x != 0) {
        if (vis[x] > -1) {
            ans.insert(vis[x], "(");
            ans += ")";
            n+=2;
            break;
        }
        vis[x] = n;
        ans += (x/b)+'0';
        x = x%b*10;
        n++;
    }
    
    int i = 0;
    while(i < n) {
        for (int j = 0; j < 76 && i < n; j++, i++) cout << ans[i];
        cout << '\n';
    }
}
