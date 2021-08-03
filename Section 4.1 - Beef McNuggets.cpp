/*
ID: 
TASK: nuggets
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> x;
int ans = 0;
bool imp[1000000]; // Largest possible is only 256*256 - (256+256) = 65024

int main() {
	ofstream cout("nuggets.out");
	ifstream cin("nuggets.in");
	
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		x.push_back(a);
	}
	
	sort(x.begin(), x.end());
	for (int i = 0; i < x.size()-1; i++) {
		for (int j = i+1; j < x.size(); j++) {
			if (x[j]%x[i] == 0) {
				x.erase(x.begin()+j);
				j--;
			}
		}
	}
	
	int GCD = x[0];
	for (auto i : x) GCD = __gcd(GCD, i);
	
	if (x[0] == 1 || GCD != 1) cout << "0\n";
	else {
		memset(imp, 0, sizeof(imp));
		ans = x[0]-1;
		for (int i = 1; i <= x[0]-1; i++) imp[i] = 1;
		
		int cnt = 0;
		for (int i = x[0]-1; i <= 2000000000; i++) {
		    if (cnt == 256) break;
		    
			bool f = 1;
			for (auto j : x) {
				if (j > i) break;
				if (!imp[i-j]) {
					f = 0;
					break;
				}
			}
			
			if (f) {
			    ans = i;
			    imp[i] = 1;
			    cnt = 0;
			} else {
			    cnt++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
