/*
ID:
TASK: kimbits
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ofstream cout("kimbits.out");
    ifstream cin("kimbits.in");
    
    int n, l;
    ll I;
    cin >> n >> l >> I;
    
    ll cnt = 1;
    int ans;
    
    if (I == 1) {
        ans = 0;
    } else { // 1L << n
        for (ll i = 1; i < (ll(1) << n); i++) { // Search through every number that can be represented by n binary bits: i.e. n = 4, 1 << 4 means 10000 in binary,
                                           // it's equal to 2^4, then we will search from 0000 to 1111 (in binary base)
            int bitC = bitset<32>(i).count(); // Convert from decimal base to binary base and count set bits
            if (bitC <= l) {
                cnt++;
                if (cnt == I) {
                    ans = i;
                    break;
                }
                
                int c = 0;
                for (int x = i; x&1; x >>= 1) c++; // Count the last few continuous 1 bits: i.e. 01011 has a count of 2 continuous 1 bits starting from the end and 10100 has 0
                
                if (cnt + (1L<<c) <= I) { // Skip a few steps: i.e. 00111 turns to 01111 and cnt increases by everything that was in between 00111 to 01111  
                                          // (because those that are in between definitely have less than l set bits) but we have to make sure we don't exceed our wanted number
                    i += (1L<<c)-1; // -1 because every we loop i++ by default so if we don't -1 we might miss a number
                    cnt += (1L<<c)-1;
                }
            } else { // If number of set bits already exceeds l, then searching a few numbers after that won't be neccesary:
                     // i.e. l = 2 and i = 011100(in binary) then we can skip 011101, 011110 and 011111
                int c = 0;
                for (int x = i; x&1 == 0; x >>= 1) c++; // Same thing as before but this time count the ending zeros so we can skip them:
                                                        // i.e. 011100 has a count of 2 and 110001 has a count of 0
                
                i += (1L<<c)-1;
            }
        }
    }
    
    bitset<32> a = bitset<32>(ans);
    for (int i = n-1; i >= 0; i--) cout << a[i];
    cout << "\n";
    
    return 0;
}