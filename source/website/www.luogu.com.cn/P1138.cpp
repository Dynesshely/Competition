#include <bits/stdc++.h>

int main(){
    int n, k, *ns;
    scanf("%d %d", &n, &k);
    ns = new int[n];
    for(int i = 0; i < n; ++ i)
        scanf("%d", &ns[i]);
    std::sort(ns, ns + n);
    int cnt = std::unique(ns, ns + n) - ns;
    if(k >= cnt) printf("NO RESULT\n");
    else printf("%d\n", ns[k - 1]);
    return 0;
}