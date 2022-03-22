#include <bits/stdc++.h>
#define l_ll long long
#define ReplacementFor_EOF EOF
#define ReplacementFor_T T
#define a_a a
#define a_add add
#define a_ans ans
#define a_ask ask
#define b_buf buf
#define c_c c
#define c_cout cout
#define e_ept ept
#define e_erase erase
#define f_fread fread
#define f_fwrite fwrite
#define g_gc gc
#define g_getchar getchar
#define i_i i
#define i_insert insert
#define i_it it
#define l_lb lb
#define m_memset memset
#define m_min min
#define m_mn mn
#define n_n n
#define o_op op
#define p_pc pc
#define p_push_back push_back
#define r_read read
#define s_s s
#define s_set set
#define s_stdin stdin
#define s_stdout stdout
#define s_sum sum
#define t_t t
#define t_tt tt
#define v_v v
#define v_val val
#define v_vector vector
#define w_w w
#define w_wt wt
#define w_wts wts
#define x_x x
#define x_xx xx
#define y_y y

using namespace std;
char g_gc(){
    static char b_buf[1 << 16], *s_s, *t_t; if ( s_s == t_t ){
        t_t = (s_s = b_buf) + f_fread( b_buf, 1, 1 << 16, s_stdin );
        if ( s_s == t_t ) return(ReplacementFor_EOF);
    }
    return(*s_s++);
}
int r_read(){
    char c_c; int	w_w = 1;
    while ( (c_c = g_getchar() ) > ((char)(0xda5+1702-0x1412)) || c_c < ((char)(0x982+2569-0x135b)) )
        if ( c_c == ((char)(0x49c+8370-0x2521)) ) w_w = -1;
    int a_ans = c_c - ((char)(0xbbd+1080-0xfc5));
    while ( (c_c = g_getchar() ) >= ((char)(0xab+7876-0x1f3f)) && c_c <= ((char)(0x44d+7576-0x21ac)) )
        a_ans = (a_ans << 1) + (a_ans << 3) + c_c - ((char)(0xfba+800-0x12aa));
    return(a_ans * w_w);
}
void p_pc( char c_c, int o_op ){
    static char b_buf[1 << 16], *s_s = b_buf, *t_t = b_buf + (1 << 16);
    (o_op || ( (*s_s++ = c_c) && s_s == t_t) ) && ( (f_fwrite( b_buf, 1, s_s - b_buf, s_stdout ) ), s_s = b_buf);
}
void w_wt( int x_x ){ if ( x_x > 9 ) w_wt( x_x / 10 ); p_pc( ((char)(0x88f+7786-0x26c9)) + x_x % 10, 0 ); }
void w_wts( int x_x, char o_op ){ if ( x_x < 0 ) p_pc( ((char)(0x2000+516-0x21d7)), 0 ), x_x = -x_x; w_wt( x_x ); p_pc( o_op, 0 ); }
const int x_xx = 2e5 + 7;
int n_n, a_a[x_xx], t_t[x_xx], s_sum[x_xx], t_tt[x_xx];
int l_lb( int x_x ){ return(x_x & - x_x); }
void a_add( int x_x, int y_y ){ for (; x_x <= n_n; x_x += l_lb( x_x ) ) s_sum[x_x] += y_y;}
int a_ask( int x_x ){ int a_ans = 0; for (; x_x; x_x -= l_lb( x_x ) ) a_ans += s_sum[x_x]; return(a_ans); }
int main(){
    int ReplacementFor_T = r_read();
    while ( ReplacementFor_T-- ){
        m_memset( s_sum, 0, sizeof(s_sum) );
        m_memset( t_t, 0, sizeof(t_t) );
        m_memset( t_tt, 0, sizeof(t_tt) );
        n_n = r_read();
        for ( int i_i = 1; i_i <= n_n; i_i++ ) a_a[i_i] = r_read();
        int	m_mn	= 1e9, e_ept = 0; l_ll	v_val	= 0;
        for ( int i_i = 1; i_i <= n_n; i_i++ ) t_t[i_i] = s_sum[i_i] = 0;
        s_set<int>s_s;
        for ( int i_i = 1; i_i <= n_n; i_i++ ){
            m_mn = m_min( m_mn, a_a[i_i] );
            if ( m_mn == a_a[i_i] ) e_ept++, t_tt[a_a[i_i]]++, s_s.i_insert( a_a[i_i] );
            t_t[a_a[i_i]]++; if ( t_t[a_a[i_i]] == 1 ) a_add( a_a[i_i], 1 );
            v_val += a_ask( a_a[i_i] - 1 ); v_vector<int>v_v;
            for ( auto i_it : s_s ){
                if ( i_it > m_mn && i_it < a_a[i_i] ){
                    t_tt[i_it]--; if ( t_tt[i_it] == 0 ) v_v.p_push_back( i_it ); e_ept--;
                }
                if ( i_it > a_a[i_i] ) break;
            }
            for ( auto i_it : v_v ) s_s.e_erase( i_it );
            c_cout << v_val + i_i - e_ept << " \n"[i_i == n_n];
        }
    }
    p_pc( ((char)(0x1c18+2615-0x261e)), 1 );
    return(0);
}



