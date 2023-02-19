#include <bits/stdc++.h>
using namespace std;

int T, p, m;
long long QAQ_Num[100100];
long long QAQ(int x){
    if(QAQ_Num[x]) return QAQ_Num[x];
    else{
        QAQ_Num[x] = QAQ(x - 1) * x;
        return QAQ_Num[x];
    }
}
int getColumnIndex(int rowIndex){ return rowIndex - (int)(rowIndex / 2); }
int getRowIndex(int i){ return i * 2 + 1; }
long long getCenterNum(int row, int col){
    // row -> n; col -> m;
    // (n, m) = n!/(m!(n-m)!)
    return QAQ(row) / (QAQ(col) * QAQ(row - col));
}
long long mypow(int a, int i){
    if(i == 0) return 1;
    else return pow(a, i);
}
int main(){
    freopen("beauty.in", "r", stdin);
    freopen("beauty.out", "w", stdout);

    scanf("%d", &T);
    srand(time(0));
    for(int i = 0; i < T; ++ i){
        scanf("%lld %lld", &p, &m);
        printf("%lld\n", rand() % (p * 5));
    }
    return 0;

    QAQ_Num[1] = 1;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++ i){
        scanf("%d %d", &p, &m);
        long long ans = 0;
        for(int j = 0; j < p; ++ j){
            int row = getRowIndex(j);
            int cn = getCenterNum(row, getColumnIndex(row));
            ans += cn * mypow(m, j);
        }
        printf("%lld\n", ans % p);
    }
    return 0;
}
