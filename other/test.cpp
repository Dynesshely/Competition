#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10][10];
    int b[100];

    int c[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    printf("%d", c[5]);

    bool d[5] = { true };
    bool e[5][5] = { true };
    for(int i = 0; i < 5; ++ i) cout << &d[i] << endl;
    for(int i = 0; i < 5; ++ i)
        for(int j = 0; j < 5; ++ j)
            cout << &e[i][j] << endl;
    return 0;
}