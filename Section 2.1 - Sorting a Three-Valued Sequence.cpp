/*
ID:
TASK: sort3
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001], b[1001];

int find(int j) {
    for (int i = j+1; i < n; i++) {
        if (a[i] == b[j] && a[j] == b[i]) return i;
    }
    for (int i = j+1; i < n; i++) {
        if (a[i] != b[i] && a[i] == b[j]) return i;
    }
    return -1;
}

int main() {
    ofstream cout("sort3.out");
    ifstream cin("sort3.in");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    sort(b, b+n);
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            int ind = find(i);
            swap(a[i], a[ind]);
            c++;
        }
    }
    
    cout << c << '\n';
}
