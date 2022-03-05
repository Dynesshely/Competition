#include<bits/stdc++.h>
char c[109];
int k, l, u;
struct big{ int a[109]; }d, p, q, r, s, t;//结构体
big mul(big x,big y){ //高精乘高精
    big z = d; //赋值实现清空
    register int i, j;
    for(i = 1; i <= k; ++ i) //高精乘法
        for(j = k - i + 1; j; -- j){
            z.a[i + j - 1] += x.a[i] * y.a[j];
        }
    for(i = 1; i < k; ++ i) z.a[i + 1] += z.a[i] / 10, z.a[i] %= 10;
    z.a[k] %= 10; //处理进位
    return z;
}
int main(){
    register int i, j;
    scanf("%s%d", c, &k), l = strlen(c);
    for(i = (l < k ? l : k); i; -- i) p.a[i] = c[l - i] - 48; //字符串转整数，p即为原数
    r = p, t.a[l = 1] = 1; //r为乘的结果，初始值为p
    for(i = 1; i <= k; ++ i){
        if(mul(p, r).a[i] == p.a[i]) continue; //周期为1的情况
        u = 1, s = r; //s为每次乘的数
        do{
            r = mul(s, r), ++ u;
            if(u > 10){
                puts("-1"); //判无解
                return 0;
            }
        }while(mul(p, r).a[i] != p.a[i]);
        for(j = 1; j <= l; ++ j) t.a[j] *= u;
        for(j = 1; j < l; ++ j) t.a[j+1] += t.a[j] / 10, t.a[j] %= 10;
        if(t.a[l] >= 10) t.a[l + 1] += t.a[l] / 10, t.a[l ++] %= 10; //更新答案，高精乘单精
    }
    for(i = l; i; --i) printf("%d", t.a[i]); //输出
    return 0;
}