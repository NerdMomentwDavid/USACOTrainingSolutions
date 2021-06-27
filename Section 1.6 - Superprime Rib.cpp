/*
ID:
TASK: sprime
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;
    
    for (int i = 2; i*i <= n; i++) {
        if (!(n%i)) return 0;
    }
    
    return 1;
}

set<int> ans;
int N;

void generate(int x, int c) {
    //cout << c << ", " << x << "\n";
    if (!check(x/pow(10, c))) return;
    
    if (c == 0) {
        ans.insert(x);
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        generate(x+i*pow(10,c-1), c-1);
    }
}

int main() {
    ofstream cout("sprime.out");
    ifstream cin("sprime.in");
    
    cin >> N;
    generate(2*pow(10, N-1), N-1);
    generate(3*pow(10, N-1), N-1);
    generate(5*pow(10, N-1), N-1);
    generate(7*pow(10, N-1), N-1);
    
    for (auto a : ans) {
        cout << a << "\n";
    }
}
