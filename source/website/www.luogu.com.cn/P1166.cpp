#include <bits/stdc++.h>
using namespace std;

vector<int> rolls;
vector<int> frameScores;

void parseToken(const string &token) {
    if (token[0] == '/')
        rolls.push_back(10);
    else
        rolls.push_back(token[0] - '0');
    if (token.length() > 1) {
        if (token[1] == '/')
            rolls.push_back(10 - (token[0] - '0'));
        else
            rolls.push_back(token[1] - '0');
    }
}

void input() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string       token;
    while (ss >> token)
        parseToken(token);
}

void process() {
    int n = rolls.size();
    for (int i = 0, frame = 0; frame < 10 && i < n; ++frame) {
        if (rolls[i] == 10) {
            if (i + 2 < n)
                frameScores.push_back(10 + rolls[i + 1] + rolls[i + 2]);
            ++i;
        } else {
            if (i + 1 >= n)
                break;
            int sum = rolls[i] + rolls[i + 1];
            if (sum == 10) {
                if (i + 2 < n)
                    frameScores.push_back(10 + rolls[i + 2]);
            } else
                frameScores.push_back(sum);
            i += 2;
        }
    }
}

void output() {
    for (int s : frameScores)
        printf("%d ", s);
    printf("\n");
    int total = 0;
    for (int s : frameScores) {
        total += s;
        printf("%d ", total);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
