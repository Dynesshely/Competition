#include <bits/stdc++.h>
using namespace std;

/*
    Monkey Jacke 在树 T 上漫步，树根是 1 号节点。
    Jacke 品味独特，它更喜欢 “厚实二叉树”，即每个非叶子节点都恰有两个儿子的树（叶子定义为非树根且度数为 1
    的节点）。于是经过猴民的一番修整，T 被修整成了有 n 个节点的 “厚实二叉树” T′。 随后 Jacke
    开始了它的漫步。它决定**从根节点出发，每次 “走”（或者说
    “爬”）过一条边，反复移动，直到重新回到根节点**。Jacke
    认为，“不畏浮云遮望眼，自缘身在最高层”，于是它想达到物理意义上的最高层，即树的 “叶子”
    节点。但在同一片叶子或同一条边上呆太久都会让 Jacke
    感到乏味，于是它准备踏上每个叶子节点恰好一次，爬过每条边恰好两次。 树上的漫步十分消耗体力。每一条边 e
    都有它的长度 l[e]，如果 “走” 过该边就会消耗 l[e] 点体力。但踏上叶子之后 Jacke 会进行调整，这使得 Jacke
    的体力回满。同时，踏上第一片叶子之前的 Jacke 是兴高采烈的，踏上所有叶子之后的 Jacke
    是志得意满的，这两种状态下 Jacke 消耗的体力都可以忽略不计。 你不关注这所谓 “自缘身在最高层”
    的体会，也不想了解 Jacke 拥有多少体力。你只想知道一些实际的东西：如果 Jacke
    想要完成它的目标，它至少要有多少体力？

    第一行输入一个正整数 n，表示树 T' 的节点数。
    接下来 n-1 行，第 i 行输入两个正整数 p[i+1],l[i+1]，分别表示点 i+1 的父亲与点 i+1 到父亲的边的长度。

    输出一个非负整数表示答案。
*/

/*
    思路:
        首先要解决总边长最小的子树,
        对于样例2, 即是结点1的左子树2
        因为 Jacke 爬过每条边需要消耗体力
        而到达结点可以恢复体力, 且走完所有叶子结点之后
        有体力不消耗的 buff, 所以要先解决总长小的
        不然另一边的结点就会产生实质消耗

        所以, 对于 Jacke 而言, 他需要在每个结点处做出选择
        最优解是走当前结点子树边长和最小的子树,
        此时最大体力消耗就是不断选择子树边长和最大的子树,
        模拟走过一遍自然得到答案
*/

const int maxn = 27010;
struct node {
    int id, ls = -1, rs = -1, lsum = 0, rsum = 0, lv;
} nodes[maxn];
bool vis[maxn];
int n, p[maxn], l[maxn], ans = 0;
vector<int> leaf;
queue<int> leafs;
inline bool isLeaf(int x) { return nodes[x].ls == -1 && nodes[x].rs == -1; }
inline void sumlen(int x) {
    if (vis[x])
        return;
    else
        vis[x] = true;
    if (x == 1) {
        nodes[1].lsum =
            ((nodes[1].ls == -1) ? 0 : l[nodes[1].ls] + nodes[nodes[1].ls].lsum + nodes[nodes[1].ls].rsum);
        nodes[1].rsum =
            ((nodes[1].rs == -1) ? 0 : l[nodes[1].rs] + nodes[nodes[1].rs].lsum + nodes[nodes[1].rs].rsum);
        return;
    }
    if (nodes[x].ls == -1 && nodes[x].rs == -1) // 叶子结点直接求爹
        else if (nodes[x].ls == -1) nodes[x].rsum =
            nodes[nodes[x].rs].rsum + nodes[nodes[x].rs].lsum + l[nodes[x].rs];
    else if (nodes[x].rs == -1)
        nodes[x].lsum = nodes[nodes[x].ls].lsum + nodes[nodes[x].ls].rsum + l[nodes[x].ls];
    else {
        nodes[x].rsum = nodes[nodes[x].rs].rsum + nodes[nodes[x].rs].lsum + l[nodes[x].rs];
        nodes[x].lsum = nodes[nodes[x].ls].lsum + nodes[nodes[x].ls].rsum + l[nodes[x].ls];
    }
    sumlen(p[x]);
}
int main() {
    scanf("%d", &n);
    // 仅考虑 n <= maxn , 对于 2e17 的数据, 直接放弃
    if (n > maxn)
        return 0;
    nodes[1].id = 1, nodes[1].lv = 1;
    for (int i = 2; i <= n; ++i) {
        scanf("%d %d", &p[i], &l[i]);
        nodes[i].id = i, nodes[i].lv = nodes[p[i]].lv + 1;
        if (nodes[p[i]].ls == -1)
            nodes[p[i]].ls = i;
        else
            nodes[p[i]].rs = i;
    }
    for (int i = 2; i <= n; ++i)
        if (nodes[i].ls == -1 && nodes[i].rs == -1)
            leaf.push_back(i);
    sort(leaf.begin(), leaf.end(), [](int a, int b) { return nodes[a].lv > nodes[b].lv; });
    for (vector<int>::iterator it = leaf.begin(); it != leaf.end(); ++it)
        sumlen(*it);
    for (vector<int>::iterator it = leaf.end(); it != leaf.begin(); --it)
        leafs.push(*it);
    memset(vis, false, sizeof(vis));
    int ans = 0, power = ans, cur = 1;
    bool way = true; // true -> 向下走, false -> 向上走
    while (!leafs.empty()) {
        int target = (nodes[cur].lsum < nodes[cur].rsum) ? nodes[cur].ls : nodes[cur].rs;
        if (isLeaf(target)) {
            cur = target;
            power = ans;
        }
    }

    // while(!leafs.empty()){

    // }

    // int ans = min(nodes[1].lsum, nodes[1].rsum), power = ans, cur = 1;
    // while(!(isLeaf(cur))){
    //     if(isLeaf(nodes[cur].ls)){
    //         power = ans - l[nodes[cur].ls];
    //     }else if(isLeaf(nodes[cur].rs)){
    //         power = ans - l[nodes[cur].rs];
    //     }
    //     if(nodes[cur].lsum == nodes[cur].rsum){
    //     }
    //     int target = (nodes[cur].lsum < nodes[cur].rsum) ? nodes[cur].rs : nodes[cur].ls;
    //     if(power >= l[target]){
    //         power -= l[target];
    //     }else{
    //         ans += l[target] - power;
    //     }
    //     cur = target;
    // }
    printf("%d\n", ans);
    return 0;
}