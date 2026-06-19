#include <bits/stdc++.h>
using namespace std;

double threshold;
char   s1[510], s2[510];

void input() {
    scanf("%lf", &threshold);
    scanf("%s%s", s1, s2);
}

void process() {}

void output() {
    int n = strlen(s1), cnt = 0;
    for (int i = 0; i < n; i++)
        if (s1[i] == s2[i])
            cnt++;
    if ((double)cnt / n >= threshold)
        printf("yes\n");
    else
        printf("no\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
