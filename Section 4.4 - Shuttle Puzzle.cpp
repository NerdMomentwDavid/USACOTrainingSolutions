/*
ID: 
TASK: shuttle
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

char board[26];
int n, l;
int m = 0, mn;
// try out the pattern here: https://nrich.maths.org/content/00/12/game1/frogs/index.html#/student/2/2
// 1 pair: 3 moves
// 2 pair: 8 moves
// 3 pair: 15 moves
// Pattern: (n+1)*(n+1)-1

void init() {
    l = 2*n+1;
    mn = (n+1)*(n+1)-1;
    for (int i = 1; i <= n; i++) board[i] = 'W';
    board[n+1] = ' ';
    for (int i = 1; i <= n; i++) board[i+n+1] = 'B';
}

int main() {
    ifstream cin("shuttle.in");
    ofstream cout("shuttle.out");
    cin >> n;
    init();
    int cnt = 1;
    bool f = 1;
    while (cnt) {
        cnt = 0;
        f = 1;
        for (int i = l-1; i >= 1; i--) {
            if (board[i] == 'W') {
                if (board[i+1] == 'B' && i < l-1 && board[i+2]==' ') {
                    swap(board[i], board[i+2]);
                    cout << i;
                    cnt++;
                    m++;
                    f = 1;
                    if (m % 20 == 0 || m == mn) {
                        cout << "\n";
                    } else {
                        cout << " ";
                    }
                } else if (board[i+1] == ' ') {
                    if (f) {
                        swap(board[i], board[i+1]);
                        cout << i;
                        cnt++;
                        m++;
                        f = 0;
                    } else {
                        break;
                    }
                    if (m % 20 == 0 || m == mn) {
                        cout << "\n";
                    } else {
                        cout << " ";
                    }
                }
            }
        }
        
        f = 1;
        for (int i = 2; i <= l; i++) {
            if (board[i] == 'B') {
                if (board[i-1] == 'W' && i > 2 && board[i-2] == ' ') {
                    swap(board[i], board[i-2]);
                    cout << i;
                    m++;
                    f = 1;
                    if (m % 20 == 0) {
                        cout << "\n";
                    } else {
                        cout << " ";
                    }
                } else if (board[i-1] == ' ') {
                    if (f) {
                        swap(board[i], board[i-1]);
                        cout << i;
                        m++;
                        f = 0;
                    } else {
                        break;
                    }
                    if (m % 20 == 0) {
                        cout << "\n";
                    } else {
                        cout << " ";
                    }
                }
            }
        }
    }
}
