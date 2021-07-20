/*
ID:
TASK: fact4
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

// last non-zero digits for factorials 0! to 9!
int base[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
//            0! 1! 2! 3! 4! 5! 6! 7! 8! 9!

int getLast(int x) {
    if (x < 10) return base[x];
    
    int tens = (x/10)%10;
    int ones = x%10;
    if (tens%2) return (4*getLast(x/5)*base[ones]) % 10;
    else return (6*getLast(x/5)*base[ones]) % 10;
}

int main() {
    ofstream cout("fact4.out");
    ifstream cin("fact4.in");
    
    int n;
    cin >> n;
    
    cout << getLast(n) << "\n";
}