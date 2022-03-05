#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000000;
long long N, ans = 0;
bool type[maxn], via[maxn];
long long flag(long long a, long long b){
    return (a + b) * (a + b + 1) / 2 + b;
}
void dfs(long long s, long long e){
    if(e - s < 2) return;
    if(via[flag(s, e)]) return;
    long long tG = 0, tH = 0;
    for(long long i = s; i <= e; ++ i) if(type[i]) ++ tG; else ++ tH; 
    if(tG == 1 || tH == 1) ++ ans;
    via[flag(s, e)] = 1;
    for(long long i = s; i <= e; ++ i)
        for(long long j = i; j <= e; ++ j)
            dfs(i, j);
    return;
}
int main(){
    scanf("%lld", &N);
    for(long long i = 1; i <= N; ++ i){
        char tmp; scanf("%c", &tmp);
        type[i] = (tmp == 'G' ? 1 : 0);
    }
    dfs(1, N);
    printf("%lld\n", ans);
    return 0;
}