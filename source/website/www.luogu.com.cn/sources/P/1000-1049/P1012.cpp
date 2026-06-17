#include <bits/stdc++.h>
using namespace std;

// P1012 [NOIP 1998 提高组] 拼数
// 排序规则: a+b > b+a (字符串拼接比较)

int main() {
    int n;
    scanf("%d", &n);

    vector<string> a(n);
    char buf[20];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        a[i] = buf;
    }

    sort(a.begin(), a.end(),
         [](const string &x, const string &y) { return x + y > y + x; });

    for (const auto &s : a) printf("%s", s.c_str());
    putchar('\n');
    return 0;
}
