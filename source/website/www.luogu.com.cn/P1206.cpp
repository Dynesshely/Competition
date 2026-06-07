#include <bits/stdc++.h>
using namespace std;

int B;

string toBaseB(int n) {
    string s;
    while (n > 0) {
        int d = n % B;
        if (d < 10)
            s += '0' + d;
        else
            s += 'A' + d - 10;
        n /= B;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r)
        if (s[l] != s[r])
            return false;
        else
            l++, r--;
    return true;
}

void input() { scanf("%d", &B); }

void process() {
    for (int i = 1; i <= 300; i++) {
        string sq = toBaseB(i * i);
        if (isPalindrome(sq))
            printf("%s %s\n", toBaseB(i).c_str(), sq.c_str());
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
