#include <bits/stdc++.h>
using namespace std;

char s[105];
bool matched[105];
int  n;

void input() {
    scanf("%s", s);
    n = strlen(s);
}

void process() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty() && s[st.top()] == '(') {
                matched[i] = matched[st.top()] = true;
                st.pop();
            }
        } else {
            if (!st.empty() && s[st.top()] == '[') {
                matched[i] = matched[st.top()] = true;
                st.pop();
            }
        }
    }
}

void output() {
    string ans;
    for (int i = 0; i < n; i++) {
        if (matched[i]) {
            ans.push_back(s[i]);
        } else {
            if (s[i] == '(' || s[i] == ')') {
                ans.push_back('(');
                ans.push_back(')');
            } else {
                ans.push_back('[');
                ans.push_back(']');
            }
        }
    }
    printf("%s\n", ans.c_str());
}

int main() {
    input();
    process();
    output();
    return 0;
}
