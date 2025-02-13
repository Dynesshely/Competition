#include <cstdio>
using namespace std;
int         n, i, j, k, t, pd, m;
inline bool c7(int x) {
    int remain = 0;
    while (x) {
        remain = x % 10;
        if (remain == 7)
            return true;
        x = x / 10;
    }
    return false;
}
inline void ha(int x, int y, int z, int a) {
    t = z;
    for (i = x; i <= y; i++) {
        t += a;
        // if(i % 7 == 0 || c7(i)) a = -a;
        if (i % 7 == 0)
            a = -a;
        else {
            k = i;
            while (k) {
                if (k % 10 == 7) {
                    a = -a;
                    break;
                }
                k /= 10;
            }
        }
        if (t == 0)
            t = 1337;
        if (t == 1338)
            t = 1;
    }
    printf("%d\n", t);
}
int main() {
    scanf("%d", &n);
    if (n < 5e7) {
        ha(1, n, 0, 1);
    } else if (n < 1e8) {
        ha(5e7, n, 157, -1);
    } else if (n < 1e8 + 5e7) {
        ha(1e8, n, 547, 1);
    } else if (n < 2e8) {
        ha(1e8 + 5e7, n, 346, -1);
    } else if (n < 2e8 + 5e7) {
        ha(2e8, n, 867, -1);
    } else if (n < 3e8) {
        ha(2e8 + 5e7, n, 892, 1);
    } else if (n < 3e8 + 5e7) {
        ha(3e8, n, 893, -1);
    } else if (n < 4e8) {
        ha(3e8 + 5e7, n, 1212, -1);
    } else if (n < 4e8 + 5e7) {
        ha(4e8, n, 63, 1);
    } else if (n < 5e8) {
        ha(4e8 + 5e7, n, 893, -1);
    } else if (n < 5e8 + 5e7) {
        ha(5e8, n, 1302, -1);
    } else if (n < 6e8) {
        ha(5e8 + 5e7, n, 1055, 1);
    } else if (n < 6e8 + 5e7) {
        ha(6e8, n, 98, -1);
    } else if (n < 7e8) {
        ha(6e8 + 5e7, n, 957, 1);
    } else if (n < 7e8 + 5e7) {
        ha(7e8, n, 1279, -1);
    } else if (n < 8e8) {
        ha(7e8 + 5e7, n, 1279, -1);
    } else if (n < 8e8 + 5e7) {
        ha(8e8, n, 1279, -1);
    } else if (n < 9e8) {
        ha(8e8 + 5e7, n, 143, 1);
    } else if (n < 9e8 + 5e7) {
        ha(9e8, n, 959, 1);
    } else if (n <= 1e9) {
        ha(9e8 + 5e7, n, 934, -1);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1e9 + 10;

// int X, cur = 1; // cur -> current person id
// bool way = true; // way: true -> ahead, false -> behind
// bool c7(int x){ int remain = 0; while(x){ remain = x % 10; if (remain == 7) return true; x = x / 10; }
// return false; } int main(){
//     scanf("%d", &X);
//     for(int i = 2; i <= X; ++ i){
//         cur += way ? 1 : -1;
//         if(cur == 0) cur = 1337;
//         else if(cur == 1338) cur = 1;
//         if(i % 7 == 0 || c7(i)) way = !way;
//     }
//     printf("%d\n", cur);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int maxx = 1e9 + 100;
// const int maxp = 1337;
// int T, cur = 1; // cur -> current person id
// bool via[maxx], way = true; // way -> true: ahead, false: behind
// bool c7(int x){ int remain = 0; while(x){ remain = x % 10; if (remain == 7) return true; x = x / 10; }
// return false; } int main(){
//     for(int i = 2; i <= maxx; ++ i)
//         if(via[i] == 0 && c7(i))
//             via[i] = 1;
//         else if(via[i] == 0 && i % 7 == 0)
//             for(int j = i; j <= maxx; j += i) via[j] = 1;
//     scanf("%d", &T);
//     for(int i = 2; i <= T; ++ i){
//         cur += way ? 1 : -1;
//         if(cur == 0) cur = 1337;
//         else if(cur == 1338) cur = 1;
//         way = (via[i] == 1 ? !way : way);
//         // printf(">>\t%d: %d\n", cur, i);
//     }
//     printf("%d\n", cur);
//     return 0;
// }
