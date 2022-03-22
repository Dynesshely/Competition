#include <bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){
    static char buf[1 << 16], *s, *t; if ( s == t ){
        t = (s = buf) + fread( buf, 1, 1 << 16, stdin );
        if ( s == t ) return(EOF);
    }
    return(*s++);
}
int read(){
    char c; int	w = 1;
    while ( (c = getchar() ) > '9' || c < '0' )
        if ( c == '-' ) w = -1;
    int ans = c - '0';
    while ( (c = getchar() ) >= '0' && c <= '9' )
        ans = (ans << 1) + (ans << 3) + c - '0';
    return(ans * w);
}
void pc( char c, int op ){
    static char buf[1 << 16], *s = buf, *t = buf + (1 << 16);
    (op || ( (*s++ = c) && s == t) ) && ( (fwrite( buf, 1, s - buf, stdout ) ), s = buf);
}
void wt( int x ){ if ( x > 9 ) wt( x / 10 ); pc( '0' + x % 10, 0 ); }
void wts( int x, char op ){ if ( x < 0 ) pc( '-', 0 ), x = -x; wt( x ); pc( op, 0 ); }
const int xx = 2e5 + 7;
int n, a[xx], t[xx], sum[xx], tt[xx];
int lb( int x ){ return(x & - x); }
void add( int x, int y ){ for (; x <= n; x += lb( x ) ) sum[x] += y;}
int ask( int x ){ int ans = 0; for (; x; x -= lb( x ) ) ans += sum[x]; return(ans); }
int main(){
    int T = read();
    while ( T-- ){
        memset( sum, 0, sizeof(sum) );
        memset( t, 0, sizeof(t) );
        memset( tt, 0, sizeof(tt) );
        n = read();
        for ( int i = 1; i <= n; i++ ) a[i] = read();
        int	mn	= 1e9, ept = 0; ll	val	= 0;
        for ( int i = 1; i <= n; i++ ) t[i] = sum[i] = 0;
        set<int>s;
        for ( int i = 1; i <= n; i++ ){
            mn = min( mn, a[i] );
            if ( mn == a[i] ) ept++, tt[a[i]]++, s.insert( a[i] );
            t[a[i]]++; if ( t[a[i]] == 1 ) add( a[i], 1 );
            val += ask( a[i] - 1 ); vector<int>v;
            for ( auto it : s ){
                if ( it > mn && it < a[i] ){
                    tt[it]--; if ( tt[it] == 0 ) v.push_back( it ); ept--;
                }
                if ( it > a[i] ) break;
            }
            for ( auto it : v ) s.erase( it );
            cout << val + i - ept << " \n"[i == n];
        }
    }
    pc( '1', 1 );
    return(0);
}


