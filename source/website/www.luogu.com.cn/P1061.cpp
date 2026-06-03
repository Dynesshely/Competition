#include <cstdio>

int main() {
    int s, t, w;
    char str[30];
    scanf("%d%d%d%s", &s, &t, &w, str);
    for (int cnt = 0; cnt < 5; ++cnt) {
        int i = w - 1;
        while (i >= 0 && str[i] == 'a' + t - 1 - (w - 1 - i)) --i;
        if (i < 0) break;
        ++str[i];
        for (int j = i + 1; j < w; ++j)
            str[j] = str[j - 1] + 1;
        printf("%s\n", str);
    }
    return 0;
}
