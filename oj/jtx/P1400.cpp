#include <bits/stdc++.h>
using namespace std;

int n, m, T, a[205][205]; // n -> 行数, m -> 列数, T -> 操作数量
void rotate(int *total_angle){
    if(*total_angle > 0){ // 如果总角度为正，则需要向右旋转
        rotate_right:
        if(*total_angle >= 360) *total_angle = *total_angle - (int)(*total_angle / 360) * 360;
        int for_num = 0;
        if(*total_angle == 270) for_num = 3;
        else if(*total_angle == 180) for_num = 2;
        else if(*total_angle == 90) for_num = 1;
        for(int q = 1; q <= for_num; ++ q){
            int a_copy[205][205];
            memset(a_copy, -1, sizeof(a_copy));
            // 旋转矩阵到新数组
            for(int i = m, ni = m; i >= 1; -- i, -- ni)
                for(int j = 1, nj = n; j <= n; ++ j, -- nj)
                    a_copy[ni][nj] = a[i][j];
            // int tmp = m, m = n, n = tmp;
            memset(a, -1, sizeof(a));
            // 拷贝新数组到原数组
            for(int i = 1; i <= max(m, n); ++ i)
                for(int j = 1; j <= max(m, n); ++ j)
                    if(a_copy[i][j] != -1) a[i][j] = a_copy[i][j];
            // for(int i = 0; i <= max(m, n); ++ i){
            //     for(int j = 0; j <= max(m, n); ++ j)
            //         printf("%d ", a_copy[i][j]);
            //     printf("\n");
            // }
        }
    }else{ // 如果总角度为负，则需要向左旋转
        if(abs(*total_angle) % 360 == 0) return;
        else if(abs(*total_angle) % 270 == 0) *total_angle = 90;
        else if(abs(*total_angle) % 180 == 0) *total_angle = 180;
        else *total_angle = 270;
        goto rotate_right;
    }
    *total_angle = 0;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            scanf("%d", &a[i][j]);
    scanf("%d", &T);
    int total_angle = 0; // 总角度
    for(int i = 1; i <= T; ++ i){
        char op; cin >> op; // 获取操作符
        if(op == 'l' || op == 'r'){
            int angle; scanf("%d", &angle); // 获取角度
            total_angle += (op == 'l' ? -angle : angle); // 计算总角度
        }else{
            if(total_angle != 0){ rotate(&total_angle); } // 如果总角度不为0，则需要旋转
            if(op == 'h'){ // 如果操作符为h，则需要按照横向翻转
                
            }else{ // 如果操作符为v，则需要按照纵向翻转
                
            }
        }
    }
    rotate(&total_angle); // 最后需要再次检查总角度是否为0
    for(int i = 1; i <= max(m, n); ++ i){
        for(int j = 1; j <= max(m, n); ++ j)
            if(a[i][j] != -1) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}