/*
ID: 
TASK: preface
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int cnt[] = {0, 0, 0, 0, 0, 0, 0};
//           I  V  X  L  C  D  M

int p[] = {1, 10, 100, 1000};

int main() {
    ofstream cout("preface.out");
    ifstream cin("preface.in");
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = i;
        for (int j = 3; j >= 0; j--) {
            int c = t/p[j];
            if (c < 4) {
                cnt[j*2] += c;
            } else if (c == 4) {
                cnt[j*2]++;
                cnt[j*2+1]++;
            } else if (c == 9) {
                cnt[j*2]++;
                cnt[j*2+2]++;
            } else {
                cnt[j*2] += c-5;
                cnt[j*2+1]++;
            }
            t %= p[j];
        }
    }
    
    for (int i = 0; i < 7; i++) {
        if (cnt[i]) {
            cout << ch[i] << " " << cnt[i] << "\n";
        }
    }
}
