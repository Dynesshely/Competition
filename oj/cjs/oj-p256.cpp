/*
    说明
    假设表达式中允许包含两种括号：圆括号和方括号，其嵌套的顺序随意，如（［ ］（））或［（［ ］［ ］）］等为正确的匹配，［（ ］）或（［ ］（ ）或 ( ( ) ) ）均为错误的匹配。
    现在的问题是，要求检验一个给定表达式中的括弧是否正确匹配？
    输入一个只包含圆括号和方括号的字符串，判断字符串中的括号是否匹配，匹配就输出 “OK” ，不匹配就输出“Wrong”。输入一个字符串：［（［］［］）］，输出：OK。

    输入格式
    输入仅一行字符（字符个数小于255）。

    输出格式
    匹配就输出 “OK” ，不匹配就输出“Wrong”。
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s; stack<char> st;
    for(char c : s){
        if(c == '[' || c == '(') st.push(c);
        else if(c == ']'){
            if(st.empty() || st.top() != '[' ){
                cout << "Wrong" << endl;
                return 0;
            }
            st.pop();
        }else if(c == ')'){
            if(st.empty() || st.top() != '(' ){
                cout << "Wrong" << endl;
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty()) cout << "OK" << endl;
    else cout << "Wrong" << endl;
    return 0;
}