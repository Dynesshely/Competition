#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100000;
int       dist[MAXV];

void bfs(int s, int maxLen) {
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        string str     = to_string(cur);
        int    len     = str.size();
        int    curDist = dist[cur];
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                swap(str[i], str[j]);
                int nxt = stoi(str);
                if (dist[nxt] == -1) {
                    dist[nxt] = curDist + 1;
                    q.push(nxt);
                }
                swap(str[i], str[j]);
            }
        }
        if (len > 1) {
            for (int i = 0; i < len; i++) {
                string tmp = str.substr(0, i) + str.substr(i + 1);
                int    nxt = stoi(tmp);
                if (dist[nxt] == -1) {
                    dist[nxt] = curDist + 1;
                    q.push(nxt);
                }
            }
        }
        if (len < maxLen) {
            for (int i = 0; i < len - 1; i++) {
                int a = str[i] - '0', b = str[i + 1] - '0';
                if (a >= b)
                    continue;
                for (int x = a + 1; x < b; x++) {
                    string tmp = str.substr(0, i + 1) + char('0' + x) + str.substr(i + 1);
                    int    nxt = stoi(tmp);
                    if (dist[nxt] == -1) {
                        dist[nxt] = curDist + 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
}

int main() {
    int s, m;
    scanf("%d%d", &s, &m);
    int maxLen = to_string(s).size();
    bfs(s, maxLen);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        printf("%d\n", dist[t]);
    }
    return 0;
}
