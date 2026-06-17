#include <bits/stdc++.h>
using namespace std;

char           s[105];
vector<string> postfix;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isRightAssociative(char op) { return op == '^'; }

bool isOperator(const string &t) { return t == "+" || t == "-" || t == "*" || t == "/" || t == "^"; }

int applyOp(int a, int b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    int r = 1;
    for (int i = 0; i < b; i++)
        r *= a;
    return r;
}

void input() { scanf("%s", s); }

void process() {
    stack<char> ops;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            postfix.push_back(string(1, c));
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(') {
                postfix.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop();
        } else {
            while (!ops.empty() && ops.top() != '(') {
                int p1 = precedence(ops.top());
                int p2 = precedence(c);
                if (p1 > p2 || (p1 == p2 && !isRightAssociative(c))) {
                    postfix.push_back(string(1, ops.top()));
                    ops.pop();
                } else
                    break;
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        postfix.push_back(string(1, ops.top()));
        ops.pop();
    }
    for (int i = 0; i < (int)postfix.size(); i++)
        printf("%s ", postfix[i].c_str());
    printf("\n");
    while (postfix.size() > 1) {
        int pos = 0;
        while (!isOperator(postfix[pos]))
            pos++;
        int a = stoi(postfix[pos - 2]);
        int b = stoi(postfix[pos - 1]);
        int r = applyOp(a, b, postfix[pos][0]);
        postfix.erase(postfix.begin() + pos - 2, postfix.begin() + pos + 1);
        postfix.insert(postfix.begin() + pos - 2, to_string(r));
        for (int i = 0; i < (int)postfix.size(); i++)
            printf("%s ", postfix[i].c_str());
        printf("\n");
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
