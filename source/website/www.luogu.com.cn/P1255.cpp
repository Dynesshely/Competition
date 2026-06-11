#include <bits/stdc++.h>
using namespace std;

string addString(string a, string b) {
    string res;
    int    carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n == 2) {
        printf("2\n");
        return 0;
    }
    string prev = "1", cur = "2";
    for (int i = 3; i <= n; ++i) {
        string next = addString(prev, cur);
        prev        = cur;
        cur         = next;
    }
    printf("%s\n", cur.c_str());
    return 0;
}
