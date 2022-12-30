#include "bits/stdc++.h"

struct num{
    int len, *arr;

    num build(int l){
        num n; n.len = l;
        int *a = new int[l];
        for(int i = 0; i < l; i++) a[i] = 0;
        n.arr = a;
        return n;
    }

    num build(int l, int *a){
        num n; n.len = l, n.arr = a;
        return n;
    }

    void reverse(num *n){
        for(int i = 0, j = n->len - 1, t; i < j; ++i, --j){
            t = n->arr[i];
            n->arr[i] = n->arr[j];
            n->arr[j] = t;
        }
    }

    void print(num *n){ for(int i = 0; i < n->len; ++i) putchar(n->arr[i] + '0'); }
    void println(num *n){ n->print(n); putchar('\n'); }

    num operator +(num a){
        int bl, ll, al, carry = 0; //  bl -> bigger length, ll -> lower length, al -> actual length, carry -> carry
        if(len > a.len) bl = len, ll = a.len, al = bl + 1;
        else bl = a.len, ll = len, al = bl + 1;
        num rst = build(al);
        for(int i = 0; i < ll; i++){
            int sum = arr[i] + a.arr[i] + carry;    //  sum of this turn sum plus last turn carry
            if (sum >= 10) rst.arr[i] = 0, carry = 1;
            else rst.arr[i] = sum, carry = 0;
        }
        if(carry > 0) rst.arr[bl] = 1;
        rst.reverse(&rst);
        return rst;
    }
};

int main(int argc, char* argv[]){
    int num1[] = {1, 2, 3, 4, 5}, num2[] = {5, 4, 3, 2, 1};
    num n1 = n1.build(5, num1), n2 = n2.build(5, num2);
    n1.println(&n1);
    n2.println(&n2);
    num rst = n1 + n2;
    rst.println(&rst);
    return 0;
}




