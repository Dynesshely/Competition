#include <bits/stdc++.h>
using namespace std;
double sum = 0.0, tmp;
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){ cin >> tmp; sum += tmp; }
    cout << (int)sum << " " << fixed << setprecision(5) << sum / (n * 1.0) << endl;
    return 0;
}