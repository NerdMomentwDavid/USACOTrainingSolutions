/*
ID:
TASK: lgame
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int val[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

unordered_map<string, bool> dict;
string str;
set<pair<string, string>> ans;
int mx = 0;

int score(string s) {
    int sum = 0;
    for (auto c : s) sum += val[c-'a'];
    return sum;
}

int main() {
    ofstream cout("lgame.out");
    ifstream din("lgame.dict");
    string tmp;
    while (din >> tmp) {
        if (tmp == ".") break;
        dict[tmp] = 1;
    }
    ifstream cin("lgame.in");
    cin >> str;
    int l = str.size();
    
    sort(str.begin(), str.end());
    do {
        for (int i = 3; i <= l; i++) {
            tmp = str.substr(0, i);
            if (dict.count(tmp)) {
                int s = score(tmp);
                if (s > mx) {
                    mx = s;
                    ans.clear();
                    ans.insert({tmp, ""});
                } else if (s == mx) {
                    ans.insert({tmp, ""});
                }
            }
            for (int j = 3; i+j <= l; j++) {
                string a = str.substr(i, j), b = str.substr(0, i);
                if (dict.count(a) && dict.count(b)) {
                    if (a > b) swap(a, b);
                    int s = score(a)+score(b);
                    if (s > mx) {
                        mx = s;
                        ans.clear();
                        ans.insert({a, b});
                    } else if (s == mx) {
                        ans.insert({a, b});
                    }
                }
            }
        }
    } while (next_permutation(str.begin(), str.end()));
    
    cout << mx << "\n";
    for (auto x : ans) {
        cout << x.first;
        if (x.second != "") {
            cout << " " << x.second;
        }
        cout << "\n";
    }
}
