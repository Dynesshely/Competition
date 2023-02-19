// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = (2 * pow(10, 9));
// bool primes[maxn + 10];
// bool isPrime(int num) {
//     if (num <= 3)
//         return num > 1;
//     if (num % 6 != 1 && num % 6 != 5)
//         return false;
//     int sqrt_num = sqrt(num);
//     for (int i = 5; i <= sqrt_num; i += 6)
//         if (num % i == 0 || num % (i + 2) == 0)
//             return false;
//     return true;
// }
// int main() {
//     for (int i = 1; i <= maxn; ++i)
//         primes[i] = isPrime(i) ? 1 : 0;
//     int n, maxp = -0x3fffffff;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; ++i)
//         if (n % i == 0 && primes[i])
//             maxp = max(maxp, i);
//     printf("%d\n", maxp);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, ans = -0x3fffffff;
bool isPrime(int num) {
    if (num <= 3)
        return num > 1;
    if (num % 6 != 1 && num % 6 != 5)
        return false;
    int sqrt_num = sqrt(num);
    for (int i = 5; i <= sqrt_num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}
int main() {
    scanf("%d", &n);
    for (int i = 2; i < n; ++i)
        if (n % i == 0 && isPrime(i))
            ans = max(ans, i);
    printf("%d\n", ans);
    return 0;
}
