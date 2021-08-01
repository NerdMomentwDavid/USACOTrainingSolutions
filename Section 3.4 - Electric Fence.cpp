/*
ID: 
TASK: fence9
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream cout("fence9.out");
    ifstream cin("fence9.in");
    
    double n, m, p;
    cin >> n >> m >> p;
    // Pick's Formula: Area = Points inside triangle + (Points on the sides / 2) - 1
    // Rearrange -->   Points inside triangle = Area - (Points on the sides / 2) + 1
    
    double Area = p*m*0.5;
    
    // Three sides
    // (0, 0) to (p, 0): p points on the side
    // (0, 0) to (n, m): GCD(n, m)  <-- This gets all integer points on one side
    // (n, m) to (p, 0): GCD(abs(p-n), m)
    // General formula to find points on a line: GCD(abs(x1-x2), abs(y1-y2))
    // Proof: https://math.stackexchange.com/questions/628117/how-to-count-lattice-points-on-a-line
    
    double P = p + __gcd((int)n, (int)m) + __gcd((int)abs(p-n), (int)m);
    
    int ans = Area - P*0.5 + 1;
    cout << ans << "\n";
}