#include <bits/stdc++.h>
using namespace std;

int n, pos[100005], lch[100005], rch[100005];
int stk[100005], top;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }
    int root = 0;
    for (int v = 1; v <= n; v++) {
        int last = 0;
        while (top && pos[stk[top]] > pos[v])
            last = stk[top--];
        lch[v] = last;
        if (top)
            rch[stk[top]] = v;
        else
            root = v;
        stk[++top] = v;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(root);
    bool first = true;
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        if (!first)
            printf(" ");
        printf("%d", v);
        first = false;
        if (lch[v])
            pq.push(lch[v]);
        if (rch[v])
            pq.push(rch[v]);
    }
    printf("\n");
    return 0;
}
