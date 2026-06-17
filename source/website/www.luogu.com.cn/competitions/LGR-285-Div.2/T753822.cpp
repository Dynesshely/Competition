/**
 * T753822 玩具 — LGR-285 Div.2
 *
 * 5 列圆形区域排列, 1/3/5 列各 H=341799 个, 2/4 列各 2 个.
 * 相邻(相切)区域不能同时为元音. 求方案数 mod 998244353.
 *
 * 图结构推断:
 *   5 列并列, 2/4 列仅存在于顶部(第1行)和底部(第H行).
 *   顶部链: c1[1]—c2[1]—c3[1]—c4[1]—c5[1]
 *   底部链: c1[H]—c2[H]—c3[H]—c4[H]—c5[H]
 *   垂直链: 列1/3/5 各自从顶到底
 *
 * 解法: 枚举 10 个边界顶点 V/C 状态(2^10=1024),
 * 检查水平约束, 垂直链内部用矩阵快速幂.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll VOWEL_CHOICES = 5;
const ll CONS_CHOICES = 21;
const int H = 341799;

struct Mat { ll a[2][2]{}; ll* operator[](int i) { return a[i]; } };

Mat mul(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            if (A.a[i][k])
                for (int j = 0; j < 2; j++)
                    C[i][j] = (C[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}

Mat mpow(Mat A, int e) {
    Mat R; R[0][0] = R[1][1] = 1;
    for (; e; e >>= 1, A = mul(A, A))
        if (e & 1) R = mul(R, A);
    return R;
}

int main() {
    // 转移矩阵 M: V->C=21, C->V=5, C->C=21, V->V=0
    Mat M, Cp;
    M[0][0] = 0;          M[0][1] = CONS_CHOICES;
    M[1][0] = VOWEL_CHOICES; M[1][1] = CONS_CHOICES;
    // 相容矩阵 C: V-V=0 其余=1
    Cp[0][0] = 0; Cp[0][1] = 1;
    Cp[1][0] = 1; Cp[1][1] = 1;

    Mat Mp = mpow(M, H - 2);

    // chain_ways[a][b] = (e_a * M^(H-2) * C)[b]
    ll cw[2][2]{};
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int k = 0; k < 2; k++)
                cw[a][b] = (cw[a][b] + Mp[a][k] * Cp[k][b]) % MOD;

    ll ans = 0;
    const int TOTAL = 1 << 10;
    const ll choice[2] = {VOWEL_CHOICES, CONS_CHOICES};

    for (int mask = 0; mask < TOTAL; mask++) {
        const int s1t = (mask >> 9) & 1, s1b = (mask >> 8) & 1;
        const int s2t = (mask >> 7) & 1, s2b = (mask >> 6) & 1;
        const int s3t = (mask >> 5) & 1, s3b = (mask >> 4) & 1;
        const int s4t = (mask >> 3) & 1, s4b = (mask >> 2) & 1;
        const int s5t = (mask >> 1) & 1, s5b = (mask >> 0) & 1;

        // 顶部水平 V-V?
        if (!s1t && !s2t || !s2t && !s3t || !s3t && !s4t || !s4t && !s5t) continue;
        // 底部水平 V-V?
        if (!s1b && !s2b || !s2b && !s3b || !s3b && !s4b || !s4b && !s5b) continue;

        ll ways = cw[s1t][s1b] * cw[s3t][s3b] % MOD * cw[s5t][s5b] % MOD;
        ways = ways * choice[s1t] % MOD * choice[s1b] % MOD
               * choice[s2t] % MOD * choice[s2b] % MOD
               * choice[s3t] % MOD * choice[s3b] % MOD
               * choice[s4t] % MOD * choice[s4b] % MOD
               * choice[s5t] % MOD * choice[s5b] % MOD;
        ans = (ans + ways) % MOD;
    }

    cout << ans << endl;
    return 0;
}
