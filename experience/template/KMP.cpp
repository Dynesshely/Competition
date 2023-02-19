// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

static inline int fixlen(std::string src) {
    if (src.length() == 0)
        return 0;
    for (int l = 0; l < src.length(); ++l) {
        bool flag = true;
        for (int i = 0; i < src.length() - 1 - l; ++i)
            if (src[i] != src[i + l + 1]) {
                flag = false;
                break;
            }
        if (flag)
            return (int)src.length() - 1 - l;
    }
    return 0;
}

int main() {
    std::string txt, pat;

    std::getline(std::cin, txt);
    std::getline(std::cin, pat);

    int *next = new int[pat.length() + 1];
    next[0] = 1;

    for (int i = 0; i < pat.length(); ++i)
        next[i + 1] = fixlen(pat.substr(0, i + 1)) + 1;

    for (int i = 0; i < txt.length(); ++i) {
        bool pass = true;
        for (int j = 0; j < pat.length(); ++j) {
            if (txt[i + j] != pat[j]) {
                i += next[j] - 1;
                pass = false;
                break;
            }
        }
        if (pass) {
            printf("%d\n", i);
            break;
        }
    }

    delete[] next;
    return 0;
}
