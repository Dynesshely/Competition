#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
double a, b, c, d, ans;
int n, m;

double f(double x){ return a * x * x * x + b * x * x + c * x + d; }

void solve(double l, double r){
    if(l + 1e-3 >= r){
        printf("%.2f ", l);
        return;
    }
    double mid = (l + r) / 2.0, ans_l, ans_r;
    if(f(mid) == 0) printf("%.2f ", mid);
    if(f(r) == 0) printf("%.2f ", r);
    ans_l = f(l) * f(mid); ans_r = f(r) * f(mid);
    if(ans_l < 0) solve(l, mid);
    else if(ans_r < 0) solve(mid, r);
}

int main(){
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for(double i = -100; i <= 99; ++ i) if(f(i) * f(i + 1.0) <= 0) solve(i, i + 1.0);
    return 0;
}
