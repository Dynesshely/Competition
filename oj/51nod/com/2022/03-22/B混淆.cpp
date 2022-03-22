#include <bits/stdc++.h>
#define ReplacementFor_ll long long
#define ReplacementFor_EOF EOF
#define ReplacementFor_T T
#define ReplacementFor_a a
#define ReplacementFor_add add
#define ReplacementFor_ans ans
#define ReplacementFor_ask ask
#define ReplacementFor_buf buf
#define ReplacementFor_c c
#define ReplacementFor_cout cout
#define ReplacementFor_ept ept
#define ReplacementFor_erase erase
#define ReplacementFor_fread fread
#define ReplacementFor_fwrite fwrite
#define ReplacementFor_gc gc
#define ReplacementFor_getchar getchar
#define ReplacementFor_i i
#define ReplacementFor_insert insert
#define ReplacementFor_it it
#define ReplacementFor_lb lb
#define ReplacementFor_memset memset
#define ReplacementFor_min min
#define ReplacementFor_mn mn
#define ReplacementFor_n n
#define ReplacementFor_op op
#define ReplacementFor_pc pc
#define ReplacementFor_push_back push_back
#define ReplacementFor_read read
#define ReplacementFor_s s
#define ReplacementFor_set set
#define ReplacementFor_stdin stdin
#define ReplacementFor_stdout stdout
#define ReplacementFor_sum sum
#define ReplacementFor_t t
#define ReplacementFor_tt tt
#define ReplacementFor_v v
#define ReplacementFor_val val
#define ReplacementFor_vector vector
#define ReplacementFor_w w
#define ReplacementFor_wt wt
#define ReplacementFor_wts wts
#define ReplacementFor_x x
#define ReplacementFor_xx xx
#define ReplacementFor_y y

