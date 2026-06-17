#include <bits/stdc++.h>
using namespace std;

int              n;
multiset<string> adj[26];
int              inDeg[26], outDeg[26];
vector<string>   bestPath;

void dfs(int u, multiset<string> *a, vector<string> &p) {
    while (!a[u].empty()) {
        auto   it = a[u].begin();
        string w  = *it;
        a[u].erase(it);
        dfs(w.back() - 'a', a, p);
        p.push_back(w);
    }
}

bool tryStart(int s) {
    multiset<string> tmp[26];
    for (int i = 0; i < 26; i++)
        tmp[i] = adj[i];
    vector<string> p;
    dfs(s, tmp, p);
    if (p.size() == n) {
        reverse(p.begin(), p.end());
        bestPath = p;
        return true;
    }
    return false;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char buf[25];
        scanf("%s", buf);
        string w(buf);
        int    u = w[0] - 'a';
        int    v = w.back() - 'a';
        adj[u].insert(w);
        outDeg[u]++;
        inDeg[v]++;
    }
}

void process() {
    int  start = -1, end = -1;
    bool valid = true;
    for (int i = 0; i < 26; i++) {
        int diff = outDeg[i] - inDeg[i];
        if (diff == 1) {
            if (start == -1)
                start = i;
            else {
                valid = false;
                break;
            }
        } else if (diff == -1) {
            if (end == -1)
                end = i;
            else {
                valid = false;
                break;
            }
        } else if (diff != 0) {
            valid = false;
            break;
        }
    }
    if (!valid)
        return;
    if ((start != -1) ^ (end != -1))
        return;

    if (start == -1) {
        bool hasEdge = false;
        for (int i = 0; i < 26; i++) {
            if (!adj[i].empty()) {
                hasEdge = true;
                break;
            }
        }
        if (!hasEdge)
            return;
        for (int i = 0; i < 26; i++) {
            if (!adj[i].empty()) {
                multiset<string> tmp[26];
                for (int j = 0; j < 26; j++)
                    tmp[j] = adj[j];
                vector<string> p;
                dfs(i, tmp, p);
                if (p.size() == n) {
                    reverse(p.begin(), p.end());
                    if (bestPath.empty() || p < bestPath)
                        bestPath = p;
                }
            }
        }
    } else {
        tryStart(start);
    }
}

void output() {
    if (bestPath.empty()) {
        printf("***\n");
        return;
    }
    for (int i = 0; i < (int)bestPath.size(); i++) {
        if (i > 0)
            putchar('.');
        printf("%s", bestPath[i].c_str());
    }
    putchar('\n');
}

int main() {
    input();
    process();
    output();
    return 0;
}
