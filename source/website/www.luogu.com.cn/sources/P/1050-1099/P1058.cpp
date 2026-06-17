#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define PINF 0x7fffffff
#define NINF 0x80000000

int        m, n, am, an;
int        arr[55][55];
char       output[500][500];
int        calM(int m, int mh, int tm) { return (tm - m + 1) * 2 + max(1 + 3 * mh, 1 + 2 * (m - 1)); }
inline int calN(int m, int n) { return 1 + 4 * n + 2 * m; }

inline void printLine(int x, int y) {
    output[x][y] = output[x][y + 4] = '+';
    output[x][y + 1] = output[x][y + 2] = output[x][y + 3] = '-';
}
inline void printRow(int x, int y) {
    output[x][y] = output[x + 2][y - 2] = '+';
    output[x + 1][y - 1]                = '/';
}
inline void printHeight(int x, int y) {
    output[x][y] = output[x + 3][y] = '+';
    output[x + 1][y] = output[x + 2][y] = '|';
}
inline void printSpace(int x, int y) {
    output[x + 1][y] = output[x + 1][y + 1] = output[x + 1][y + 2] = ' ';
    output[x + 3][y - 1] = output[x + 3][y] = output[x + 3][y + 1] = ' ';
    output[x + 4][y - 1] = output[x + 4][y] = output[x + 4][y + 1] = ' ';
    output[x + 2][y + 3] = output[x + 3][y + 3] = ' ';
}
inline void printCube(int x, int y) {
    printLine(x, y);
    printLine(x + 2, y - 2);
    printLine(x + 5, y - 2);
    printRow(x, y);
    printRow(x, y + 4);
    printRow(x + 3, y + 4);
    printHeight(x + 2, y - 2);
    printHeight(x + 2, y + 2);
    printHeight(x, y + 4);
    printSpace(x, y);
}
inline void printCube2(int l, int r, int h) { printCube(am - 3 * h - 2 * (m - l + 1), 1 + 2 * (m - l + 1) + (r - 1) * 4); }
inline void printAns() {
    for (int i = 1; i <= am; i++) {
        cout << output[i] + 1 << endl;
    }
    cout << endl;
}
int main() {
    cin >> m >> n;
    an = calN(m, n);
    for (int i = 1; i <= m; i++) {
        int mmax = 0;
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            mmax = max(mmax, arr[i][j]);
        }
        am = max(am, calM(i, mmax, m));
    }
    for (int i = 1; i <= am; i++) {
        for (int j = 1; j <= an; j++) {
            output[i][j] = '.';
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= arr[i][j]; k++) {
                printCube2(i, j, k);
            }
        }
    }
    printAns();
}
