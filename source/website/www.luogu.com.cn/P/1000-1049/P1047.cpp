#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, M, count = 0;
    cin >> L >> M;
    L++;
    int road[L], blocks[M][2];
    for (int i = 0; i < M; i++) {
        cin >> blocks[i][0] >> blocks[i][1];
    }
    for (int i = 0; i < L; i++) {
        road[i] = i;
    }
    for (int i = 0; i < M; i++) {
        for (int j = blocks[i][0]; j <= blocks[i][1]; j++) {
            road[j] = -1;
        }
    }
    for (int i = 0; i < L; i++) {
        if (road[i] != -1) {
            count++;
        }
    }
    cout << count;
    return 0;
}