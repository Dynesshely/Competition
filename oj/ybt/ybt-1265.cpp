#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int al = a.length(), bl = b.length();
    int _map[al + 1][bl + 1];
    memset(_map, 0, sizeof(_map));
    for(int i = 1; i <= al; ++ i)
    {
        for(int j = 1; j <= bl; ++ j)
        {
            int up = _map[i - 1][j], left = _map[i][j - 1], upleft = _map[i - 1][j - 1];
            _map[i][j] = (a[i - 1] == b[j - 1] ? upleft + 1 : max(up, left));
        }
    }
    // for(int i=0;i<al;i++)
    //     for(int j=0;j<bl;j++)
    //         if(a[i]==b[j])
    //             _map[i+1][j+1]=_map[i][j]+1;
    //         else
    //             _map[i+1][j+1]=max(_map[i][j+1],_map[i+1][j]);
    printf("%d\n", _map[al][bl]);
    return 0;
}
