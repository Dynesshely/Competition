#include <bits/stdc++.h>
using namespace std;

/*
    题目背景
    为了调整电灯亮度，贝西要用干草包堆出一座塔，然后爬到牛棚顶去把灯泡换掉。干草包会从传送带上运来，共会出现N包干草，第i包干草的宽度是W i ，高度和长度统一为1。干草塔要从底层开始铺建。贝西会选择最先送来的若干包干草，堆在地上作为第一层，然后再把紧接着送来的几包干草包放在第二层， 再铺建第三层……重复这个过程， 一直到所有的干 草全部用完。每层的干草包必须紧靠在一起，不出现缝隙，而且为了建筑稳定，上层干草的宽度不能超过下层的宽度。 按顺序运来的干草包一定要都用上， 不能将其中几个干草包弃置不用。贝西的目标是建一座最高的塔，请你来帮助她完成这个任务吧。

    输入格式
    第一行：单个整数：N，1 ≤ N ≤ 100000 第二行到N + 1行：第i + 1行有一个整数W_i，1 ≤ W_i ≤ 10000

    输出格式
    第一行：单个整数，表示可以建立的最高高度
*/

/*
    思路：
        这是一个动态规划的题目
        仅考虑两个结点
        结点A表示过去所有子问题的最优解
        结点B表示现阶段待处理的问题
        那么B只有两个选择：
            1. 将 B 并入 A 这一层作为新的方案
            2. 将 B 作为下一层 (如果可以)
*/

const int N = 100010;
int n, f[N], g[N], sum[N];
int main(){
    scanf("%d", &n);
    for(int i = n; i >= 1; -- i) scanf("%d", &sum[i]);
    for(int i = 1; i <= n; ++ i) sum[i] += sum[i - 1];
    for(int i = 1; i <= n; ++ i)
        for(int j = i - 1; j >= 0; -- j)
            if(sum[i] - sum[j] >= g[j]){
                f[i] = f[j] + 1;
                g[i] = sum[i] - sum[j];
                break;
            }
    printf("%d\n", f[n]);
	return 0;
}

// const int maxn = 100010;
// int N, *w, sln[maxn], maxmum = -1;

// struct state{
//     int level = 0, width = 0;
//     state *prev;
// }*f[maxn][2000];

// int main(){
//     scanf("%d", &N);
//     w = new int[N + 1];
//     for(int i = 1; i <= N; ++ i) scanf("%d", &w[i]);
//     f[0][0] = new state{0, 0x7fffffff, NULL};
//     f[1][0] = new state{1, w[1], f[0][0]};
//     sln[0] = 1; sln[1] = 1;
//     for(int i = 2; i <= N; ++ i)
//         for(int j = 0; j < sln[i - 1]; ++ j){
//             state *to_state = f[i - 1][j];
//             // 如果可以堆叠到下一层
//             if(w[i] <= to_state->width)
//                 f[i][sln[i]++] = new state{to_state->level + 1, w[i], to_state};
//             // 如果可以加入当前层
//             if(w[i] + to_state->width <= to_state->prev->width)
//                 f[i][sln[i]++] = new state{to_state->level, to_state->width + w[i], to_state->prev};
//         }
//     for(int i = 0; i < sln[N]; ++ i)
//         maxmum = max(maxmum, f[N][i]->level);
//     printf("%d\n", maxmum);
//     return 0;
// }

// const int maxn = 100010;
// int N, *w, sln[maxn];
// struct Node{
//     int level = 0, width = 0;
// }f[maxn][maxn];

// int main(){
//     scanf("%d", &N);
//     w = new int[N + 1];
//     for(int i = 1; i <= N; ++ i) scanf("%d", &w[i]);
//     for(int i = 1; i <= N; ++ i){
//         if(sln[i - 1] == 0){ // 第一个结点初始化
//             f[i][sln[i]].level = f[i][sln[i - 1]].level + 1;
//             f[i][sln[i]].width = w[i]; sln[i]++;
//         }else{
//             for(int j = 0; j < sln[i - 1]; ++ j){
//                 if(f[i][j].width >= w[i]){
                    
//                 }
//             }
//         }
//     }
//     return 0;
// }

// int N, *W, ans = 0;
// // int layer_now = 0, layers = 1;
// // stack<int> st;
// int main(){
//     scanf("%d", &N);
//     W = new int[N + 1];
//     for(int i = 0; i < N; ++ i) scanf("%d", &W[i]);
//     for(int i = 0; i < N; ++ i){
        
//     }
//     // for(int i = 0; i < N; ++ i){
//     //     scanf("%d", &W[i]);
//     //     if(W[i] >= layer_now){
//     //         layer_now = 0;
//     //         ++ layers;
//     //         while(!st.empty()){
//     //             st.pop();
//     //         }
//     //         st.push(W[i]);
//     //         continue;
//     //     }
//     //     st.push(W[i]);
//     //     layer_now += W[i];
//     // }
//     printf("%d\n", ans);
//     return 0;
// }