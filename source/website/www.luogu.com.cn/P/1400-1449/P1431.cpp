#include <bits/stdc++.h>
using namespace std;

string mul3(const string &s) {
    string r;
    int    c = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        int d = (s[i] - '0') * 3 + c;
        r.push_back('0' + d % 10);
        c = d / 10;
    }
    while (c) {
        r.push_back('0' + c % 10);
        c /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

string mul2(const string &s) {
    string r;
    int    c = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        int d = (s[i] - '0') * 2 + c;
        r.push_back('0' + d % 10);
        c = d / 10;
    }
    while (c) {
        r.push_back('0' + c % 10);
        c /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

string add3(const string &s) {
    string r = s;
    int    i = (int)r.size() - 1;
    int    c = 3;
    while (c && i >= 0) {
        int d = (r[i] - '0') + c;
        r[i]  = '0' + d % 10;
        c     = d / 10;
        i--;
    }
    if (c)
        r.insert(r.begin(), '0' + c);
    return r;
}

int cmp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size() ? -1 : 1;
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] != b[i])
            return a[i] < b[i] ? -1 : 1;
    return 0;
}

struct Case {
    string t;
    int    idx;
};

int main() {
    int T;
    scanf("%d", &T);
    vector<Case> cs(T);
    vector<int>  ans(T);
    for (int i = 0; i < T; i++) {
        int  k, p;
        char s[10010];
        scanf("%d %d %s", &k, &p, s);
        string n(s);
        if (p == 0)
            cs[i].t = add3(mul2(n));
        else
            cs[i].t = n;
        cs[i].idx = i;
    }
    sort(cs.begin(), cs.end(), [](const Case &a, const Case &b) { return cmp(a.t, b.t) < 0; });
    string cur  = "1";
    int    curM = 0, idx = 0;
    while (idx < T) {
        if (cmp(cur, cs[idx].t) >= 0) {
            ans[cs[idx].idx] = curM;
            idx++;
        } else {
            cur = mul3(cur);
            curM++;
        }
    }
    for (int v : ans)
        printf("%d\n", v);
    return 0;
}
