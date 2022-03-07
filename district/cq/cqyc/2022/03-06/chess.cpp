#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, colnum[1010], tmp, ans = 0;
int color[1010][1010]; // 1->black; 2->white;
bool checkColEnd(int x, int y){
    // check column - k same
    int column_same = 0, y_copy = y - 1;
    while(true){
        if(y_copy <= 0) break;
        if(color[y_copy][x] == color[y][x])
            ++ column_same;
        else break;
        -- y_copy;
        if(column_same >= k) return true;
    }
    y_copy = y + 1;
    while(true){
        if(y_copy >= n - 1) break;
        if(color[y_copy][x] == color[y][x])
            ++ column_same;
        else break;
        ++ y_copy;
        if(column_same >= k) return true;
    }
    if(column_same >= k) return true;
    else return false;
}
bool checkRowEnd(int x, int y){
    // check row - k same
    int row_same = 0, x_copy = x - 1;
    while(true){
        if(x_copy <= 0) break;
        if(color[y][x_copy] == color[y][x])
            ++ row_same;
        else break;
        -- x_copy;
        if(row_same >= k) return true;
    }
    x_copy = x + 1;
    while(true){
        if(x_copy >= m - 1) break;
        if(color[y][x_copy] == color[y][x])
            ++ row_same;
        else break;
        ++ x_copy;
        if(row_same >= k) return true;
    }
    if(row_same >= k) return true;
    else return false;
}
bool checkTanEnd(int x, int y){
    // check tan - k same
    int x_lu = x - 1, y_lu = y + 1;
    int x_ru = x + 1, y_ru = y + 1;
    int x_ld = x - 1, y_ld = y - 1;
    int x_rd = x + 1, y_rd = y - 1;
    int sum_lu = 0, sum_rd = 0;
    int sum_ld = 0, sum_ru = 0;
    bool way[4] = {true}; // 0-lu, 1-rd, 2-ld, 3-ru
    while(true){
        if(sum_lu + sum_rd >= k ||
            sum_ld + sum_ru >= k)
            return true;
        if(way[0] && (color[y_lu][x_lu] == color[y][x])){
            ++ sum_lu; -- x_lu; ++ y_lu;
        }else way[0] = false;
        if(way[1] && (color[y_rd][x_rd] == color[y][x])){
            ++ sum_rd; ++ x_rd; -- y_rd;
        }else way[1] = false;
        if(way[2] && (color[y_ld][x_ld] == color[y][x])){
            ++ sum_ld; -- x_ld; -- y_ld;
        }else way[2] = false;        
        if(way[3] && (color[y_ru][x_ru] == color[y][x])){
            ++ sum_ru; ++ x_ru; ++ y_ru;
        }else way[3] = false;
        if(!way[0] && !way[1] && !way[2] && !way[3]) break;
    }
    if(sum_lu + sum_rd >= k ||
        sum_ld + sum_ru >= k)
        return true;
    else return false;
}
bool checkGameEnd(int x, int y){
    return
        checkColEnd(x, y) ||
        checkRowEnd(x, y) ||
        checkTanEnd(x, y);
}

int sum(){
    for(int i = 0; i < m; ++ i) ans += colnum[i];
    return ans;
}

int main(){
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);

    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(int i = 1; i <= t; ++ i){
        scanf("%d", &tmp);
        if(colnum[tmp] % 2 == 0)
            color[n - colnum[tmp]][tmp] = 1;
        else color[n - colnum[tmp]][tmp] = 2;
        if(checkGameEnd(tmp, n - colnum[tmp])){
            printf("%d\n", sum());
            return 0;
        }
        ++ colnum[tmp];
    }
    printf("%d\n", sum());
    return 0;
}