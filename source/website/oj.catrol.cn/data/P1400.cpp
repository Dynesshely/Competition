// Copyright (c) Catrol 2022-present.
// ALL RIGHTS RESERVED.
// Author:   Dynesshely/Catrol
// E-Mail:   catrol@qq.com
// Date:     2022-04-26

#include <bits/stdc++.h>

inline int valid(int tmp){
    int x = 0;
    while(x == 0) x = rand() % tmp;
    return x;
}

int main() {
    srand(time(0));

    for(int t = 1; t <= 2; ++ t){
        int size_x = valid(20), size_y = valid(20), T = valid(10);

        printf("%d %d\n", size_y, size_x);
        for (int i = 0; i < size_y; ++i) {
            for (int j = 0; j < size_x; ++j)
                printf("%d ", valid(10));
            printf("\n");
        }

        printf("%d\n", T);
        for (int i = 0; i < T; ++i) {
            int choose = valid(16);
            if (choose < 10) {
                if (choose % 2 == 0)
                    printf("r %d\n", valid(100) * 90);
                else printf("l %d\n", valid(200) * 90);
            } else {
                if (choose < 13)
                    printf("h\n");
                else printf("v\n");
            }
        }
    }

    for(int t = 3; t <= 5; ++ t){
        int size_x = valid(100), size_y = valid(100), T = valid(20);
        printf("%d %d\n", size_y, size_x);
        for (int i = 0; i < size_y; ++i) {
            for (int j = 0; j < size_x; ++j)
                printf("%d ", valid(10));
            printf("\n");
        }

        printf("%d\n", T);
        for (int i = 0; i < T; ++i) {
            int choose = valid(16);
            if (choose < 10) {
                if (choose % 2 == 0)
                    printf("r %d\n", valid(100) * 90);
                else printf("l %d\n", valid(200) * 90);
            } else {
                if (choose < 13)
                    printf("h\n");
                else printf("v\n");
            }
        }
    }

    for (int t = 6; t <= 10; ++t) {
//        std::ostringstream filename;
//        filename << "data/P1400/imger." << t << ".in";
//        freopen(filename.str().c_str(), "w", stdout);

        int size_x = valid(200), size_y = valid(200), T = valid(50);
        printf("%d %d\n", size_y, size_x);
        for (int i = 0; i < size_y; ++i) {
            for (int j = 0; j < size_x; ++j)
                printf("%d ", valid(10));
            printf("\n");
        }

        printf("%d\n", T);
        for (int i = 0; i < T; ++i) {
            int choose = valid(16);
            if (choose < 10) {
                if (choose % 2 == 0)
                    printf("r %d\n", valid(100) * 90);
                else printf("l %d\n", valid(200) * 90);
            } else {
                if (choose < 13)
                    printf("h\n");
                else printf("v\n");
            }
        }
    }

    return 0;
}
