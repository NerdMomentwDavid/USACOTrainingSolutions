/*
ID: 
TASK: calfflac
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream cout("calfflac.out");
    ifstream cin("calfflac.in");
    
    string s, t;
    while (getline(cin, t)) s += t+'\n';

    int n = s.size();
    int mx = 1, st = 0, len = 1;
    for (int i = 0; i < n; i++) {
        if (tolower(s[i]) < 'a' || tolower(s[i]) > 'z') continue;
        int l = i-1, r = i+1;
        int c = 1;
        int pre = 0;
        int tmp = 1;
        while (l >= 0 && r < n) {
            char a = tolower(s[l]), b = tolower(s[r]);
            if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
                if (a == b) {
                    c += 2;
                    pre = l;
                    tmp = r;
                    l--; r++;
                } else break;
            } else {
                if (a < 'a' || a > 'z') l--;
                if (b < 'a' || b > 'z') r++;
            }
        }
        if (c > mx) {
            mx = c;
            st = pre;
            len = tmp-pre+1;
        }
        l = i;
        r = i+1;
        c = 0;
        pre = 0;
        tmp = 1;
        while (l >= 0 && r < n) {
            char a = tolower(s[l]), b = tolower(s[r]);
            if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
                if (a == b) {
                    c += 2;
                    pre = l;
                    tmp = r;
                    l--; r++;
                } else break;
            } else {
                if (a < 'a' || a > 'z') l--;
                if (b < 'a' || b > 'z') r++;
            }
        }
        if (c > mx) {
            mx = c;
            st = pre;
            len = tmp-pre+1;
        }
    }
    
    cout << mx << "\n" << s.substr(st, len) << "\n";
}
