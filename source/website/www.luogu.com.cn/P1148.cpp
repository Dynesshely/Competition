#include <bits/stdc++.h>
using namespace std;

const int hVal[] = {0, -50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};

int            cnt[4];
char           buf[10];
vector<string> cards[4];

void input() {
    for (int i = 0; i < 4; i++) {
        cards[i].clear();
        scanf("%d", &cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%s", buf);
            cards[i].push_back(string(buf));
        }
    }
}

int calc(vector<string> &c) {
    bool s12 = false, d11 = false, c10 = false;
    bool h[14] = {false};
    int  hc    = 0;
    for (string &s : c) {
        char suit = s[0];
        int  num  = 0;
        for (int k = 1; s[k]; k++)
            num = num * 10 + (s[k] - '0');
        if (suit == 'S' && num == 12)
            s12 = true;
        else if (suit == 'D' && num == 11)
            d11 = true;
        else if (suit == 'C' && num == 10)
            c10 = true;
        else if (suit == 'H') {
            h[num] = true;
            hc++;
        }
    }
    if (!s12 && !d11 && !c10 && hc == 0)
        return 0;
    int sc = 0;
    if (hc == 13) {
        if (s12 && d11)
            sc = 500;
        else {
            sc = 200;
            if (s12)
                sc -= 100;
            if (d11)
                sc += 100;
        }
    } else {
        for (int i = 1; i <= 13; i++)
            if (h[i])
                sc += hVal[i];
        if (s12)
            sc -= 100;
        if (d11)
            sc += 100;
    }
    if (c10) {
        if (!s12 && !d11 && hc == 0)
            sc = 50;
        else
            sc *= 2;
    }
    return sc;
}

void process() {}

void output() {
    for (int i = 0; i < 4; i++) {
        int sc = calc(cards[i]);
        if (sc > 0)
            printf("+%d", sc);
        else
            printf("%d", sc);
        if (i < 3)
            printf(" ");
    }
    printf("\n");
}

int main() {
    while (true) {
        input();
        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0)
            break;
        process();
        output();
    }
    return 0;
}
