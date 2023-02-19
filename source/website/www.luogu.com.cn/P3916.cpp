#pragma region 一

// #include<bits/stdc++.h>
// using namespace std;

// const int MaxN = 100010;
// int n, m;
// vector<int> gra[MaxN];
// int vis[MaxN];

// void dfs(int now, int head) {	
//     vis[now] = head;

//     for (int k = 0; k < gra[now].size(); k++) {
//         int to = gra[now][k];
//         if (!vis[to]) {
//             dfs(to, head);
//         }
//     }
// }

// int main() {
//     cin >> n >> m;

//     while (m--) {
//         int u, v;
//         cin >> u >> v;
//         gra[v].push_back(u);
//     }

//     memset(vis, 0, sizeof(vis));

//     for (int i = n; i >= 1; i--) {
//         if (!vis[i]) {
//             vis[i] = i;
//             dfs(i, i);
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         cout << vis[i] << " ";
//     printf("\n");
//     return 0;
// }

#pragma endregion

#pragma region 二

// #include <bits/stdc++.h>
// #define MAXN 100001
// using namespace std;
// vector<int> points[MAXN];
// int n, m, flag[MAXN];
// void dfs(int num, int mm){
//     flag[num] = mm;
//     for(int i = 0; i < points[num].size(); i++){
//         int to = points[num][i];
//         if(!flag[to]){
//             dfs(to, mm);
//         }
//     }
// }
// int main(){
//     scanf("%d %d", &n, &m);
//     memset(flag, 0, sizeof(flag));
//     for(int i = 0; i < m; i++){
//         int start, end;
//         scanf("%d %d", &start, &end);
//         points[end].push_back(start);
//     }
//     for(int i = n; i > 0; i --){
//         if(flag[i] == 0){
//             flag[i] = i;
//             dfs(i, i);
//         }
//     }
//     for(int i = 1; i <= n; ++ i){
//         printf("%d ", flag[i]);
//     }
//     printf("\n");
//     return 0;
// }

#pragma endregion

#pragma region 三

#include <bits/stdc++.h>
#define MAXM 100
using namespace std;
struct point{
    int id, sonsum = 0, sons[MAXM];
};
int via[100001];
void dfs(point p, point points[], int mm){
    via[p.id] = mm;
    for(int i = 0; i < p.sonsum; ++ i){
        if(!via[points[p.sons[i]].id]){
            dfs(points[p.sons[i]], points, mm);
        }
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    memset(via, 0, sizeof(via));
    point points[n + 1];
    for(int i = 1; i <= n; ++ i){
        points[i].id = i;
    }
    for(int i = 1; i <= m; ++ i){
        int start, end;
        scanf("%d %d", &start, &end);
        points[end].sons[points[end].sonsum++] = start;
    }
    for(int i = n; i >= 1; -- i){
        if(!via[points[i].id]){
            dfs(points[i], points, points[i].id);
        }
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d ", via[points[i].id]);
    }
    printf("\n");
    return 0;
}

#pragma endregion

#pragma region MLE-版本

// #include <bits/stdc++.h>
// #define MAXM 10
// using namespace std;
// struct point{
//     int id, sonsum = 0, sons[MAXM];
// };
// int big;
// void dfs(point p, point points[]){
//     big = max(p.id, big);
//     if(p.sonsum > 0){
//         for(int i = 0; i < p.sonsum; ++ i){
//             dfs(points[p.sons[i]], points);
//         }
//     }
// }
// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
//     point points[n + 1];
//     for(int i = 1; i <= n; ++ i){
//         points[i].id = i;
//     }
//     for(int i = 1; i <= m; ++ i){
//         int start, end;
//         scanf("%d %d", &start, &end);
//         points[start].sons[points[start].sonsum++] = end;
//     }
//     for(int i = 1; i <= n; ++ i){
//         big = points[i].id;
//         dfs(points[i], points);
//         printf("%d ", big);
//     }
//     printf("\n");
//     return 0;
// }

#pragma endregion
