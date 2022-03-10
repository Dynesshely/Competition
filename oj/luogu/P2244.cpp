#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int n, k, x, indegree[MAXN], outdegree[MAXN];
int max_outdegree = -1, max_outdegree_index = -1;
bool vis[MAXN];

struct node{
    int id;
    vector<int> indegr, outdegr;
}nodes[MAXN];

queue<int> pro_arr, ans;

void win(int a, int b){
    nodes[a].outdegr.push_back(b);
    nodes[b].indegr.push_back(a);
    ++ outdegree[a];
    ++ indegree[b];
}

void updateMax(int i){
    if(outdegree[i] > max_outdegree){
        max_outdegree = outdegree[i];
        max_outdegree_index = i;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        nodes[i].id = i;
        scanf("%d", &k);
        for(int j = 0; j < k; ++ j){
            scanf("%d", &x);
            win(i, x); // i -> x
            updateMax(i); // update max_outdegree_index
        }
    }
    pro_arr.push(max_outdegree_index);
    while(!pro_arr.empty()){
        // 寻找队列当前点不能直接指向的所有的点
        int cur = pro_arr.front(); // 取出当前点
        ans.push(cur); // 记录答案
        pro_arr.pop(); // 弹出当前点
        vis[cur] = true; // 标记当前点已经被访问
        bool flag[MAXN] = {false};
        for(int i = 0; i < outdegree[cur]; ++ i){
            flag[nodes[cur].outdegr[i]] = true;
        }
        // 找出所有不能直接指向的点并放入队列
        for(int i = 1; i <= n; ++ i)
            if(!vis[i] && !flag[i])
                pro_arr.push(i);
    }
    int size = ans.size();
    printf("%d ", size);
    int ans_arr[size];
    for(int i = 1; i <= size; ++ i)
        ans_arr[i] = ans.front(), ans.pop();
    sort(ans_arr + 1, ans_arr + size + 1);
    for(int i = 1; i <= size; ++ i)
        printf("%d ", ans_arr[i]);
    printf("\n");
    return 0;
}

/* 再次失败
const int MAXN = 1000001;
int n, k, x;

struct outdegr_id{
    int outdegree, id;
}outdegrs[MAXN];

queue<int> ans_queue, dfs_queue;

struct node{
    unsigned int id, indegree = 0, outdegree = 0;
    vector<int> fa, son;
}nodes[MAXN];

bool cmp (outdegr_id a, outdegr_id b){
    return a.outdegree > b.outdegree;
}

void dfs(int src){
    ans_queue.push(src);
    int son_num = nodes[src].son.size();
    for(int i = 0; i < son_num; ++ i){
        dfs_queue.push(nodes[src].son[i]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        nodes[i].id = i;
        scanf("%d", &k);
        for(int j = 0; j < k; ++ j){
            scanf("%d", &x); // i 赢了 x
            ++ nodes[i].outdegree;
            nodes[i].son.push_back(x);
            ++ nodes[x].indegree;
            nodes[x].fa.push_back(i);
            outdegrs[i].outdegree = nodes[i].outdegree;
            outdegrs[i].id = i;
        }
    }
    sort(outdegrs + 1, outdegrs + n + 1, cmp);
    dfs(outdegrs[n].id);
    // for(int i = n; i >= 1; -- i){
    //     if(nodes[outdegrs[i].id].outdegree > 0)
    //         dfs_queue.push(outdegrs[i].id);
    // }
    while(!dfs_queue.empty()){
        int cur = dfs_queue.front();
        dfs_queue.pop();
        ans_queue.push(cur);
        dfs(cur);
    }
    printf("%ld ", ans_queue.size());
    return 0;
}
*/

/*
    1. 入度为 0 的点直接加入答案
    2. 入度不为 0 的且出度不为 0 的点直接加入答案
    3. 出度为 0 的点搜索周围
*/

