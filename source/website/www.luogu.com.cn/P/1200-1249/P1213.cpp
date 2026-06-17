#include <bits/stdc++.h>
using namespace std;

int init[9];
int bestCnt[9];
int bestTot = 28;

const int eff[9][9] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1}};

void input() {
    for (int i = 0; i < 9; ++i) {
        int t;
        scanf("%d", &t);
        init[i] = (t / 3) % 4;
    }
}

void process() {
    int cnt[9];
    for (cnt[0] = 0; cnt[0] < 4; ++cnt[0])
        for (cnt[1] = 0; cnt[1] < 4; ++cnt[1])
            for (cnt[2] = 0; cnt[2] < 4; ++cnt[2])
                for (cnt[3] = 0; cnt[3] < 4; ++cnt[3])
                    for (cnt[4] = 0; cnt[4] < 4; ++cnt[4])
                        for (cnt[5] = 0; cnt[5] < 4; ++cnt[5])
                            for (cnt[6] = 0; cnt[6] < 4; ++cnt[6])
                                for (cnt[7] = 0; cnt[7] < 4; ++cnt[7])
                                    for (cnt[8] = 0; cnt[8] < 4; ++cnt[8]) {
                                        int ok = 1;
                                        for (int i = 0; i < 9 && ok; ++i) {
                                            int sum = 0;
                                            for (int j = 0; j < 9; ++j)
                                                sum += cnt[j] * eff[j][i];
                                            if ((init[i] + sum) % 4)
                                                ok = 0;
                                        }
                                        if (!ok)
                                            continue;
                                        int tot = 0;
                                        for (int j = 0; j < 9; ++j)
                                            tot += cnt[j];
                                        if (tot < bestTot) {
                                            bestTot = tot;
                                            for (int j = 0; j < 9; ++j)
                                                bestCnt[j] = cnt[j];
                                        } else if (tot == bestTot) {
                                            int better = 0;
                                            for (int j = 0; j < 9; ++j)
                                                if (cnt[j] != bestCnt[j]) {
                                                    if (cnt[j] > bestCnt[j])
                                                        better = 1;
                                                    break;
                                                }
                                            if (better)
                                                for (int j = 0; j < 9; ++j)
                                                    bestCnt[j] = cnt[j];
                                        }
                                    }
}

void output() {
    int first = 1;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < bestCnt[i]; ++j) {
            if (!first)
                printf(" ");
            printf("%d", i + 1);
            first = 0;
        }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
