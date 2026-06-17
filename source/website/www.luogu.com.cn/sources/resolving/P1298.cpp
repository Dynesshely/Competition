#include <bits/stdc++.h>
using namespace std;

int       M, N;
long long num, den;
char      s[30];
long long bestNum, bestDen, bestCross;
bool      tooMany;

void input() {
    scanf("%d%d%s", &M, &N, s);
    long long intPart = 0, fracPart = 0;
    int       fracLen = 0, i = 0;
    while (s[i] && s[i] != '.') {
        intPart = intPart * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.') {
        i++;
        while (s[i]) {
            fracPart = fracPart * 10 + (s[i] - '0');
            fracLen++;
            i++;
        }
    }
    den = 1;
    for (int j = 0; j < fracLen; j++)
        den *= 10;
    num = intPart * den + fracPart;
}

void process() {
    bestNum = -1, bestDen = 1, bestCross = 0;
    tooMany = false;
    for (long long d = 1; d <= N; d++) {
        long long n1  = d * num / den;
        long long rem = d * num % den;
        if (n1 >= 0 && n1 <= M) {
            if (bestNum == -1) {
                bestNum   = n1;
                bestDen   = d;
                bestCross = rem;
            } else {
                long long lhs = rem * bestDen;
                long long rhs = bestCross * d;
                if (lhs < rhs) {
                    bestNum   = n1;
                    bestDen   = d;
                    bestCross = rem;
                    tooMany   = false;
                } else if (lhs == rhs && n1 * bestDen != bestNum * d)
                    tooMany = true;
            }
        }
        if (rem != 0) {
            long long n2 = n1 + 1;
            if (n2 <= M) {
                long long cross = den - rem;
                if (bestNum == -1) {
                    bestNum   = n2;
                    bestDen   = d;
                    bestCross = cross;
                } else {
                    long long lhs = cross * bestDen;
                    long long rhs = bestCross * d;
                    if (lhs < rhs) {
                        bestNum   = n2;
                        bestDen   = d;
                        bestCross = cross;
                        tooMany   = false;
                    } else if (lhs == rhs && n2 * bestDen != bestNum * d)
                        tooMany = true;
                }
            }
        }
    }
}

void output() {
    if (tooMany) {
        printf("TOO MANY\n");
        return;
    }
    long long g = __gcd(bestNum, bestDen);
    printf("%lld/%lld\n", bestNum / g, bestDen / g);
}

int main() {
    input();
    process();
    output();
    return 0;
}
