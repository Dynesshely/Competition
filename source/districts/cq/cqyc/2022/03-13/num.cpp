#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int n;
long long x = 1, addon = 2, cur = 1;
struct num{
    int index;
    long long value;
    bool isit;
}arr[maxn];
bool isittrue[maxn];
bool cmp(num a, num b){ return a.value < b.value; }

int main(){
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &arr[i].value);
        arr[i].index = i;
        arr[i].isit = false;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    // printf("%d\n", arr[n].value);
    while(x <= arr[n].value){
        if(x < arr[cur].value){
        	// printf("x -> %d < arr[%d].value\n", x, cur);
		    x += addon;
		    ++ addon;
        	continue;
        }else if(x == arr[cur].value){
        	// printf("x -> %d == arr[%d].value\n", x, cur);
            arr[cur].isit = true;
            ++ cur;
        }else if(x > arr[cur].value){
            while(arr[cur].value < x){
        		// printf("x -> %d > arr[%d].value\n", x, cur);
            	++ cur;
			}
            continue;
        }
        x += addon;
        ++ addon;
        // printf("x -> %d, addon -> %d\n", x, addon);
    }

    // for(int i = 1; i <= n; ++ i){
    //     printf("%d:%d:", arr[i].index, arr[i].value);
    //     if(arr[i].isit) printf("Yes "), isittrue[arr[i].index] = true;
    //     else printf("No ");
    // }
    for(int i = 1; i <= n; ++ i)
        if(arr[i].isit) isittrue[arr[i].index] = true;
    for(int i = 1; i <= n; ++ i){
        if(isittrue[i]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

// const int maxn = 10010;
// const long long maxx = 1e18 + 10;
// int n, now = 0, addon = 1, index = 1;
// struct tar{
//     int index, src;
// }arr[maxn];
// bool cmp(tar a, tar b){
//     return a.index < b.index;
// }
// bool outputstatus[maxn];
// int main(){
//     // freopen("num.in", "r", stdin);
//     // freopen("num.out", "w", stdout);

//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++ i){
//         scanf("%d", &arr[i].index);
//         arr[i].src = i;
//     }
//     sort(arr + 1, arr + n + 1, cmp);
//     // for(int i = 1; i <= n; ++ i){
//     //     printf("%d:%d ", arr[i].index, arr[i].src);
//     // }
//     while(now <= arr[n].index){
//         if(index == n) break;
//         if(now == arr[index].index){
//             outputstatus[arr[index].src] = true;
//             ++ index;
//         }
//         now += addon;
//         ++ addon;
//     }
//     for(int i = 1; i <= n; ++ i){
//         if(outputstatus[i]) printf("Yes\n");
//         else printf("No\n");
//     }
//     return 0;
// }
