#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    bool found = false;
    for (int i = 10000; i <= 30000; ++i) {
        int sub1 = i / 100;
        int sub2 = (i / 10) % 1000;
        int sub3 = i % 1000;
        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
            printf("%d\n", i);
            found = true;
        }
    }
    if (!found) printf("No\n");
    return 0;
}
