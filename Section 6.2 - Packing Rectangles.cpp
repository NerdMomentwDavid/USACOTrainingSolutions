/*
ID: 
TASK: packrec
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MEM(x, v) memset(x, v, sizeof(x))

int minArea = INT_MAX;
bool vis[205][205];
vector<pair<int, int>> ans;
pair<int, int> rect[4];

void check(int w, int h, int m) {
    if (w > h) swap(w, h);
    if (vis[w][h]) return;
    vis[w][h] = 1;
    int area = w*h;
    if (area < minArea) {
        ans.clear();
        ans.push_back({w, h});
        minArea = area;
    } else if (area == minArea) {
        ans.push_back({w, h});
    }
}

void tryRect() {
    int w, h;
    // case #1
    w = 0, h = 0;
    for (int i = 0; i < 4; i++) w += rect[i].first, h = max(h, rect[i].second);
    check(w, h, 1);
    
    // case #2
    w = 0, h = 0;
    for (int i = 1; i < 4; i++) w += rect[i].first, h = max(h, rect[i].second);
    w = max(w, rect[0].first);
    h += rect[0].second;
    check(w, h, 2);
    
    // case #3
    w = max(rect[1].first+rect[2].first, rect[0].first);
    h = max(rect[1].second, rect[2].second) + rect[0].second;
    w += rect[3].first;
    h = max(h, rect[3].second);
    check(w, h, 3);
    
    // case #4 and #5
    w = max(rect[0].first, rect[1].first) + rect[2].first + rect[3].first;
    h = max(max(rect[0].second+rect[1].second, rect[2].second), rect[3].second);
    check(w, h, 4);
    
    // case #6
    w = max(rect[0].first+rect[1].first, max(rect[2].first, rect[3].first));
    h = max(rect[0].second+rect[2].second, rect[1].second+rect[3].second);
    if (rect[0].second > rect[1].second) {
        w = max(w, rect[0].first+rect[3].first);
        if (rect[0].second-rect[1].second < rect[3].second) w = max(w, rect[2].first+rect[3].first);
    } else {
        w = max(w, rect[1].first+rect[2].first);
        if (rect[1].second-rect[0].second < rect[2].second) w = max(w, rect[2].first+rect[3].first);
    }
    check(w, h, 6);
}

void rotateShape(int c) {
    if (c == 4) {
        tryRect();
        return;
    }
    swap(rect[c].first, rect[c].second);
    rotateShape(c+1);
    swap(rect[c].first, rect[c].second);
    rotateShape(c+1);
}

int main() {
    ofstream cout("packrec.out");
    ifstream cin("packrec.in");
    
    MEM(vis, 0);
    for (int i = 0; i < 4; i++) cin >> rect[i].first >> rect[i].second;
    
    sort(rect, rect+4);
    do {
        rotateShape(0);
    } while (next_permutation(rect, rect+4));
    
    sort(ans.begin(), ans.end());
    cout << minArea << "\n";
    for (auto i : ans) cout << i.first << " " << i.second << "\n";
}
