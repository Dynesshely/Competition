#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

template<class T>

inline void read(T &x) {
    x      = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar())
        f ^= c == '-';
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template<class T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T   y   = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10)
        ++len;
    for (; len; --len, x %= y, y /= 10)
        putchar(x / y + 48);
}

const int MAXN = 3e4, MAXM = 3e5;
int       n, ans;
string    s[MAXN + 5];
bool      ok[MAXN + 5];

struct Trie {
    int        tot, in[26], e[26][26], ch[MAXM + 5][26];
    bool       ed[MAXM + 5];
    queue<int> q;

    inline void insert(string x) {
        int u = 1, len = x.size();
        for (int i = 0; i < len; ++i) {
            int v = x[i] - 'a';
            if (!ch[u][v])
                ch[u][v] = ++tot;
            u = ch[u][v];
        }
        ed[u] = 1;
    }

    inline void topoSort() {
        for (; !q.empty(); q.pop())
            ;
        for (int i = 0; i < 26; ++i)
            if (!in[i])
                q.push(i);
        for (; !q.empty();) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < 26; ++v)
                if (e[u][v])
                    if (!(--in[v]))
                        q.push(v);
        }
    }

    inline bool find(string x) {
        int u = 1, len = x.size();
        memset(e, 0, sizeof(e));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < len; ++i) {
            if (ed[u])
                return 0;
            int v = x[i] - 'a';
            for (int j = 0; j < 26; ++j)
                if (v != j && ch[u][j] && !e[v][j]) {
                    e[v][j] = 1;
                    ++in[j];
                }
            u = ch[u][v];
        }
        topoSort();
        for (int i = 0; i < 26; ++i)
            if (in[i])
                return 0;
        return 1;
    }
} tr;

int main() {
    read(n);
    tr.tot = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        tr.insert(s[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (tr.find(s[i])) {
            ++ans;
            ok[i] = 1;
        }
    write(ans);
    putchar('\n');
    for (int i = 1; i <= n; ++i)
        if (ok[i])
            cout << s[i] << '\n';
    return 0;
}