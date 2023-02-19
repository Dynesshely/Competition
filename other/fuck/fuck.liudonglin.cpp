#include <bits/stdc++.h>
using namespace std;
typedef long long van;
template <typename T> inline void read(T &x) {
    T f = 1, b = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        b *= 10, b += ch - '0', ch = getchar();
    x = f * b;
    return;
}
template <typename T> inline void print(T x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x == 0) {
        putchar('0');
        return;
    }
    van st[51] = {0}, k = 0;
    while (x)
        st[++k] = x % 10, x /= 10;
    for (int i = k; i; i--)
        putchar(st[i] + '0');
}
int main() {
    while (1)
        cout << "fuck liudonglin!!!" << endl;
}
