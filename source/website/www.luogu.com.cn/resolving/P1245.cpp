#include <bits/stdc++.h>
using namespace std;

int            N;
string         pwd;
vector<string> words;
vector<string> wordDig;
vector<string> result;
bool           solvable;

void input() {
    scanf("%d", &N);
    char buf[105];
    scanf("%s", buf);
    pwd = buf;
    words.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%s", buf);
        words[i] = buf;
    }
}

char toDigit(char c) {
    if (c <= 'c')
        return '1';
    if (c <= 'f')
        return '2';
    if (c <= 'i')
        return '3';
    if (c <= 'l')
        return '4';
    if (c <= 'n')
        return '5';
    if (c <= 'q')
        return '6';
    if (c <= 't')
        return '7';
    if (c <= 'w')
        return '8';
    return '9';
}

void process() {
    wordDig.resize(N);
    for (int i = 0; i < N; i++)
        for (char c : words[i])
            wordDig[i].push_back(toDigit(c));
    int         pwLen = pwd.length();
    vector<int> reachable(pwLen + 1, 0);
    reachable[0] = 1;
    for (int i = 1; i <= pwLen; i++)
        for (int j = 0; j < N; j++) {
            int len = wordDig[j].length();
            if (i >= len && reachable[i - len] && pwd.substr(i - len, len) == wordDig[j]) {
                reachable[i] = 1;
                break;
            }
        }
    if (!reachable[pwLen]) {
        solvable = false;
        return;
    }
    solvable = true;
    int pos  = pwLen;
    while (pos > 0)
        for (int j = 0; j < N; j++) {
            int len = wordDig[j].length();
            if (pos >= len && reachable[pos - len] && pwd.substr(pos - len, len) == wordDig[j]) {
                result.push_back(words[j]);
                pos -= len;
                break;
            }
        }
    reverse(result.begin(), result.end());
}

void output() {
    if (!solvable) {
        printf("No Solutions!\n");
        return;
    }
    for (int i = 0; i < result.size(); i++) {
        if (i > 0)
            printf(" ");
        printf("%s", result[i].c_str());
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
