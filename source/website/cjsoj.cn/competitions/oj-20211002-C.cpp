#include <bits/stdc++.h>
#define MAXN 300
#define INF 0x7fffffff
using namespace std;
long long N, each_gold[MAXN], ans = -INF, dfs(int i, long long ng, queue<int> via);
bool way[MAXN][MAXN];
string path = "";
int main() {
    scanf("%lld", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%lld", &each_gold[i]);
    while (true) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        else
            way[a][b] = true;
    }
    for (int i = 1; i <= N; ++i) {
        queue<int> via;
        dfs(i, each_gold[i], via);
    }
    printf("%s\n%lld\n", path.c_str(), ans);
    return 0;
}
bool exist(queue<int> visit, int tar) {
    int size = visit.size();
    for (int i = 0; i < size; ++i) {
        if (visit.front() == tar)
            return true;
        visit.push(visit.front());
        visit.pop();
    }
    return false;
}
long long dfs(int i, long long ng, queue<int> via) {
    if (exist(via, i))
        return ng - each_gold[i];
    else
        via.push(i);
    long long tmp = ng;
    for (int j = 1; j <= N; ++j)
        if (way[i][j] && i != j)
            tmp = max(tmp, dfs(j, ng + each_gold[j], via));
    if (tmp > ans) {
        ans = tmp;
        path = "";
        int size = via.size();
        for (int i = 0; i < size; ++i) {
            ostringstream os;
            os << via.front();
            path += os.str();
            path += i == size - 1 ? "" : "-";
            via.push(via.front());
            via.pop();
        }
    }
    return tmp;
}