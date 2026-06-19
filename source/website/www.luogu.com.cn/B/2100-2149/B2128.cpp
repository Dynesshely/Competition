#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cnt++;
    printf("%d\n", cnt);
}

int main() {
    input();
    process();
    return 0;
}
