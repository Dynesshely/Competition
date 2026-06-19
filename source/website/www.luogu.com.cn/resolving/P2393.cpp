#include <bits/stdc++.h>
using namespace std;

double sum, x;

void input() {
    while (cin >> x)
        sum += x;
}

void process() { cout << fixed << setprecision(5) << sum << endl; }

int main() {
    input();
    process();
    return 0;
}
