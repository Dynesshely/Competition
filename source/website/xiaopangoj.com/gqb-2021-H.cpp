/*
        贵青杯赛事题或者训练题
*/

#include <bits/stdc++.h>
using namespace std;
string dx;
string dw(string input) {
    string rst;
    for (int i = input.length() - 1; i >= 0; --i)
        rst += input[i];
    return rst;
}
string substr(int a, int b, string mom) {
    string rst;
    for (int i = a; i <= b; ++i)
        rst += mom[i];
    return rst;
}
void exe(string input) {
    if (input.length() % 2 != 0) {
        printf("%d\n", input.length());
        return;
    }
    string s1 = substr(0, input.length() / 2 - 1, input),
           s2 = substr(input.length() / 2, input.length() - 1, input);
    if (input.length() == 2) {
        printf("2\n");
        return;
    } else if (s1 == s2 || s1 == dw(s2))
        exe(s1);
    else {
        printf("%d\n", s1.length());
        return;
    }
}
int main() {
    cin >> dx;
    exe(dx);
    return 0;
}