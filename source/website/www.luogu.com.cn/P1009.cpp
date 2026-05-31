#include <bits/stdc++.h>
using namespace std;

// P1009 [NOIP 1998 普及组] 阶乘之和
// 高精度：计算 1! + 2! + ... + n!，n ≤ 50

struct Big {
    vector<int> d; // 倒序存储，d[0] 为最低位
    Big() : d(1, 0) {}
    explicit Big(int x) : d(1, x) { carry(); }

    void carry() {
        for (size_t i = 0; i < d.size(); ++i) {
            if (d[i] >= 10) {
                if (i + 1 == d.size()) d.push_back(0);
                d[i + 1] += d[i] / 10;
                d[i] %= 10;
            }
        }
    }

    Big &operator+=(const Big &o) {
        if (o.d.size() > d.size()) d.resize(o.d.size(), 0);
        for (size_t i = 0; i < o.d.size(); ++i) d[i] += o.d[i];
        carry();
        return *this;
    }

    Big &operator*=(int x) {
        for (int &v : d) v *= x;
        carry();
        return *this;
    }

    void print() const {
        for (int i = (int)d.size() - 1; i >= 0; --i)
            putchar(d[i] + '0');
        putchar('\n');
    }
};

int main() {
    int n;
    scanf("%d", &n);

    Big fact(1); // 当前阶乘值
    Big sum(0);  // 累加和

    for (int i = 1; i <= n; ++i) {
        fact *= i;
        sum += fact;
    }
    sum.print();
    return 0;
}
