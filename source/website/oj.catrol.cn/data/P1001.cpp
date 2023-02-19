#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x7fffffff;
int main(){
    srand(time(0));
    for(int i = 1; i <= 10; ++ i){
        int a = rand() % maxn, b = rand() % maxn;
        long long c = b, d = a;
        ostringstream fin, fout;

        fin << "P1001/" << "swap" << i << ".in";
        freopen(fin.str().c_str(), "w", stdout);
        printf("%d %d\n", (int)a, (int)b);

        fout << "P1001/" << "swap" << i << ".ans";
        freopen(fout.str().c_str(), "w", stdout);
        printf("%lld %lld\n", c + d, c - d);
    }
    return 0;
}