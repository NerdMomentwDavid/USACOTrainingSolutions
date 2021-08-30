/*
ID: 
TASK: vans
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define MEM(x, v) memset(x, v, sizeof(x));

struct BigNum {
    int len;
    int dig[1000];
    BigNum() {
        MEM(dig, 0);
        len = 1;
    }
    BigNum(int x) {
        MEM(dig, 0);
        dig[0] = x;
        len = 1;
    }
    
    BigNum operator + (BigNum a) {
        BigNum c;
        c.len = max(a.len, len);
        bool carry = 0;
        for (int i = 0; i < c.len; i++) {
            int t = dig[i] + a.dig[i] + carry;
            if (t >= 10) {
                carry = 1;
                t -= 10;
            } else carry = 0;
            c.dig[i] = t;
        }
        if (carry) {
            c.dig[c.len] = 1;
            c.len++;
        }
        return c;
    }
    
    friend ostream& operator << (ostream& o, BigNum c);
};

ostream& operator << (ostream& o, BigNum c) {
    for (int i = c.len-1; i >= 0; i--) {
        o << c.dig[i];
    }
    return o;
}

BigNum a[1005], b[1005];
BigNum c;

int main() {
    ofstream cout("vans.out");
    ifstream cin("vans.in");
    
    int n;
    cin >> n;
    
    a[1] = BigNum(0), a[2] = BigNum(2);
    b[1] = BigNum(2), b[2] = BigNum(2);
    BigNum c = BigNum(2);
    for (int i = 3; i <= n; i++) {
        c = c + a[i-2] + a[i-2];
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1] + a[i-1] + b[i-2] + c;
    }
    
    cout << a[n] << "\n";
    
    return 0;
}
