#include <bits/stdc++.h>
using namespace std;

int         n;
vector<int> nums;
vector<int> prod;

void input() { scanf("%d", &n); }

void process() {
    int rem = n;
    for (int i = 2; i <= rem; ++i) {
        nums.push_back(i);
        rem -= i;
    }
    int len = nums.size();
    if (rem >= len) {
        int addAll = rem / len;
        for (int i = 0; i < len; ++i)
            nums[i] += addAll;
        rem %= len;
    }
    for (int i = len - 1; i >= 0 && rem > 0; --i) {
        nums[i]++;
        rem--;
    }
    prod.push_back(1);
    for (int x : nums) {
        int carry = 0;
        for (int i = 0; i < (int)prod.size(); ++i) {
            long long cur = (long long)prod[i] * x + carry;
            prod[i]       = cur % 10;
            carry         = cur / 10;
        }
        while (carry) {
            prod.push_back(carry % 10);
            carry /= 10;
        }
    }
}

void output() {
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i)
            printf(" ");
        printf("%d", nums[i]);
    }
    printf("\n");
    for (int i = (int)prod.size() - 1; i >= 0; --i)
        printf("%d", prod[i]);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
