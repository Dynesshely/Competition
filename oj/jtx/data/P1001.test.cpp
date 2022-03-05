#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 1; i <= 10; ++ i){
        ostringstream fin, fout;
        fin << "P1001/" << "swap" << i << ".in";
        freopen(fin.str().c_str(), "r", stdin);
        long long a, b, tmp;
        scanf("%lld %lld", &a, &b);
        tmp = a, a = b, b = tmp;
        long long m = a + b, n = a - b;
        fout << "P1001/" << "swap" << i << ".ans";
        freopen(fout.str().c_str(), "r", stdin);
        long long ans_m, ans_n;
        scanf("%lld %lld", &ans_m, &ans_n);
        if(m != ans_m || n != ans_n)
            printf("err in: %s\n", fout.str().c_str());
    }
    return 0;
}