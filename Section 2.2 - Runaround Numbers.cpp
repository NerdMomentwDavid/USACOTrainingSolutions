/*
ID:
TASK: runround
LANG: C++14
*/

#include <bits/stdc++.h>

#define moveRight(x) (x+1 == l) ? 0 : (x+1)

using namespace std;

bool check(string m) {
    int l = m.size();
    bool digit[10];
    memset(digit, 0, sizeof(digit));
    int c = 0;
    int p = 0;
    while (1) {
        int a = m[p]-'0';
        if (digit[a]) return (c == l && p == 0) ? 1 : 0;
        digit[a] = 1;
        for (int i = 0; i < a; i++) {
            p = moveRight(p);
        }
        c++;
    }
}

int main() {
    ofstream cout("runround.out");
    ifstream cin("runround.in");
    
    unsigned long m;
    cin >> m;
    m++;
    while(!check(to_string(m))) m++;
    cout << m << "\n";
}
