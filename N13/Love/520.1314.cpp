// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <iostream>

inline int sum(std::string s) { int ans = 0; for (char i: s) ans += i; return ans; }

int main() {
    for (int i = 1; i <= sum("CQY"); ++ i)
        printf("%.4f\n", (((float) i + 52.8) * 5.0 - 3.9343) / 0.5 - 10 * i);
    return 0;
}
