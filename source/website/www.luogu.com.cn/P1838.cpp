#include <bits/stdc++.h>
using namespace std;

char s[20];
int len;
int board[3][3];

void input() {
    if (scanf("%s", s) != 1) return;
    len = strlen(s);
}

bool check(int player) {
    for (int r = 0; r < 3; r++)
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
            return true;
    for (int c = 0; c < 3; c++)
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
            return true;
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

void process() {
    for (int i = 0; i < len; i++) {
        int pos = s[i] - '0' - 1;
        int r = pos / 3, c = pos % 3;
        board[r][c] = (i % 2 == 0) ? 1 : 2;
    }
}

void output() {
    if (check(1)) printf("xiaoa wins.\n");
    else if (check(2)) printf("uim wins.\n");
    else printf("drew.\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
