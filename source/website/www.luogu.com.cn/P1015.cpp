#include <bits/stdc++.h>
using namespace std;

// P1015 [NOIP 1999 普及组] 回文数
// 给定 N 进制数 M (最长 100 位)，每次操作：M + reverse(M)
// 30 步内若成回文数输出步数，否则 Impossible!

int char_to_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char digit_to_char(int d) {
    if (d < 10) return '0' + d;
    return 'A' + d - 10;
}

int main() {
    int N;
    char s[105];
    scanf("%d%s", &N, s);

    vector<int> a;
    for (int i = 0; s[i]; ++i)
        a.push_back(char_to_digit(s[i]));

    for (int step = 1; step <= 30; ++step) {
        // 反转并相加
        vector<int> b(a.rbegin(), a.rend());
        vector<int> c;
        int carry = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            int sum = a[i] + b[i] + carry;
            c.push_back(sum % N);
            carry = sum / N;
        }
        if (carry) c.push_back(carry);
        a = c;

        // 检查回文
        bool ok = true;
        for (size_t i = 0; i < a.size() / 2; ++i) {
            if (a[i] != a[a.size() - 1 - i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("STEP=%d\n", step);
            return 0;
        }
    }

    printf("Impossible!\n");
    return 0;
}
