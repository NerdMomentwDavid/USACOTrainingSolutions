/*
ID: 
TASK: heritage
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int ind = 0, n;
string inorder, preorder;
string ans = "";

int p = 0;
void postorder(int l, int r) {
    if (r < l || l > r) {
        p--;
        return;
    }
    if (l == r) {
        ans += inorder[l];
        return;
    }
    
    int ind = 0;
    while (inorder[ind] != preorder[p]) ind++;
    p++;
    postorder(l, ind-1);
    p++;
    postorder(ind+1, r);
    ans += inorder[ind];
}

int main() {
    ofstream cout("heritage.out");
    ifstream cin("heritage.in");
    cin >> inorder >> preorder;
    n = inorder.size();
    postorder(0, n-1);
    cout << ans << '\n';
}