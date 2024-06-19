#include <bits/stdc++.h>
using namespace std;

// void debug(string info){ printf("\tdebug >> %s\n", info.c_str()); }

int N, a[310], ans = 0x7fffffff, tmp_a[310];

void multistart(int s) {
    int tmp_ans = 0;
    for (int i = s; i <= N; ++i)
        for (int j = N; j >= i; --j)
            if (tmp_a[i] == tmp_a[j] && tmp_a[i] >= 1 && tmp_a[j] >= 1) {
                ++tmp_ans;
                int tmp = tmp_a[i];
                for (int k = i + 1; k < j; ++k) {
                    if (tmp_a[k] == -1) {
                        int s = k;
                        while (true) {
                            if (tmp_a[s] == -1)
                                ++s;
                            else
                                break;
                        }
                        ++tmp_ans;
                        k = s + 1;
                    }
                }
                for (int k = i; k <= j; ++k)
                    if (tmp_a[k] == tmp)
                        tmp_a[k] = -1;
                    else
                        break;
                for (int k = j; k >= i; --k)
                    if (tmp_a[k] == tmp)
                        tmp_a[k] = -1;
                    else
                        break;
            }
    if (s != 1)
        tmp_ans += (s - 1);
    ans = min(ans, tmp_ans);
}

int main() {
    freopen("draw.in", "r", stdin);
    freopen("draw.out", "w", stdout);

    // freopen("draw.in", "r", stdin);
    // freopen("draw.out", "w", stdout);

    scanf("%d", &N);

    // cur_end = N;

    for (int i = 1; i <= N; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            tmp_a[j] = a[j];
        multistart(i);
    }
    // for(int i = 1; i <= N; ++ i)
    //     for(int j = N; j >= i; -- j)
    //         if(a[i] == a[j] && a[i] >= 1 && a[j] >= 1){
    //             ++ ans; int tmp = a[i];
    //             for(int k = i + 1; k < j; ++ k){
    //                 if(a[k] == -1){
    //                     int s = k;
    //                     while(true){
    //                         if(a[s] == -1) ++ s;
    //                         else break;
    //                     }
    //                     ++ ans;
    //                     k = s + 1;
    //                 }
    //             }
    //             for(int k = i; k <= j; ++ k)
    //                 if(a[k] == tmp) a[k] = -1;
    //                 else break;
    //             for(int k = j; k >= i; -- k)
    //                 if(a[k] == tmp) a[k] = -1;
    //                 else break;

    //             // for(int k = i; k <= j; ++ k)
    //             //     if(a[k] == tmp) a[k] = -1;

    //             // 调试
    //             // printf("\tdebug>> %d %d\n", i, j);
    //             // for(int m = 1; m <= N; ++ m)
    //             //     printf(" %d ", a[m]);
    //             // printf("\n");
    //         }

    // while(true){
    //     if(a[cur_a] == a[cur_b]){
    //         ++ ans;
    //         ++ cur_a;
    //         -- cur_b;
    //         continue;
    //     }else{
    //         -- cur_b;
    //     }

    // }

    // bool isLastMoveOnLeft = true;
    // while(true){
    //     if(cur_a == cur_b){ ++ ans; break; }
    //     else{

    //     }
    //     if(a[*cur_a] == a[*cur_b]) ++ans;
    //     if(isLastMoveOnLeft){
    //         -- *cur_b;
    //         isLastMoveOnLeft = false;
    //         printf(" debug >> %d\n", *cur_b);
    //     }
    //     else{
    //         ++ *&cur_a;
    //         isLastMoveOnLeft = true;
    //         printf(" debug >> %d\n", *cur_a);
    //     }
    // }

    printf("%d\n", ans);
    return 0;
}

/*
    第一版 14:46
    问题：
        1. 漏掉单独处于中间的已经记录过的数字
*/
// int N, a[310], index[310][2], length[310], ans = 0;
// bool via[310], via_end[310];
// int main(){
//     // freopen("draw.in", "r", stdin);
//     // freopen("draw.out", "w", stdout);
//     memset(length, -1, sizeof(length));
//     scanf("%d", &N);
//     for(int i = 1; i <= N; ++ i){
//         scanf("%d", &a[i]);
//         if(via[a[i]]){
//             index[a[i]][1] = i; // 更新终点坐标
//             length[a[i]] = i - index[a[i]][0]; // 更新跨度
//         }else{
//             index[a[i]][0] = i; // 更新起点坐标
//             length[a[i]] = 0; // 更新跨度
//             via[a[i]]= true; // 更新起点是否找到的记录
//         }
//     }
//     for(int i = 1; i <= N; ++ i){
//         if(length[i] != -1) ++ ans;
//         printf(">> length[%d] %d << ", i, length[i]);
//     }
//     printf("%d\n", ans);
//     return 0;
// }