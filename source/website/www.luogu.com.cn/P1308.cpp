#include <bits/stdc++.h>
using namespace std;

string word, article;
int    cnt, firstPos;

void input() {
    cin >> word;
    cin.ignore();
    getline(cin, article);
}

void process() {
    for (char &c : word)
        if (c >= 'A' && c <= 'Z')
            c += 32;
    cnt      = 0;
    firstPos = -1;
    int n = article.length(), i = 0;
    while (i < n) {
        while (i < n && article[i] == ' ')
            i++;
        if (i >= n)
            break;
        int start = i;
        while (i < n && article[i] != ' ')
            i++;
        int len = i - start;
        if (len == (int)word.length()) {
            bool match = true;
            for (int j = 0; j < len; j++) {
                char c = article[start + j];
                if (c >= 'A' && c <= 'Z')
                    c += 32;
                if (c != word[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cnt++;
                if (cnt == 1)
                    firstPos = start;
            }
        }
    }
}

void output() {
    if (cnt == 0)
        printf("-1\n");
    else
        printf("%d %d\n", cnt, firstPos);
}

int main() {
    input();
    process();
    output();
    return 0;
}
