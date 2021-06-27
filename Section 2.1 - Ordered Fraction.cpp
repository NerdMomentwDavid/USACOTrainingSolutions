/*
ID:
TASK: frac1
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

struct frac{
    int a;
    int b;
//  a/b
};

bool comp(frac f1, frac f2) {
    double a1 = f1.a, a2 = f2.a;
    double b1 = f1.b, b2 = f2.b;
    return (a1/b1 < a2/b2);
}

vector<frac> ans;

int main() {
    ofstream cout("frac1.out");
    ifstream cin("frac1.in");
    
    int n;
    cin >> n;
    ans.push_back({0, 1});
    ans.push_back({1, 1});
    for (int i = 2; i <= n; i++) {
        ans.push_back({1, i});
        for (int j = 2; j < i; j++) {
            bool f = 1;
            for (int k = 2; k <= j; k++) {
                if (j%k == 0 && i%k == 0) {
                    f = 0;
                    break;
                }
            }
            if (f) ans.push_back({j, i});
        }
    }
    
    sort(ans.begin(), ans.end(), comp);
    for (auto i : ans) {
        cout << i.a << "/" << i.b << "\n";
    }
}
