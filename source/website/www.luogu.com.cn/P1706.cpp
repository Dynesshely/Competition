#include <bits/stdc++.h>

int main(){
    int n, *ns;
    scanf("%d", &n);
    ns = new int[n + 1];
    for(int i = 1; i <= n; ++ i) ns[i] = i;
    do{
        for(int i = 1; i <= n; ++ i) printf("%5d", ns[i]);
        printf("\n");
    }while(std::next_permutation(ns + 1, ns + n + 1));
    return 0;
}