#include <bits/stdc++.h>
using namespace std;
const int Max = 101;
int n, m, ans, f[Max][Max];
int main(){
    scanf("%d %d", &n, &m);
    memset(f, 0x3f3f3f, sizeof(f));
    for(int i = 1; i <= m; ++ i){
      int a, b, c; scanf("%d %d %d", &a, &b, &c); f[a][b] = f[b][a] = c;
    }
    for(int k = 1; k <= n; ++ k){
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for(int i = 2; i <= n; ++ i){
        ans = max(ans, f[1][i]);
    }
    printf("%d\n", ans);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int area = 101;
// const int INF = 0x7f7f7f7f;
// int n, m;
// bool vis[area];
// vector<int> towers[area];
// int dist[area][area], dis[area];
// void Dijkstra(int s){
//     vis[s] = true;
//     for (int i = 1; i <= n; ++ i)
//         dis[i] = dist[s][i];
//     dis[s] = 0;
//     for (int i = 1; i <= n; ++ i){
//         int tmp_pos, fmin = INF;
//         for(int i = 1; i < n; ++ i)
//             if (!vis[i] && dis[i] < fmin) {
//                 fmin = dis[i];
//                 tmp_pos = i;
//             }
//         vis[tmp_pos] = true;
//         for (int j = 1; j <= n; j++) {
//             if (!vis[j] && dis[tmp_pos] + dist[tmp_pos][j] < dis[j])
//                 dis[j] = dis[tmp_pos] + dist[tmp_pos][j];
//         }
//     }
// }
// int main(){
//     scanf("%d %d", &n, &m);
//     for(int i = 1; i <= m; ++ i){
//         int a, b, c; vis[i] = false;
//         scanf("%d %d %d", &a, &b, &c);
//         towers[a].push_back(b);
//         dist[a][b] = c, dist[b][a] = c;
//     }
//     Dijkstra(1);
//     printf("%d\n", dis[n]);
//     return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
// const int MaxN = 110;
// const int INF = 0x7f7f7f7f;
// int n, m;
// int re[MaxN][3];
// double mapp[MaxN][MaxN];
// double dis[MaxN];
// bool vis[MaxN];
// void Dijkstra(int s){
//     vis[s] = true;
//     for (int i = 1; i <= n; i++)
//         dis[i] = mapp[s][i];
//     dis[s] = 0;
//     for (int i = 1; i < n; i++) {
//         int tmp_pos;
//         int fmin = INF;
//         for(int i=1;i<=n;i++)
//             if (!vis[i] && dis[i] < fmin) {
//                 fmin = dis[i];
//                 tmp_pos = i;
//             }
//         vis[tmp_pos] = true;
//         for (int j = 1; j <= n; j++) {
//             if (!vis[j] && dis[tmp_pos] + mapp[tmp_pos][j] < dis[j])
//                 dis[j] = dis[tmp_pos] + mapp[tmp_pos][j];
//         }
//     }
// }
// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> re[i][0] >> re[i][1];
//     memset(mapp, 0x7f, sizeof(mapp));
//     cin >> m;
//     int p1, p2;
//     for (int i = 1; i <= m; i++) {
//         cin >> p1 >> p2;
//         mapp[p1][p2] =mapp[p2][p1] =sqrt(double((re[p1][0] - re[p2][0]) * (re[p1][0] - re[p2][0])) + double((re[p1][1] - re[p2][1]) * (re[p1][1] - re[p2][1])));
//     }
//     int s, t;
//     cin >> s >> t;
//     Dijkstra(s);
//     printf("%.2f\n", dis[t]);
//     return 0;
// }