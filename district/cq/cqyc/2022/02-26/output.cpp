#include <bits/stdc++.h>
using namespace std;

/*
    这题因该是有更优解的
    但是奈何我功力不够
    只能就此作罢 😂
    考后还将温习此题
*/

/*
    预估: 最多50分
    就是按照 50% 数据点设计的算法
    谁知道 2^63 怎么存啊
    肯定有某种数据结构和算法可以解决
    奈何我不会。。。
*/

long long T, l, r, k;
int main(){
    freopen("output.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%lld", &T);
    for(long long i = 0; i < T; ++ i){
        scanf("%lld %lld %lld", &l, &r, &k);
        if(k > r){
            if(l == 1) printf("1 ");
            else printf("None.\n");
        }else if(k > l){
            if(l <= 1) printf("1 ");
            for(long long j = 0, src = k; true; ++ j){
                if(k > r || k < 0) break;
                else{
                    printf("%lld ", k);
                    k *= src;
                }
            }
            printf("\n");
        }else if(k == 0){
            if(l <= 0 && r >= 0)
                if(r >= 1) printf("0 1\n");
                else printf("0\n");
        }else{
            if(l == 1) printf("1 ");
            for(long long j = 0, src = k; true; ++ j){
                if(k > r || k <= 0) break;
                else{
                    if(k >= l && k <= r) printf("%lld ", k);
                    k *= src;
                }
                // printf("debug >> %d\n", k);
            }
            printf("\n");
        }
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 0x7fffffff;
// int T, l, r, k, *f;
// int mypow(int x, int ks){
// 	if(ks == 0) return 1;
// 	else return pow(x, ks);
// }
// queue<int> *s[maxn];
// int main(){
// 	scanf("%d", &T);
// 	f = new int[maxn];
// 	for(int i = 0; i < maxn; ++ i){
// 		queue<int> arr;
// 		s[i] = &arr;
// 		int j = i;
// 		while(j <= maxn){
// 			arr.push(j);
// 			++ f[i];
// 			j *= j;
// 		}
// 	}

// 	cout << maxn << endl;

// 	for(int i = 0; i < T; ++ i){
// 		scanf("%lld %lld %lld", &l, &r, &k);
// 		for(long long j = l; j < r; ++ j){
            
// 		}
// 	}
// 	return 0;
// } 
