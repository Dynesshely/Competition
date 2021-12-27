#pragma region 老师的 - 邻接表版本
// 老师的 - 邻接表版本
// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1000;
// const int maxe = 100001;
// int g[maxn] = {0}; // n 个节点的邻接表 : 表头，初始为 0 表示无边
// struct Edge{
//     int v; // 边的起点
//     int w; // 边的权值
//     int ne; // 指向下一条边的连接（下标）
// } e[maxe]; // 边集数组
// int tot = 0; // 记录当前边数
// void insert(int u, int v, int w){
//     ++ tot; e[tot].v = v; e[tot].w = w;
//     e[tot].ne = g[u]; g[u] = tot;
// }
// int main(){
//     int m; // 初始边数
//     cin >> m;
//     for(int i = 0; i < m; ++ i){ // 初始化，插入 m 条边
//         int u, v, w;
//         cin >> u >> v >> w;
//         insert(u, v, w);
//     }
//     for(int u = 1; u <= 5; ++ u){ // 遍历
//         int p = g[u];
//         while(p){
//             printf("<%d,%d>(%d) ", u, e[p].v, e[p].w);
//             p = e[p].ne;
//         }
//         if(g[u]) cout << endl;
//     }
//     return 0;
// }
#pragma endregion

#pragma region 自写 - 模拟版本
自写 - 模拟版本
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int start;
    int end;
    int width;
};
struct point{
    int sons[100];
    int width[100];
    int count = 0;
};
int main(){
    int num_edges;
    scanf("%d", &num_edges);
    edge edges[num_edges];
    point points[6];
    for(int i = 0; i < num_edges; ++ i){
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].width);
        points[edges[i].start].sons[points[edges[i].start].count] = edges[i].end;
        points[edges[i].start].width[points[edges[i].start].count] = edges[i].width;
        points[edges[i].start].count ++;
        // 无向图（此题为有向图）
        // points[edges[i].end].sons[points[edges[i].end].count] = edges[i].start;
        // points[edges[i].end].width[points[edges[i].end].count] = edges[i].width;
        // points[edges[i].end].count ++;
    }
    for(int i = 1; i <= 5; ++ i){
        for(int j = points[i].count - 1; j >= 0; -- j){
            printf("<%d,%d>(%d) ", i, points[i].sons[j], points[i].width[j]);
        }
        printf("\n");
    }
    return 0;
}
#pragma endregion