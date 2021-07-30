/*
ID: 
TASK: game1
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int a[102];
int dp[102][102][102];

int Search(int l, int r, int f) {
	if (dp[l][r][f] != -1) return dp[l][r][f];
	
	if (l == r) {
		if (f&1) return 0;
		return a[l];
	}
	
	if (f&1) dp[l][r][f] = min(Search(l+1, r, f+1), Search(l, r-1, f+1));
	else dp[l][r][f] = max(a[l]+Search(l+1, r, f+1), a[r]+Search(l, r-1, f+1));
	
	return dp[l][r][f];
}

int main() {
	ofstream cout("game1.out");
	ifstream cin("game1.in");
	
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	
	int x = Search(0, n-1, 0);
	cout << x << " " << s-x << "\n";
	
    return 0;
}