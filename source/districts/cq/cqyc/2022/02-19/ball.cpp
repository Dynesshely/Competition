#include <bits/stdc++.h>
using namespace std;

/*
    按理说我这个逻辑是没问题的
    但是不知道哪里出了问题， 估计是语言层面的
    也有可能是边界处理出了问题
    应该是拿不到分的。。。
    但大致估计我这个算法在 60 < H, W < 100 的情况下应该是会超时的
    所以假设我的语言层面没出问题， 此题因该能拿 40 分
    QAQ

    一开始我没看准题
    以为是一个球一个球的移动
    耽误了半小时
    后面才发现是所有球一起移动
    才有了下面这个逻辑， 虽然不能过

    想法：
        单纯的深搜， 模拟所有球的移动， 向各个方向的。
        1. 输入数据同时记录出口坐标和所有球的坐标
        2. 深搜
            1. 向左
                ...
            2. 向右
                ...
            3. 向上
                ...
            4. 向下
                ...
        3. 每次深搜的操作 dfs()
            遍历当前点集（移动过后的）
            如果：
            1. 和出口坐标重合
                此线路的 ans ++
                点集剔除此点
            2. 超出边界
                点集剔除此点
            然后
            继续深搜四个方向
            如果点集元素树小于等于0，结束此线路的深搜
*/

int H, W, xx, yy, ansm = 0, psn = 0; // H -> 行, W -> 列, (x, y) -> 出口坐标, ans -> 答案
string src[110];
struct point {
    int x, y;
};
queue<point> ps;
void dfs(char way, queue<point> *pnow, int ans);

int main() {
    // 输入数据
    scanf("%d%d", &H, &W);
    for (int i = 0; i < H; ++i) {
        cin >> src[i];
        for (int j = 0; j < W; ++j) {
            if (src[i][j] == 'E')
                xx = j, yy = i;
            if (src[i][j] == 'o') {
                point p;
                p.x = j;
                p.y = i;
                ps.push(p);
            }
        }
    }
    dfs('l', &ps, 0);
    dfs('r', &ps, 0);
    dfs('u', &ps, 0);
    dfs('d', &ps, 0);
    printf("%d\n", ansm);
    return 0;
}

bool checkp(point p) { return p.x < 0 || p.x > W - 1 || p.y < 0 || p.y > H - 1; }

void dfs(char way, queue<point> *pnow, int ans) {
    if ((*pnow).size() <= 0)
        return;
    if (way == 'l') { // 向左
        queue<point> tmp = *pnow;
        int num = tmp.size();
        for (int i = 0; i < num; ++i) {
            point p = tmp.front();
            p.x -= 1;
            if (checkp(p)) {
                tmp.pop();
                --num;
                continue;
            }
            if (p.x == xx && p.y == yy) {
                ++ans;
                tmp.pop();
                --num;
                continue;
            }
            tmp.push(tmp.front());
            tmp.pop();
        }
        ansm = max(ansm, ans);
        dfs('l', &tmp, ans);
        dfs('r', &tmp, ans);
        dfs('u', &tmp, ans);
        dfs('d', &tmp, ans);
    }
    if (way == 'r') { // 向右
        queue<point> tmp = *pnow;
        int num = tmp.size();
        for (int i = 0; i < num; ++i) {
            point p = tmp.front();
            p.x += 1;
            if (checkp(p)) {
                tmp.pop();
                --num;
                continue;
            }
            if (p.x == xx && p.y == yy) {
                ++ans;
                tmp.pop();
                --num;
                continue;
            }
            tmp.push(tmp.front());
            tmp.pop();
        }
        ansm = max(ansm, ans);
        dfs('l', &tmp, ans);
        dfs('r', &tmp, ans);
        dfs('u', &tmp, ans);
        dfs('d', &tmp, ans);
    }
    if (way == 'u') { // 向上
        queue<point> tmp = *pnow;
        int num = tmp.size();
        for (int i = 0; i < num; ++i) {
            point p = tmp.front();
            p.y -= 1;
            if (checkp(p)) {
                tmp.pop();
                --num;
                continue;
            }
            if (p.x == xx && p.y == yy) {
                ++ans;
                tmp.pop();
                --num;
                continue;
            }
            tmp.push(tmp.front());
            tmp.pop();
        }
        ansm = max(ansm, ans);
        dfs('l', &tmp, ans);
        dfs('r', &tmp, ans);
        dfs('u', &tmp, ans);
        dfs('d', &tmp, ans);
    }
    if (way == 'd') { // 向下
        queue<point> tmp = *pnow;
        int num = tmp.size();
        for (int i = 0; i < num; ++i) {
            point p = tmp.front();
            p.y += 1;
            if (checkp(p)) {
                tmp.pop();
                --num;
                continue;
            }
            if (p.x == xx && p.y == yy) {
                ++ans;
                tmp.pop();
                --num;
                continue;
            }
            tmp.push(tmp.front());
            tmp.pop();
        }
        ansm = max(ansm, ans);
        dfs('l', &tmp, ans);
        dfs('r', &tmp, ans);
        dfs('u', &tmp, ans);
        dfs('d', &tmp, ans);
    }
    ansm = max(ansm, ans);
}
