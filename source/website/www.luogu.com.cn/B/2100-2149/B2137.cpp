#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100000;
bool      isComp[MAXN + 1];
int       x, y;

void input() { scanf("%d%d", &x, &y); }

void process() {
    if (x > y)
        swap(x, y);
    isComp[0] = isComp[1] = true;
    for (int i = 2; i * i <= y; i++)
        if (!isComp[i])
            for (int j = i * i; j <= y; j += i)
                isComp[j] = true;
    int cnt = 0;
    for (int i = x; i <= y; i++)
        if (!isComp[i])
            cnt++;
    printf("%d\n", cnt);
}

int main() {
    input();
    process();
    return 0;
}
