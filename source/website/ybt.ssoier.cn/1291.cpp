#include <bits/stdc++.h>
using namespace std;
int c[1000], f[1000];
int v, m;
int main() {
    scanf("%d%d", &m, &v);
    for(int i = 1; i <= m; i++){
        scanf("%d", &c[i]);
    }
    f[0] = 1;
    for(int i = 1; i <= m; i++)
        for(int j = v; j >= c[i]; j--)  
            f[j] += f[j-c[i]];
    printf("%d\n", f[v]);
    return 0;
}