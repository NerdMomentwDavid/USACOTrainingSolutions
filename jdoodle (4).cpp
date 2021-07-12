/*
ID: 
TASK: cowtour
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e7;
int n, g=1;
double co[155][2];
double dist[155][155];
double maxD[155], groupD[155];
int group[155];

void setGroup(int x) {
    group[x] = g;
    for (int i = 0; i < n; i++) {
        if (dist[x][i] != INF && !group[i]) setGroup(i);
    }
}

int main() {
    ofstream cout("cowtour.out");
    ifstream cin("cowtour.in");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> co[i][0] >> co[i][1];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            
            if (t=='1' || i == j) {
                double x1 = co[i][0], y1 = co[i][1], x2 = co[j][0], y2 = co[j][1];
                dist[i][j] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            } else {
                dist[i][j] = INF;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!group[i]) {
            setGroup(i);
            g++;
        }
    }
    
    for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
		        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
    for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        if (dist[i][j] != INF && dist[i][j] > maxD[i]) {
			    maxD[i] = dist[i][j];
			}
	    }
	    groupD[group[i]] = max(groupD[group[i]], maxD[i]);
	}
	
	double ans = INF;
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        if (dist[i][j] == INF) { // group[i] != group[j]
	            double x1 = co[i][0], y1 = co[i][1], x2 = co[j][0], y2 = co[j][1];
	            double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	            d += maxD[i] + maxD[j];
	            double di = groupD[group[i]], dj = groupD[group[j]];
	            ans = min(ans, max(d, max(di, dj)));
	        }
	    }
	}
	
	cout << fixed << ans << setprecision(6) << "\n";
}