#include <bits/stdc++.h>
using namespace std;
const int	maxn = 2e5 + 7, K = 400;
int		n, k, q, cnt, ans, tot, a[maxn], b[maxn], c[maxn];
int		sum[maxn], id[maxn], L[maxn], f[maxn], num[1007][16507];

inline void update1( int p, int v );
inline void update2( int p, int v );
inline void update( int pla, int nu );
int main(){
    register int	i, j;
    char		s[5];
    scanf( "%d %d %d", &n, &k, &q );
    for ( i = 1; i <= n; ++i )
        scanf( "%d", &a[i] );
    for ( i = 1; i <= n; ++i )
        scanf( "%d", &b[i] );
    ++n;
    if ( n / k >= K ){
        for ( i = 1; i <= k; ++i )
            for ( j = i; j <= n; j += k ){
                if ( ( (j - 1) / k + 1) % K == 1 ){
                    L[++cnt]	= j;
                    num[cnt][0]	= min( K, (n - j) / k + 1 );
                }
                id[j] = cnt;
            }
    }
    for ( i = 1; i <= n; ++i )
        update( i, a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1] );
    if ( tot )
        puts( "-1" );
    else printf( "%d\n", ans );
    while ( q-- ){
        scanf( "%s", s + 1 );
        scanf( "%d %d", &i, &j );
        if ( s[1] == 'a' )
            a[i] = j;
        else b[i] = j;
        update( i, a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1] );
        if ( i != n )
            ++i, update( i, a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1] );
        if ( tot )
            puts( "-1" );
        else printf( "%d\n", ans );
    }
    return(0);
}



inline void update( int pla, int nu ){
    if ( n / k < K )
        update1( pla, nu ^ c[pla] );
    else update2( pla, nu ^ c[pla] );
    c[pla] = nu;
}

inline void update2( int p, int v ){
    register int i;
    if ( !v )
        return;
    for ( i = p; id[i] == id[p]; i += k ){
        if ( (sum[i] ^ f[id[p]]) == 0 )
            ++ans;
        --num[id[p]][sum[i]];
        sum[i] ^= v;
        ++num[id[p]][sum[i]];
        if ( (sum[i] ^ f[id[p]]) == 0 )
            --ans;
    }
    for ( i = id[p] + 1; i <= cnt && L[i] % k == p % k; ++i ){
        ans	+= num[i][f[i]];
        f[i]	^= v;
        ans	-= num[i][f[i]];
    }
    i = p % k + ( (n - p % k) / k) * k;
    if ( (sum[i] ^ f[id[i]]) == 0 )
        --tot;
    if ( (sum[i] ^ f[id[i]]) == v )
        ++tot;
}

inline void update1( int p, int v ){
    register int i;
    if ( !v )
        return;
    for ( i = p; i <= n; i += k ){
        sum[i] ^= v;
        if ( sum[i] == 0 )
            --ans;
        if ( sum[i] == v )
            ++ans;
    }
    i = p % k + ( (n - p % k) / k) * k;
    if ( sum[i] == 0 )
        --tot;
    if ( sum[i] == v )
        ++tot;
}


