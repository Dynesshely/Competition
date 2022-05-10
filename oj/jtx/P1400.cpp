#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cert-err34-c"

// Copyright (c) Catrol 2022-present.
// ALL RIGHTS RESERVED.
// Author:   Dynesshely/Catrol
// E-Mail:   catrol@qq.com
// Date:     2022-04-25

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-register"

const int maxsize = 200 + 3;

int n, m, a[maxsize][maxsize], T, cur_w, cur_h;
std::queue<std::pair<char, int>> cmds;

inline void input(), process(), output();

int main() {
    input();
    process();
    output();
    return 0;
}

inline void input() {
    scanf("%d %d", &n, &m);
    cur_h = n, cur_w = m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    scanf("%d", &T);
    char o;
    for (int i = 1, arg; i <= T; ++i) {
        std::cin >> o;
        if (o == 'h' || o == 'v') cmds.push({o, 0});
        else {
            scanf("%d", &arg);
            cmds.push({o, arg});
        }
    }
}

template<typename T>
inline void swap(T *x, T *y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
}

inline void rotate() {
    swap(&cur_h, &cur_w);
    int **tmp_mat = new int *[cur_h];
    for (int i = 0; i < cur_h; ++i)
        tmp_mat[i] = new int[cur_w];

    int newmat_pos_x = 0, newmat_pos_y = 0;
    for (int j = 0; j < cur_h; ++j)
        for (int i = cur_w - 1; i >= 0; --i) {
            tmp_mat[newmat_pos_y][newmat_pos_x] = a[i][j];
            newmat_pos_y = newmat_pos_x == cur_w - 1 ? newmat_pos_y + 1 : newmat_pos_y;
            newmat_pos_x = newmat_pos_x == cur_w - 1 ? 0 : newmat_pos_x + 1;
        }

    for (int i = 0; i < cur_h; ++i)
        for (int j = 0; j < cur_w; ++j)
            a[i][j] = tmp_mat[i][j];

    for (int i = 0; i < cur_h; ++i) {
        delete[]tmp_mat[i];
        tmp_mat[i] = nullptr;
    }
    delete[]tmp_mat;
    tmp_mat = nullptr;
}

inline void rotate(int *angle) {
    int times = *angle >= 0 ? (*angle % 360) / 90 : (
            *angle <= -360 ? (360 + -1 * (std::abs(*angle) % 360)) / 90 : (*angle + 360) / 90
    );

    while (times--)
        rotate();
    *angle = 0;
}

inline void process() {
    int angle = 0, size = cmds.size();
    for (int i = 0; i < size; ++i) {
        std::pair<char, int> cur = cmds.front();
        if (cur.first == 'r') angle += cur.second;
        else if (cur.first == 'l') angle -= cur.second;
        else {
            rotate(&angle);
            switch (cur.first) {
                case 'h':
                    for (int l = 0; l < cur_h; ++l)
                        for (int j = 0, je = cur_w - 1; j < cur_w / 2; ++j, --je)
                            swap(&a[l][j], &a[l][je]);
                    break;
                case 'v':
                    for (int j = 0; j < cur_w; ++j)
                        for (int l = 0, le = cur_h - 1; l < cur_h / 2; ++l, --le)
                            swap(&a[l][j], &a[le][j]);
                    break;
            }
        }
        cmds.pop();
    }
    rotate(&angle);
}

inline void output() {
    for (int i = 0; i < cur_h; ++i) {
        for (int j = 0; j < cur_w; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

#pragma clang diagnostic pop
#pragma clang diagnostic pop
