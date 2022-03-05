#include<bits/stdc++.h>
using namespace std;
const int MaxN = 110;
const int INF = 0x7f7f7f7f;
int n, m;
int re[MaxN][3];
double mapp[MaxN][MaxN];
double dis[MaxN];
bool vis[MaxN];
void Dijkstra(int s){
    vis[s] = true;
    for (int i = 1; i <= n; i++)
        dis[i] = mapp[s][i];
    dis[s] = 0;
    for (int i = 1; i < n; i++) {
        int tmp_pos;
        int fmin = INF;
        for(int i=1;i<=n;i++)
            if (!vis[i] && dis[i] < fmin) {
                fmin = dis[i];
                tmp_pos = i;
            }
        vis[tmp_pos] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[tmp_pos] + mapp[tmp_pos][j] < dis[j])
                dis[j] = dis[tmp_pos] + mapp[tmp_pos][j];
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> re[i][0] >> re[i][1];
    memset(mapp, 0x7f, sizeof(mapp));
    cin >> m;
    int p1, p2;
    for (int i = 1; i <= m; i++) {
        cin >> p1 >> p2;
        mapp[p1][p2] =mapp[p2][p1] =sqrt(double((re[p1][0] - re[p2][0]) * (re[p1][0] - re[p2][0])) + double((re[p1][1] - re[p2][1]) * (re[p1][1] - re[p2][1])));
    }
    int s, t;
    cin >> s >> t;
    Dijkstra(s);
    printf("%.2f\n", dis[t]);
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// const int nn = 101, mm = 100001;
// vector<int> points[nn];
// bool blue[nn];
// int _map[nn][nn], loc[nn][2];
// double dist[nn];
// void dij(int i, int n){
//     int minest = i; double closest = 0x7fffffff;
//     for(int p = 1; p <= n; ++ p){
//         for(int j = 0; j < points[i].size(); ++ j){
//             if(blue[points[i][j]] && dist[i] < closest){
//                 minest = points[i][j]; closest = dist[i];
//             }
//         }
//         blue[minest] = 0;
        
//     }
// }
// int main(){
//     int n, m, s, t, x, y, i, j, index = 1, nt;
//     scanf("%d", &n); nt = n;
//     memset(blue, 1, sizeof(blue));
//     while(n--){ scanf("%d %d", &x, &y); loc[index][0] = x; loc[index][1] = y; }
//     scanf("%d", &m);
//     while(m--){
//         scanf("%d %d", &i, &j); points[i].push_back(j); points[j].push_back(i);
//         _map[i][j] = sqrt(pow(loc[i][0] - loc[j][0], 2) + pow(loc[i][1] - loc[j][1], 2));
//     }
//     scanf("%d %d", &s, &t);
//     dist[s] = 0; dij(s, nt);
//     printf("%0.2f", dist[t]);
//     return 0;
// }


// // Dijkrastl (DJ 算法)
// #include <bits/stdc++.h>
// #define MAXN 100
// #define MAXXY 10000
// #define AREA MAXXY*2+1
// using namespace std;
// struct point{
//     int id, x, y, sonsum = 0, sons[MAXN], fasum = 0, fathers[MAXN], isBlue = 1;
// };
// void Dijkstra(int i, point points[], double distance[][], double flag[]){
//     int minest = i; double mindist = 0x7fffffff;
//     for(int j = 0; j < points[i].sonsum; ++ i){
//         if(points[j].isBlue && distance[j] < mindist){
//             mindist = distance[j]; minest = j;
//         }
//     }

// }
// int main(){
//     int n, m, s, t, index = 1, x, y, i, j;
//     scanf("%d", &n);
//     point points[n + 1];
//     while(n--){
//         scanf("%d %d", &x, &y);
//         points[index].x = x, points[index].y = y, points[index].id = index;
//         index++;
//     }
//     scanf("%d", &m);
//     double distance[n + 1][n + 1], flag[n + 1]; index = 1;
//     while(m--){
//         scanf("%d %d", &i, &j);
//         points[i].sons[points[i].sonsum++] = j, points[j].sons[points[j].sonsum++] = i;
//         points[i].fathers[points[i].fasum++] = j, points[j].fathers[points[j].fasum++] = i;
//         distance[i] = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
//         index++;
//     }
//     memset(flag, 0, sizeof(flag));
//     scanf("%d %d", &s, &t);
//     Dijkstra(s, points, distance);
//     printf("%0.2f\n", flag[t]);
//     return 0;
// }