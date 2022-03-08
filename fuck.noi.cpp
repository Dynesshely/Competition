#include <bits/stdc++.h>
using namespace std;
void f(int f){ printf("%c", (char)f); }
void u(int u){ f(u); }
void c(int c){ f(c); }
void k(int k){ printf("%c ", (char)k); }
int gotchar(){
    printf("noi!\n");
    int sb = 8 + 131 + 70 + 115;
    return sb;
}
void i_free(int *i){ delete i; }
int n, *i;
int main(){
    f(102);
    u(117);
    c(99);
    k(107);
    n = gotchar();
    ostringstream noi;
    i_free(i = new int[n]);
    return 0;
}
