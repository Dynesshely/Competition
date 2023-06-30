#include "bits/stdc++.h"

struct num {
    int len, *arr;

    num build(int l) {
        num n;
        n.len = l;
        int *a = new int[l];
        for (int i = 0; i < l; i++)
            a[i] = 0;
        n.arr = a;
        return n;
    }

    num build(int l, int *a) {
        num n;
        n.len = l, n.arr = a;
        return n;
    }

    void reverse(num *n) {
        for (int i = 0, j = n->len - 1, t; i < j; ++i, --j) {
            t = n->arr[i];
            n->arr[i] = n->arr[j];
            n->arr[j] = t;
        }
    }
    void align2right(num *n) {
        for (int i = n->len - 1; i > 0; --i)
            n->arr[i] = n->arr[i - 1];
        n->arr[0] = 0;
    }
    void print(num *n) {
        for (int i = 0; i < n->len; ++i)
            putchar(n->arr[i] + '0');
    }
    void println(num *n) {
        n->print(n);
        putchar('\n');
    }

    num operator+(num a) {
        int length = len > a.len ? len : a.len, carry = 0;
        num rst = build(length + 1);
        for (int i = len - 1, j = a.len - 1, p = length - 1; i >= 0 || j >= 0; --i, --j, --p) {
            rst.arr[p] = (i >= 0 ? arr[i] : 0) + (j >= 0 ? a.arr[j] : 0) + carry;
            carry = rst.arr[p] / 10;
            rst.arr[p] %= 10;
        }
        rst.align2right(&rst);
        return rst;
    }

    num operator*(num a) {
        int length = len + a.len, carry = 0;
        num rst = build(length);
        for (int i = len - 1, p = length - 1; i >= 0; --i, --p) {
            carry = 0;
            for (int j = a.len - 1, q = p; j >= 0; --j, --q) {
                rst.arr[q] += arr[i] * a.arr[j] + carry;
                carry = rst.arr[q] / 10;
                rst.arr[q] %= 10;
            }
            rst.arr[p - a.len] += carry;
        }
        return rst;
    }
};

void testAdd(num *a, num *b) {
    a->println(a);
    b->println(b);
    num c = *a + *b;
    c.println(&c);
    putchar('\n');
}

void testMul(num *a, num *b) {
    a->println(a);
    b->println(b);
    num c = *a * *b;
    c.println(&c);
    putchar('\n');
}

int main(int argc, char *argv[]) {
    int num1[] = {1, 2, 3, 4, 5}, num2[] = {5, 4, 3, 2, 1};
    int num3[] = {1, 2, 3, 4}, num4[] = {4, 3, 2, 1};
    int num5[] = {1, 2, 3, 4, 5}, num6[] = {5, 4, 3, 2};
    int num7[] = {1, 2, 3, 4}, num8[] = {5, 4, 3, 2, 1};
    int num9[] = {4, 8, 2, 6, 7}, num10[] = {4, 6, 8, 1, 1, 9, 9};
    int num11[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                   1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                   1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                   1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        num12[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7,
                   6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4,
                   3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    num n1 = n1.build(5, num1), n2 = n2.build(5, num2);
    num n3 = n3.build(4, num3), n4 = n4.build(4, num4);
    num n5 = n5.build(5, num5), n6 = n6.build(4, num6);
    num n7 = n7.build(4, num7), n8 = n8.build(5, num8);
    num n9 = n9.build(5, num9), n10 = n10.build(7, num10);
    num n11 = n11.build(18 * 6, num11), n12 = n12.build(18 * 5, num12);

    testAdd(&n1, &n2);
    testAdd(&n3, &n4);
    testAdd(&n5, &n6);
    testAdd(&n7, &n8);
    testAdd(&n9, &n10);
    testAdd(&n11, &n12);

    testMul(&n1, &n2);
    testMul(&n3, &n4);
    testMul(&n5, &n6);
    testMul(&n7, &n8);
    testMul(&n9, &n10);
    testMul(&n11, &n12);

    return 0;
}