/* 做法 1 -> failed
const int maxn = 1000001;
int n, k, i_win, tmp, ans_arr[maxn];
queue<int> ans;

struct node{
    int id, inedge = 0, outedge = 0;
    vector <int> father;
    vector <int> sons;
}nodes[maxn];

bool contain(int f, int s, int* index){
    int size = nodes[f].sons.size();
    for(int i = 0; i < size; ++ i)
        if(nodes[f].sons[i] == s){
            *index = i; return true;
        }
    return false;
}

bool dfs(int src){ // src -> 要搜索的点 -> 搜索周围两圈
    int fnum = nodes[src].father.size(); // 中心点的父亲数量
    for(int i = 0; i < fnum; ++ i){ // 搜索第一圈
        node* r1 = &nodes[nodes[src].father[i]]; // r1 -> 第一圈的点
        int fr1 = r1->father.size(); // 第一圈的点的父亲数量
        for(int j = 0; j < fr1; ++ j){ // 搜索第二圈
            node* r2 = &nodes[r1->father[j]]; // r2 -> 第二圈的点
            if(contain(r2->id, src, &tmp)) // 如果第二圈的点的父亲中包含中心点
                continue;
            else{
                bool eaten = false; // 第一圈是否有点能吃掉第二圈的点
                for(int k = 0; k < fnum && !eaten; ++ k){ // 搜索第一圈
                    node* r1_1 = &nodes[nodes[src].father[k]]; // r1_1 -> 第一圈的点
                    int fr1_1 = r1_1->sons.size(); // 第一圈的点的父亲数量
                    for(int u = 0; u < fr1_1; ++ u)
                        if(r1_1->sons[u] == r1->father[j]) // 第一圈的点能吃掉第二圈的点
                            eaten = true; break;
                }
                if(!eaten) // 如果第一圈没有点能吃掉第二圈的点
                    return true;
            }
        }
    }
    return false;
}

// bool dfs(int src){ // 能赢返回 true , 否则返回 false
//     int fnum = nodes[src].father.size();
//     bool pass = false;
//     for(int i = 0; i < fnum; ++ i){ // 搜第一圈的点
//         int ffnum = nodes[nodes[src].father[i]].father.size();
//         for(int j = 0, l = 0; j < ffnum; ++ j){ // 搜第二圈的点
//             if(contain(nodes[nodes[src].father[i]].father[j], src, &l))
//                 continue;
//             else{ // 搜第一圈的点看有没有能吃第二圈的点
//                 bool eaten = false;
//                 for(int k = 0; k < fnum; ++ k){ // nodes[src].father[k] -> 第一圈的点
//                     if(eaten) break;
//                     int ssnum = nodes[nodes[src].father[k]].sons.size();
//                     for(int u = 0; u < ssnum; ++ u){ // 搜第一圈的点的子点
//                         if(nodes[nodes[src].father[k]].sons[u] ==
//                             nodes[nodes[src].father[i]].father[j]){
//                             pass = false;
//                             eaten = true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return pass;
// }

int main(){
    for(int i = 1; i <= maxn; ++ i)
        nodes[i].id = i;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &k);
        for(int j = 1, index = -1; j <= k; ++ j){ // 第 j 个点
            scanf("%d", &i_win); // 能赢的点
            if(contain(i_win, i, &index)){
                nodes[i_win].outedge --;
                nodes[i_win].sons.erase(nodes[i_win].sons.begin() + index);
                continue;
            }
            nodes[i].sons.push_back(i_win);
            nodes[i].outedge ++;
            nodes[i_win].father.push_back(i);
            nodes[i_win].inedge ++;
        }
    }

    for(int i = 1; i <= n; ++ i){
        if(nodes[i].inedge == 0) // 入度为 0 的点直接加入答案
            ans.push(i);
        else if(nodes[i].inedge >= 1 && nodes[i].outedge >= 1)
            if(dfs(i)) ans.push(i);
            else continue;
        else{ // 出度为 0 的点开始搜索
            if(dfs(i)) ans.push(i);
            else continue;
        }
    }

    int size = ans.size();
    printf("%d ", size);
    for(int i = 0; i < size; ++ i){
        ans_arr[i] = ans.front();
        ans.pop();
    }
    sort(ans_arr, ans_arr + size);
    for(int i = 0; i < size; ++ i)
        printf("%d ", ans_arr[i]);
    printf("\n");
    return 0;
}

*/
