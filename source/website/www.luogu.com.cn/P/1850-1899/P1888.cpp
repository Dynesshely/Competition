#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);
    int g = __gcd(arr[0], arr[2]);
    printf("%d/%d\n", arr[0] / g, arr[2] / g);
    return 0;
}