using namespace std;
char ReplacementFor_gc(){
    static char ReplacementFor_buf[1 << 16], *ReplacementFor_s, *ReplacementFor_t; if ( ReplacementFor_s == ReplacementFor_t ){
        ReplacementFor_t = (ReplacementFor_s = ReplacementFor_buf) + ReplacementFor_fread( ReplacementFor_buf, 1, 1 << 16, ReplacementFor_stdin );
        if ( ReplacementFor_s == ReplacementFor_t ) return(ReplacementFor_EOF);
    }
    return(*ReplacementFor_s++);
}
int ReplacementFor_read(){
    char ReplacementFor_c; int	ReplacementFor_w = 1;
    while ( (ReplacementFor_c = ReplacementFor_getchar() ) > ((char)(0xda5+1702-0x1412)) || ReplacementFor_c < ((char)(0x982+2569-0x135b)) )
        if ( ReplacementFor_c == ((char)(0x49c+8370-0x2521)) ) ReplacementFor_w = -1;
    int ReplacementFor_ans = ReplacementFor_c - ((char)(0xbbd+1080-0xfc5));
    while ( (ReplacementFor_c = ReplacementFor_getchar() ) >= ((char)(0xab+7876-0x1f3f)) && ReplacementFor_c <= ((char)(0x44d+7576-0x21ac)) )
        ReplacementFor_ans = (ReplacementFor_ans << 1) + (ReplacementFor_ans << 3) + ReplacementFor_c - ((char)(0xfba+800-0x12aa));
    return(ReplacementFor_ans * ReplacementFor_w);
}
void ReplacementFor_pc( char ReplacementFor_c, int ReplacementFor_op ){
    static char ReplacementFor_buf[1 << 16], *ReplacementFor_s = ReplacementFor_buf, *ReplacementFor_t = ReplacementFor_buf + (1 << 16);
    (ReplacementFor_op || ( (*ReplacementFor_s++ = ReplacementFor_c) && ReplacementFor_s == ReplacementFor_t) ) && ( (ReplacementFor_fwrite( ReplacementFor_buf, 1, ReplacementFor_s - ReplacementFor_buf, ReplacementFor_stdout ) ), ReplacementFor_s = ReplacementFor_buf);
}
void ReplacementFor_wt( int ReplacementFor_x ){ if ( ReplacementFor_x > 9 ) ReplacementFor_wt( ReplacementFor_x / 10 ); ReplacementFor_pc( ((char)(0x88f+7786-0x26c9)) + ReplacementFor_x % 10, 0 ); }
void ReplacementFor_wts( int ReplacementFor_x, char ReplacementFor_op ){ if ( ReplacementFor_x < 0 ) ReplacementFor_pc( ((char)(0x2000+516-0x21d7)), 0 ), ReplacementFor_x = -ReplacementFor_x; ReplacementFor_wt( ReplacementFor_x ); ReplacementFor_pc( ReplacementFor_op, 0 ); }
const int ReplacementFor_xx = 2e5 + 7;
int ReplacementFor_n, ReplacementFor_a[ReplacementFor_xx], ReplacementFor_t[ReplacementFor_xx], ReplacementFor_sum[ReplacementFor_xx], ReplacementFor_tt[ReplacementFor_xx];
int ReplacementFor_lb( int ReplacementFor_x ){ return(ReplacementFor_x & - ReplacementFor_x); }
void ReplacementFor_add( int ReplacementFor_x, int ReplacementFor_y ){ for (; ReplacementFor_x <= ReplacementFor_n; ReplacementFor_x += ReplacementFor_lb( ReplacementFor_x ) ) ReplacementFor_sum[ReplacementFor_x] += ReplacementFor_y;}
int ReplacementFor_ask( int ReplacementFor_x ){ int ReplacementFor_ans = 0; for (; ReplacementFor_x; ReplacementFor_x -= ReplacementFor_lb( ReplacementFor_x ) ) ReplacementFor_ans += ReplacementFor_sum[ReplacementFor_x]; return(ReplacementFor_ans); }
int main(){
    int ReplacementFor_T = ReplacementFor_read();
    while ( ReplacementFor_T-- ){
        ReplacementFor_memset( ReplacementFor_sum, 0, sizeof(ReplacementFor_sum) );
        ReplacementFor_memset( ReplacementFor_t, 0, sizeof(ReplacementFor_t) );
        ReplacementFor_memset( ReplacementFor_tt, 0, sizeof(ReplacementFor_tt) );
        ReplacementFor_n = ReplacementFor_read();
        for ( int ReplacementFor_i = 1; ReplacementFor_i <= ReplacementFor_n; ReplacementFor_i++ ) ReplacementFor_a[ReplacementFor_i] = ReplacementFor_read();
        int	ReplacementFor_mn	= 1e9, ReplacementFor_ept = 0; ReplacementFor_ll	ReplacementFor_val	= 0;
        for ( int ReplacementFor_i = 1; ReplacementFor_i <= ReplacementFor_n; ReplacementFor_i++ ) ReplacementFor_t[ReplacementFor_i] = ReplacementFor_sum[ReplacementFor_i] = 0;
        ReplacementFor_set<int>ReplacementFor_s;
        for ( int ReplacementFor_i = 1; ReplacementFor_i <= ReplacementFor_n; ReplacementFor_i++ ){
            ReplacementFor_mn = ReplacementFor_min( ReplacementFor_mn, ReplacementFor_a[ReplacementFor_i] );
            if ( ReplacementFor_mn == ReplacementFor_a[ReplacementFor_i] ) ReplacementFor_ept++, ReplacementFor_tt[ReplacementFor_a[ReplacementFor_i]]++, ReplacementFor_s.ReplacementFor_insert( ReplacementFor_a[ReplacementFor_i] );
            ReplacementFor_t[ReplacementFor_a[ReplacementFor_i]]++; if ( ReplacementFor_t[ReplacementFor_a[ReplacementFor_i]] == 1 ) ReplacementFor_add( ReplacementFor_a[ReplacementFor_i], 1 );
            ReplacementFor_val += ReplacementFor_ask( ReplacementFor_a[ReplacementFor_i] - 1 ); ReplacementFor_vector<int>ReplacementFor_v;
            for ( auto ReplacementFor_it : ReplacementFor_s ){
                if ( ReplacementFor_it > ReplacementFor_mn && ReplacementFor_it < ReplacementFor_a[ReplacementFor_i] ){
                    ReplacementFor_tt[ReplacementFor_it]--; if ( ReplacementFor_tt[ReplacementFor_it] == 0 ) ReplacementFor_v.ReplacementFor_push_back( ReplacementFor_it ); ReplacementFor_ept--;
                }
                if ( ReplacementFor_it > ReplacementFor_a[ReplacementFor_i] ) break;
            }
            for ( auto ReplacementFor_it : ReplacementFor_v ) ReplacementFor_s.ReplacementFor_erase( ReplacementFor_it );
            ReplacementFor_cout << ReplacementFor_val + ReplacementFor_i - ReplacementFor_ept << " \n"[ReplacementFor_i == ReplacementFor_n];
        }
    }
    ReplacementFor_pc( ((char)(0x1c18+2615-0x261e)), 1 );
    return(0);
}



