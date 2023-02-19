#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
    cin >> a >> b;
    int f[a.length() + 1][b.length() + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < a.length(); ++i)
        for (int j = 0; j < b.length(); ++j)
            if (a[i] == b[j])
                f[i + 1][j + 1] = max(f[i][j] + 1, max(f[i][j + 1], f[i + 1][j]));
            else
                f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
    cout << f[a.length()][b.length()] << endl;
    return 0;
}