#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    ostringstream os;
    os << num;
    string ss = os.str();
    char *arr = new char[ss.length() + 1]; // 转换为数组
    memmove(arr, ss.c_str(), ss.length());
    char newarr[ss.length()];
    for (int i = 1; i < ss.length() + 1; i++) {
        newarr[i - 1] = arr[ss.length() - i];
    }
    string output;
    int indexof = 0;
    for (int i = 0; i < ss.length(); i++) {
        if ((newarr[i] - '0') != 0) {
            indexof = i;
            break;
        }
    }
    for (int i = indexof; i < ss.length(); i++) {
        if (newarr[i] != '-') {
            output += newarr[i];
        } else {
            output = "-" + output;
        }
    }
    cout << output;
    return 0;
}