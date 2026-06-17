#include <bits/stdc++.h>
using namespace std;

int n;
struct FD {
    int l, r;
};
vector<FD> fd;

int mk(const string &s) {
    int m = 0;
    for (char c : s)
        m |= 1 << (c - 'A');
    return m;
}

void input() {
    scanf("%d", &n);
    fd.resize(n);
    for (int i = 0; i < n; i++) {
        char buf[1000];
        scanf("%s", buf);
        string s(buf);
        int    p = s.find("->");
        fd[i].l  = mk(s.substr(0, p));
        fd[i].r  = mk(s.substr(p + 2));
    }
}

bool red(int i) {
    int          cur = fd[i].l, t = fd[i].r;
    vector<char> u(n, 0);
    u[i] = 1;
    while (true) {
        bool ch = false;
        for (int j = 0; j < n; j++) {
            if (u[j])
                continue;
            if ((fd[j].l & ~cur) == 0) {
                int na = fd[j].r & ~cur;
                if (na) {
                    cur |= na;
                    u[j] = 1;
                    ch   = true;
                    if ((t & ~cur) == 0)
                        return true;
                }
            }
        }
        if (!ch)
            break;
    }
    return false;
}

vector<int> pro(int i) {
    int                     s = fd[i].l, t = fd[i].r;
    unordered_map<int, int> pv, fu;
    queue<int>              q;
    pv[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if ((t & ~c) == 0) {
            vector<int> seq;
            int         st = c;
            while (pv[st] != -1) {
                seq.push_back(fu[st]);
                st = pv[st];
            }
            reverse(seq.begin(), seq.end());
            return seq;
        }
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            if ((fd[j].l & ~c) != 0)
                continue;
            if ((fd[j].r & ~c) == 0)
                continue;
            int nx = c | fd[j].r;
            if (pv.find(nx) == pv.end()) {
                pv[nx] = c;
                fu[nx] = j;
                q.push(nx);
            }
        }
    }
    return {};
}

void process() {
    bool any = false;
    for (int i = 0; i < n; i++) {
        if (red(i)) {
            any             = true;
            vector<int> seq = pro(i);
            printf("FD %d is redundant using FDs:", i + 1);
            for (int x : seq)
                printf(" %d", x + 1);
            printf("\n");
        }
    }
    if (!any)
        printf("No redundant FDs\n");
}

int main() {
    input();
    process();
    return 0;
}
