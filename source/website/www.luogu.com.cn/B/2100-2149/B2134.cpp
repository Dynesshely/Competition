#include <bits/stdc++.h>
using namespace std;

int s;

void input() { scanf("%d", &s); }

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void process() {
    int maxProd = 0;
    for (int i = 2; i <= s / 2; i++)
        if (isPrime(i) && isPrime(s - i)) {
            int prod = i * (s - i);
            if (prod > maxProd)
                maxProd = prod;
        }
    printf("%d\n", maxProd);
}

int main() {
    input();
    process();
    return 0;
}
