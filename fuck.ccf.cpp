#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int f[maxn];
int find(int x){
  if(f[x]!=x) f[x] = find(f[x]);
  return f[x];
}
void combine(int a, int b) { f[a] = b; }
bool judge(int a, int b){
  return find(a) == find(b);
}
int u[100], n = 100;
int kruskal(int a, int b){
    if(!judge(a, b)) {
        combine(a, b);
        return 1;
    }
}
int main(){
  for(int i = 0; i < n; ++ i) f[i] = i;
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; ++ i){
    int a, b;
    scanf("%d%d", &a, &b);
    u[i] = kruskal(a, b);
  }
  int ans = 0;
  for(int i = 0; i < m; ++ i) ans += u[i];
  printf("%d\n", ans);
  return 0;
}
int main(){
    for(int i = 0; i < n; ++ i)
    u[i] = i;
    const int m = 100;
    kruskal(m, u);
    cin >> u[0];
    cout << u[n] << endl;
    find(u[0]);
    return 0;
}
