/*
    题目描述
    Farmer John 的 NN（1 \leq N \leq 10^51≤N≤10 
    5
    ）头奶牛中出现了 KK（1 \leq K \leq 250001≤K≤25000）只坏蛋！这些坏蛋在奶牛排队的时候总站在一起。现在你需要帮助 FJ 找出他们。
    为了区分，FJ 给每头奶牛发了号牌，上面写着一个 1 \ldots S1…S 之间的数字（1 \leq S \leq 251≤S≤25），虽然这不是个完美的方法，但也有一定作用。现在 FJ 记不得坏蛋们的具体号码，但他给出了一个模式串。原坏蛋的号码相同，模式串中的号码依旧相同，模式串中坏蛋号码的大小关系也和原号码相同。
    例如模式串：1,4,4,3,2,11,4,4,3,2,1，原来的 66 只坏蛋，最前面和最后面的号码相等且最小（不一定是 11），位置 2,32,3 的坏蛋号码相同且最大（不一定是 44）。
    现在有这样一个队列：5, 6, 2, 10, 10, 7, 3, 2, 95,6,2,10,10,7,3,2,9，它的子串 2, 10, 10, 7, 3, 22,10,10,7,3,2 匹配模式串的相等关系和大小关系，这就可能是一个坏蛋团伙。
    请找出所有团伙的可能情况。

    输入格式
    第一行三个整数 N,K,SN,K,S。
    接下来 NN 行，每行一个整数，代表第 ii 奶牛的编号。
    接下来 KK 行，每行一个整数，表示模式串中第 ii 个位置的号码。

    输出格式
    第一行输出一个整数 BB。
    接下来 BB 行，每行一个整数，为一种可能的坏蛋团伙的起始位置。
    所有位置按升序输出。
*/

#include <bits/stdc++.h>
using namespace std;
int N, K, S, *cow, *pattern, *pattern_discre, *pattern_tmp;
queue<int> ans;
int get_index(int x, int *discre){ return lower_bound(discre, discre + K, x) - discre; }
int main(){
    // 初始化
    scanf("%d%d%d", &N, &K, &S);
    cow = new int[N], pattern = new int[K];
    pattern_discre = new int[K];
    // 输入
    for(int i = 0; i < N; ++ i) scanf("%d", &cow[i]);
    for(int i = 0; i < K; ++ i) scanf("%d", &pattern[i]), pattern_discre[i] = pattern[i];
    // 离散化模式串
    sort(pattern_discre, pattern_discre + K);
    unique(pattern_discre, pattern_discre + K) - pattern_discre;
    // 枚举查找
    for(int i = 0; i <= N - K; ++ i){
        // 向临时弹匣填充号牌
        pattern_tmp = new int[K];
        for(int j = 0; j < K; ++ j) pattern_tmp[j] = cow[j + i];
        // 离散化临时弹匣
        sort(pattern_tmp, pattern_tmp + K);
        unique(pattern_tmp, pattern_tmp + K) - pattern_tmp;
        // 是否匹配
        bool isit = true;
        for(int j = 0; j < K; ++ j){
            if(get_index(pattern_tmp[j], pattern_tmp) != get_index(pattern_discre[j], pattern_discre)){
                isit = false;
                i += j; // notice
                break;
            }
        }
        if(isit) ans.push(i);
    }
    // 输出
    printf("%d\n", ans.size());
    while(!ans.empty()){
        printf("%d\n", ans.front());
        ans.pop();
    }
    return 0;
}

/*
    草， 下面的被我写废了， 只能放弃了
*/

// int N, K, S, *cow, *pattern, *discre, len_discre, ans_num = 0;
// queue<int> anser;

// int get_index(int x){
//     return lower_bound(discre, discre + len_discre, x) - discre;
// }

// int main(){
//     scanf("%d%d%d", &N, &K, &S);
//     cow = new int[N + 1];
//     pattern = new int[K + 1];
//     discre = new int[K + 1];
//     for(int i = 0; i < N; ++ i) scanf("%d", &cow[i]);
//     for(int i = 0; i < K; ++ i) scanf("%d", &pattern[i]), discre[i] = pattern[i];
//     sort(discre, discre + K);
//     len_discre = unique(discre, discre + K) - discre;
//     int *tmp = new int[K], *tmp_copy = new int[K];
//     for(int i = 0; i <= N - K; ++ i){
//         for(int j = i; j <= K; ++ j) tmp[j] = cow[j], tmp_copy[j] = tmp[j];
//         sort(tmp, tmp + K);
//         int length = unique(tmp, tmp + K) - tmp;
//         if(length == len_discre){
//             bool isit = true;
//             for(int k = 0; k < K; ++ k) if(get_index(tmp_copy[k]) != get_index(cow[k])){
//                 isit = false; break;
//             }
//             if(isit){ anser.push(i); ++ ans_num; }
//         }
//     }
//     printf("%d\n", ans_num);
//     while(!anser.empty()){
//         printf("%d\n", anser.front());
//         anser.pop();
//     }
//     return 0;
// }
