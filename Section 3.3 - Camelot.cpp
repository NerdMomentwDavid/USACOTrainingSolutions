/*
ID: 
TASK: camelot
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int dist[35][30][35][30];
int R, C;
int kr, kc;
vector<pii> k;

int mr[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int mc[] = {-2, 2, -1, 1, -2, 2, -1, 1};

bool check(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

void bfs(int si, int sj) {
	dist[si][sj][si][sj] = 0;
	queue<pii> Q;
	Q.push({si, sj});
	
	int r, c;
	while(!Q.empty()) {
		tie(r, c) = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++) {
			if (check(r+mr[i], c+mc[i]) && dist[si][sj][r+mr[i]][c+mc[i]] == -1) {
				dist[si][sj][r+mr[i]][c+mc[i]] = dist[si][sj][r][c]+1;
				Q.push({r+mr[i], c+mc[i]});
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream cout("camelot.out");
    ifstream cin("camelot.in");
	
    cin >> R >> C;
    
    memset(dist, -1, sizeof(dist));
    char c;
    int r;
    cin >> c >> r;
    
    kr = r-1, kc = c-'A';
    
    while (cin >> c >> r) {
		k.push_back({r-1, c-'A'});
	}
	
	if (k.size() == 0) {
	    cout << "0\n";
	    return 0;
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			bfs(i, j);
		}
	}
	
	int sr = max(0, kr-2), er = min(R, kr+3);
	int sc = max(0, kc-2), ec = min(C, kc+3);
	
	int ans = INT_MAX;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int m = 0; bool f = 1;
			for (auto p : k) {
				if (dist[i][j][p.first][p.second] == -1) {
					f = 0;
					break;
				}
				m += dist[i][j][p.first][p.second];
			}
			if (f) {
				int king = INT_MAX, tr, tc;
				for (int x = sr; x < er; x++) {
					for (int y = sc; y < ec; y++) {
						int d = max(abs(kr-x), abs(kc-y));
						for (auto p : k) {
							tie(tr, tc) = p;
							if (dist[x][y][tr][tc] != -1) {
								king = min(king, d-dist[i][j][tr][tc]+dist[i][j][x][y]+dist[x][y][tr][tc]);
							}
						}
					}
				}
				ans = min(ans, m+king);
			}
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}
