#include <bits/stdc++.h>
using namespace std;

int main() {
    long long xl, xu, yl, yu;
    scanf("%lld%lld", &xl, &xu);
    scanf("%lld%lld", &yl, &yu);
    long long minVal = min({xl * yl, xl * yu, xu * yl, xu * yu});
    long long maxVal = max({xl * yl, xl * yu, xu * yl, xu * yu});
    if (minVal < -2147483648LL || maxVal > 2147483647LL)
        printf("long long int\n");
    else
        printf("int\n");
    return 0;
}
