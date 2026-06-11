#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

struct Node {
    int ways0, ways1;
};

int prec(char op) {
    if (op == '+')
        return 1;
    if (op == '*')
        return 2;
    return 0;
}

void applyOp(stack<Node> &st, char op) {
    Node r = st.top();
    st.pop();
    Node l = st.top();
    st.pop();
    Node res;
    if (op == '+') {
        res.ways0 = l.ways0 * r.ways0 % MOD;
        res.ways1 = (l.ways0 * r.ways1 + l.ways1 * r.ways0 + l.ways1 * r.ways1) % MOD;
    } else {
        res.ways1 = l.ways1 * r.ways1 % MOD;
        res.ways0 = (l.ways0 * r.ways0 + l.ways0 * r.ways1 + l.ways1 * r.ways0) % MOD;
    }
    st.push(res);
}

int main() {
    int  L;
    char s[100005];
    scanf("%d%s", &L, s);

    stack<Node> valStk;
    stack<char> opStk;
    bool        needVal = true;

    for (int i = 0; i < L; i++) {
        char c = s[i];
        if (c == '(') {
            opStk.push('(');
            needVal = true;
        } else if (c == ')') {
            if (needVal)
                valStk.push({1, 1});
            needVal = false;
            while (opStk.top() != '(') {
                applyOp(valStk, opStk.top());
                opStk.pop();
            }
            opStk.pop();
        } else {
            if (needVal)
                valStk.push({1, 1});
            needVal = false;
            while (!opStk.empty() && opStk.top() != '(' && prec(opStk.top()) >= prec(c)) {
                applyOp(valStk, opStk.top());
                opStk.pop();
            }
            opStk.push(c);
            needVal = true;
        }
    }

    if (needVal)
        valStk.push({1, 1});

    while (!opStk.empty()) {
        applyOp(valStk, opStk.top());
        opStk.pop();
    }

    printf("%d\n", valStk.top().ways0 % MOD);

    return 0;
}
