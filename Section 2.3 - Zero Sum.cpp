/*
ID: 
TASK: zerosum
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> ans;
//int checks = 0;

bool check(string s) {
    //checks++;
    int l = s.size();
    int sum = 0;
    int prev = 1;
    for (int i = 1; i < l; i++) {
        char op = s[i];
        i++;
        int next = s[i]-'0';
        if (op == '+') {
            sum += prev;
            prev = next;
        } else if (op == '-') {
            sum += prev;
            prev = 0-next;
        } else {
            if (prev < 0) prev = prev*10 - next;
            else prev = prev*10 + next;
        }
    }
    sum += prev;
    if (sum == 0) return 1;
    return 0;
}

void search(int x, string s) {
    if (x == n) {
        s += x+'0';
        if (check(s)) {
            ans.push_back(s);
        }
        return;
    }
    
    search(x+1, s + char(x+'0') + " ");
    search(x+1, s + char(x+'0') + "+");
    search(x+1, s + char(x+'0') + "-");
}

int main() {
    ofstream cout("zerosum.out");
    ifstream cin("zerosum.in");
    
    cin >> n;
    search(1, "");
    //cout << "checks: " << checks << "\n";
    for (auto i : ans) cout << i << "\n";
}
