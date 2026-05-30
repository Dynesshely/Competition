#!/usr/bin/env python3
"""Solve T723013: 第 114514 小的必胜棋子数 mod 223999"""

MOD = 223999  # prime
TARGET_IDX = 114514


def mat_mul(A, B, mod):
    """2x2 matrix multiplication modulo mod."""
    return [
        [(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod,
         (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod],
        [(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod,
         (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod],
    ]


def mat_pow(M, exp, mod):
    """Fast exponentiation for 2x2 matrix."""
    # Identity matrix
    R = [[1, 0], [0, 1]]
    base = M
    while exp > 0:
        if exp & 1:
            R = mat_mul(R, base, mod)
        base = mat_mul(base, base, mod)
        exp >>= 1
    return R


def compute_y_A(k, mod):
    """Compute a_k (Sequence A) modulo mod.

    Sequence A: y_0=1, y_1=17, y_{k+1}=10*y_k - y_{k-1}
    Returns y_k mod mod.
    """
    if k == 0:
        return 1 % mod
    if k == 1:
        return 17 % mod

    # [y_k, y_{k-1}]^T = M^{k-1} * [17, 1]^T
    M = [[10, -1 % mod], [1, 0]]
    M_pow = mat_pow(M, k - 1, mod)
    y_k = (M_pow[0][0] * 17 + M_pow[0][1] * 1) % mod
    return y_k


def compute_y_B(k, mod):
    """Compute b_k (Sequence B) modulo mod.

    Sequence B: y_0=-1, y_1=7, y_{k+1}=10*y_k - y_{k-1}
    Returns y_k mod mod.
    """
    if k == 0:
        return (-1) % mod
    if k == 1:
        return 7 % mod

    M = [[10, -1 % mod], [1, 0]]
    M_pow = mat_pow(M, k - 1, mod)
    y_k = (M_pow[0][0] * 7 + M_pow[0][1] * (-1 % mod)) % mod
    return y_k


def main():
    mod = MOD
    idx = TARGET_IDX

    # 114514 is even -> from Sequence A, index = idx/2
    assert idx % 2 == 0
    m = idx // 2  # = 57257

    y = compute_y_A(m, mod)

    # n = (y^2 - 1) / 2 mod mod
    # Division by 2 in F_p: multiply by (mod+1)//2
    inv2 = (mod + 1) // 2  # = 112000
    n = ((y * y - 1) % mod) * inv2 % mod

    print(f"a_{m} mod {mod} = {y}")
    print(f"Answer (n mod {mod}) = {n}")

    # Verification: compute small terms to verify
    print("\n--- Verification (small terms) ---")
    for i in range(1, 6):
        a = compute_y_A(i, 10**18)  # exact value (no mod needed for small i)
        b = compute_y_B(i, 10**18)
        n_a = (a * a - 1) // 2
        n_b = (b * b - 1) // 2
        print(f"  k={i}: b_k={b} (n={n_b}), a_k={a} (n={n_a})")

    # Verify pattern: b_1 < a_1 < b_2 < a_2 < ...
    vals = []
    for i in range(1, 4):
        a = compute_y_A(i, 10**18)
        b = compute_y_B(i, 10**18)
        vals.append(((b * b - 1) // 2, 'B', i))
        vals.append(((a * a - 1) // 2, 'A', i))
    vals.sort()
    print(f"\nSorted n values: {[(v, src, i) for v, src, i in vals]}")

    # Verify that index 114514 is even -> from A
    # First few: B1(1st), A1(2nd), B2(3rd), A2(4th), ...
    # So position 2 is A1, position 4 is A2, position 114514 is A_{57257}
    print(f"\n114514 is {'even' if idx % 2 == 0 else 'odd'} → from Sequence {'A' if idx % 2 == 0 else 'B'}, index {m}")


if __name__ == '__main__':
    main()
