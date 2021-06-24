/*
ID: davidwa11
TASK: pprime
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
    for (int i = 2; i*i <= x ; i++) {
        if (x%i == 0) return 0;
    }
    
    return 1;
}

set<int> ans;

int main() {
    ofstream cout("pprime.out");
    ifstream cin("pprime.in");
    
    int A, B;
    cin >> A >> B;
    
    ans.insert(5);
    ans.insert(7);
    ans.insert(11);
    
    for (int i = 10; i < 100; i++) {
        if (!(i%20)) i+=10;
        string s1 = to_string(i);
        string s2 = to_string(i/10);
        int t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
        s2 = s1;
        reverse(s2.begin(), s2.end());
        t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
    }
    
    for (int i = 100; i < 1000; i++) {
        if (!(i%200)) i += 100;
        string s1 = to_string(i);
        string s2 = to_string(i/10);
        reverse(s2.begin(), s2.end());
        int t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
        s2 = s1;
        reverse(s2.begin(), s2.end());
        t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
    }
    
    for (int i = 1000; i < 10000; i++) {
        if (!(i%2000)) i += 1000;
        string s1 = to_string(i);
        string s2 = to_string(i/10);
        reverse(s2.begin(), s2.end());
        int t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
        s2 = s1;
        reverse(s2.begin(), s2.end());
        t = stoi(s1+s2);
        if (check(t)) ans.insert(t);
    }
    
    for (auto i : ans) {
        if (i > B) break;
        if (i < A) continue;
        cout << i << "\n";
    }
}