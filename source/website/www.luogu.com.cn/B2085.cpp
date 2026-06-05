#include <bits/stdc++.h>
using namespace std;

const int lim = 400000;

void input(int &n) { scanf("%d", &n); }

void process(int n) {
    vector<bool> isPrime(lim + 1, true);
    isPrime[0] = isPrime[1] = false;
    int cnt                 = 0;
    for (int i = 2; i <= lim; i++) {
        if (isPrime[i]) {
            cnt++;
            if (cnt == n) {
                printf("%d\n", i);
                return;
            }
            if ((long long)i * i <= lim)
                for (int j = i * i; j <= lim; j += i)
                    isPrime[j] = false;
        }
    }
}

int main() {
    int n;
    input(n);
    process(n);
    return 0;
}
