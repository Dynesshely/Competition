#include <bits/stdc++.h>
using namespace std;

/*
    此题用时： 啊，没看，忘了，大概半小时左右吧
    过程：
        1. 一开始使用 char[][] 存储输入数据
            结果不知道哪里出了问题， 输出就是有问题
        2. 后面换用 string[] 来存储， 输出没问题了
            不知道在 100 的情况下用时多杀
    时间复杂度：O(M(2N+1)) ≈ o(M²)
        1. 输入部分 O(M)
        2. 旋转部分 O(MN)
        3. 放大部分 O(MN)
    思路：
        1. 输出矩阵
        2. 把每一列当做一个向量
        3. 从右向左取出向量并在新矩阵中自顶向下放入向量 （此步完成旋转和上下镜像）
        4. 放大图像
            1. 每行变成原来的两倍
            2. 在double之后的每行下面追加一行double之后的
        5. 输出最终矩阵
*/

int N, M; // N -> 列, M -> 行
int main(){
    // 输入数据
    scanf("%d%d", &N, &M);
    string src[M]; // 源矩阵
    for(int i = 0; i < M; ++ i)
        cin >> src[i];
    
    // 旋转矩阵 (按列从右向左取出向量)
    string rotate[N]; // 旋转后矩阵
    for(int i = N - 1, index = 0; i >= 0; -- i, ++ index){
        string col; // 第 i 列的向量
        for(int j = 0; j < M; ++ j)
            col += src[j][i];
        rotate[index] = col;
    }
    // for(int i = 0; i < N; ++ i) // 单元测试
    //     cout << rotate[i] << endl;
    // cout << endl;

    // 旋转时已经镜像了
    // // 水平翻转 (上下镜像)
    // string mirror[N]; // 镜像后矩阵
    // for(int i = N - 1, index = 0; i >= 0; -- i, ++ index)
    //     mirror[index] = rotate[i];
    // for(int i = 0; i < N; ++ i) // 单元测试
    //     cout << mirror[i] << endl;
    // cout << endl;

    // 放大两倍
    string doubles[N * 2 + 1];
    for(int i = 0; i < N; ++ i){
        string tmp = rotate[i];
        for(int j = 0; j < M; ++ j) tmp += tmp[j];
        doubles[i * 2] = tmp;
        doubles[i * 2 + 1] = tmp;
    }

    // 输出结果
    for(int i = 0; i <= N * 2; ++ i)
        cout << doubles[i] << endl;
    return 0;
}
