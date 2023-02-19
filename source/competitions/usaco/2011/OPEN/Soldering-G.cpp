#include <bits/stdc++.h>
using namespace std;
const int N = 50001;
struct st{
    int l; long long co;
    st(){} st(int x, long long y){ l = x; co = y;}
    long long cal(){ return co + l * l; }
    bool operator <(const st x) const{ return l < x.l || (l  ==  x.l && co < x.co);}
};
vector <st> f[N], g; vector <int> l[N];
int n, i, x, y; bool vis[N];

void dp(int x, int d);

int main(){
        scanf("%d", &n);
        for (i = 1; i < n; ++ i) {
            scanf("%d%d", &x, &y);
            l[x].push_back(y); l[y].push_back(x);
        }
        dp(1, 0); printf("%lld\n", f[0][0].cal());
}

void dp(int x, int d){
    vis[x] = 1; f[d].clear(); bool leaf = 1;
    int m1 = l[x].size(), m2, m3;
    for (int k = 0;k<m1;k++)
        if (!vis[l[x][k]]){
            leaf = 0; dp(l[x][k], d+1);
            m3 = f[d+1].size();
            for (int i = 0;i<m3;i++) f[d+1][i].l++;
            if (!f[d].size()){f[d] = f[d+1]; continue;}
            g.clear(); m2 = f[d].size();
            for (int i = 0;i<m2;i++)
                for (int j = 0;j<m3;j++)
                    if (!f[d][i].l) g.push_back(st(0, f[d][i].co+f[d+1][j].cal()));
                    else{
                        g.push_back(st(f[d][i].l, f[d][i].co+f[d+1][j].cal()));
                        g.push_back(st(f[d+1][j].l, f[d+1][j].co+f[d][i].cal()));
                        g.push_back(st(0, f[d][i].cal()+f[d+1][j].cal()+((f[d][i].l*f[d+1][j].l)<<1)));
                    }
            sort(g.begin(), g.end());
            int num = 0; m2 = g.size();
            for (int i = 1;i<m2;i++) if (g[i].cal()<g[num].cal()) g[++num] = g[i];
            g.resize(num+1);
            f[d] = g;
        }
    if (leaf) f[d].push_back(st(0, 0));
}
