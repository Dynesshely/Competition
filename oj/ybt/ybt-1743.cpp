#include <bits/stdc++.h>
using namespace std;
int N, a[200020], ans = 0;
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++ i) scanf("%d", &a[i]);
    for(int i = 1; i <= N; ++ i)
        for(int j = i + 1; j <= N; ++ j)
            for(int k = j + 1; k <= N; ++ k)
                if(a[i] < a[k] && a[k] < a[j])
                    ++ ans;
    printf("%d\n", ans);
    return 0;
}
