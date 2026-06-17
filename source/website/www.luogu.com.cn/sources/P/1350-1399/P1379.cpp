#include <bits/stdc++.h>
using namespace std;

string                     start, target = "123804765";
int                        dr[] = {-1, 1, 0, 0};
int                        dc[] = {0, 0, -1, 1};
unordered_map<string, int> dist;

void input() {
    char s[10];
    scanf("%s", s);
    start = s;
}

void process() {
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        if (cur == target)
            return;
        int d = dist[cur], pos = cur.find('0');
        int r = pos / 3, c = pos % 3;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr > 2 || nc < 0 || nc > 2)
                continue;
            int    npos = nr * 3 + nc;
            string next = cur;
            swap(next[pos], next[npos]);
            if (dist.find(next) != dist.end())
                continue;
            dist[next] = d + 1;
            q.push(next);
        }
    }
}

void output() { printf("%d\n", dist[target]); }

int main() {
    input();
    process();
    output();
    return 0;
}
