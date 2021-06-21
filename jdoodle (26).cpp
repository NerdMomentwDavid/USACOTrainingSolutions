/*
ID: 
TASK: milk3
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

bool vis[21][21][21];
bool ans[21];
int cnt = 0;
int A, B, C;

void solve(int a, int b, int c) {
    if (vis[a][b][c] || cnt == C+1) return; // Make sure the recursion stops somewhere
    
    if (a == 0) { // Add new answer
        if (!ans[c]) cnt++;
        ans[c] = 1;
    }
    
    vis[a][b][c]=1;
    
    // DFS through all possibilities
    if (a < A) {
        if (a+b <= A) {
            solve(a+b, 0, c);
        } else {
            solve(A, a+b-A, c);
        }
        
        if (a+c <= A) {
            solve(a+c, b, 0);
        } else {
            solve(A, b, a+c-A);
        }
    }
    
    if (b < B) {
        if (a+b <= B) {
            solve(0, a+b, c);
        } else {
            solve(a+b-B, B, c);
        }
        
        if (b+c <= B) {
            solve(a, b+c, 0);
        } else {
            solve(a, B, b+c-B);
        }
    }
    
    if (c < C) {
        if (a+c <= C) {
            solve(0, b, a+c);
        } else {
            solve(a+c-C, b, C);
        }
        
        if (b+c <= C) {
            solve(a, 0, b+c);
        } else {
            solve(a, b+c-C, C);
        }
    }
}

int main() {
    ofstream cout("milk3.out");
    ifstream cin("milk3.in");
    
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    
    cin >> A >> B >> C;
    
    solve(0, 0, C); // The important part
    
    vector<int> v;
    for (int i = 0; i <= 20; i++) {
        if (ans[i]) {
            v.push_back(i);
        }
    }
    
    for (int i = 0; i < cnt; i++) {
        cout << v[i];
        if (i != cnt-1) { // Cannot have whitespace at the end
            cout << " ";
        }
    }
    cout << "\n";
}