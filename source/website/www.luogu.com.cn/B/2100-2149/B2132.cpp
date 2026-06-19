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
    bool found = false;
    for (int i = 2; i + 2 <= n; i++)
        if (isPrime[i] && isPrime[i + 2]) {
            printf("%d %d\n", i, i + 2);
            found = true;
        }
    if (!found)
        printf("empty\n");
}

int main() {
    input();
    process();
    return 0;
}
