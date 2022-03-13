#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int (i) = (a); (i) <= (b); ++ (i))
typedef pair<int, int> pii; typedef pair<pii, int> pli;
const int N = 205;
int n, m, T, close, tag[N + 1];
char s[N][N], a[N][N];
vector<pli> prt;
template <class T> void read(T &x){
    bool f = false; x = 0; char ch = getchar();
    while (ch<'0' || ch>'9'){ if (ch == '-') f = true; ch = getchar(); }
    while (ch>='0' && ch<='9') x = x * 10 + ch - '0', ch = getchar();
    if (f) x = -x;
}
inline void open(int x, int y){
    -- close; int cnt = 0;
    fr(i, x - 1, x + 1) fr(j, y - 1, y + 1){
        if (i < 1 || i > n || j < 1 || j > m) continue;
        if (a[i][j] == '*') ++ cnt;
    }
    prt.push_back(make_pair(make_pair(x, y), cnt)); s[x][y] = '0' + cnt;
    if (cnt == 0){
        fr(i, x - 1, x + 1) fr(j, y - 1, y + 1){
            if (i < 1 || i > n || j < 1 || j > m) continue;
            if (s[i][j] == '_' || s[i][j] == '?'){ open(i, j); }
        }
    }
}
inline void outputall(){
    sort(prt.begin(), prt.end()); int sz = prt.size() - 1; printf("RUNNING: [");
    fr(i, 0, sz){
        printf("<%d, %d, %d>", prt[i].first.first, prt[i].first.second, prt[i].second);
        if (i != sz) printf(", ");
    }
    puts("]");
}
int main(){
    srand(time(0));
    fr(i, 1, N) tag[i] = rand() % 100;
    freopen("boom.in", "r", stdin); freopen("boom.out", "w", stdout);
    read(T);
    while (T--){
        read(n), read(m); int mine = 0;
        fr(i, 1, n){ scanf("%s", a[i] + 1); fr(j, 1, m) if (a[i][j] == '*') mine++; }
        fr(i, 1, n) fr(j, 1, m) s[i][j] = '_';
        int op, x, y; close = n * m; bool lose = false, win = false;
        while (~scanf("%d", &op)){
            if (op == 0){ if (!win && !lose) puts("QUIT"); break; }
            read(x), read(y); if (lose || win){ puts("INVALID"); continue; }
            switch(op){
                case 1:
                    if (s[x][y] >= '0' && s[x][y] <= '9' || s[x][y] == 'P')
                    { puts("RUNNING: []"); continue; }
                    if (a[x][y] == '*'){ puts("LOSE"); lose = true; continue; }
                    prt.clear(); open(x, y); outputall();
                    if (close == mine){ puts("WIN"); win = true; continue; }
                    break;
                case 2:
                    if (s[x][y] >= '0' && s[x][y] <= '9')
                    { puts("RUNNING: []"); continue; }
                    if (s[x][y] == '_') s[x][y] = 'P';
                    else if (s[x][y] == 'P') s[x][y] = '?'; else s[x][y] = '_';
                    printf("RUNNING: [<%d, %d, %c>]\n", x, y, s[x][y]);
                    break;
                case 3:
                    if (!(s[x][y] >= '0' && s[x][y] <= '9'))
                    { puts("RUNNING: []"); continue; }
                    int cnt = 0;
                    fr(i, x - 1, x + 1) fr(j, y - 1, y + 1){
                        if (i < 1 || i > n || j < 1 || j > m) continue;
                        if (s[i][j] == 'P') cnt++;
                    }
                    if (cnt != (s[x][y] - '0')){ puts("RUNNING: []"); continue; }
                    prt.clear();
                    fr(i, x - 1, x + 1){
                        fr(j, y - 1, y + 1){
                            if (i < 1 || i > n || j < 1 || j > m) continue;
                            if (s[i][j] == 'P' || (s[i][j] >= '0' && s[i][j] <= '9'))
                                continue;
                            if (a[i][j] == '*'){ lose = true; } else open(i, j);
                        }
                    }
                    if (lose){ puts("LOSE"); continue; } outputall();
                    if (close == mine){ puts("WIN"); win = true; continue; }
                    break;
            }
        }
        if (T) puts("==========");
    }
    return 0;
}
