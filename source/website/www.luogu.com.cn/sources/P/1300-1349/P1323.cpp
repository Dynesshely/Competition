#include <bits/stdc++.h>
using namespace std;

int    k, m;
string allDigits, ans;

void input() {
    if (scanf("%d%d", &k, &m) == 2) {
    }
}

void process() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(1);
    for (int i = 0; i < k; i++) {
        long long cur = pq.top();
        pq.pop();
        allDigits += to_string(cur);
        pq.push(2 * cur + 1);
        pq.push(4 * cur + 5);
    }
    int rem = m;
    for (char c : allDigits) {
        while (rem > 0 && !ans.empty() && ans.back() < c) {
            ans.pop_back();
            rem--;
        }
        ans.push_back(c);
    }
    while (rem > 0) {
        ans.pop_back();
        rem--;
    }
}

void output() { printf("%s\n%s\n", allDigits.c_str(), ans.c_str()); }

int main() {
    input();
    process();
    output();
    return 0;
}
