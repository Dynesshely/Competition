#include <bits/stdc++.h>
using namespace std;

int         n, s;
vector<int> ans;

bool isPalindrome(int x, int b) {
    int digits[32], len = 0;
    while (x) {
        digits[len++] = x % b;
        x /= b;
    }
    for (int i = 0; i < len / 2; i++)
        if (digits[i] != digits[len - 1 - i])
            return false;
    return true;
}

bool check(int x) {
    int cnt = 0;
    for (int b = 2; b <= 10; b++)
        if (isPalindrome(x, b))
            cnt++;
    return cnt >= 2;
}

void input() { scanf("%d%d", &n, &s); }

void process() {
    ans.clear();
    for (int x = s + 1; (int)ans.size() < n; x++)
        if (check(x))
            ans.push_back(x);
}

void output() {
    for (int x : ans)
        printf("%d\n", x);
}

int main() {
    input();
    process();
    output();
    return 0;
}
