#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 223999;
const int INV2 = (MOD + 1) / 2;
struct Mat { ll a[2][2]; Mat() { memset(a, 0, sizeof(a)); } };
Mat mul(const Mat &A, const Mat &B) {
    Mat C;
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            if (A.a[i][k])
                for (int j = 0; j < 2; ++j)
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}
Mat mpow(Mat A, int e) {
    Mat R; R.a[0][0] = R.a[1][1] = 1;
    for (; e; e >>= 1, A = mul(A, A))
        if (e & 1) R = mul(R, A);
    return R;
}
int main() {
    int k = 114514 / 2;
    Mat M;
    M.a[0][0] = 10; M.a[0][1] = MOD - 1;
    M.a[1][0] = 1;  M.a[1][1] = 0;
    Mat P = mpow(M, k - 1);
    ll y = (P.a[0][0] * 17 + P.a[0][1] * 1) % MOD;
    ll n = ((y * y - 1) % MOD + MOD) % MOD * INV2 % MOD;
    printf("%lld\n", n);
    return 0;
}
