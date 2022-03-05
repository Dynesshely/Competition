// /*
//     题目描述
//     为了培养小孩的计算能力，大人们经常给小孩玩这样的游戏：从1付扑克牌中任意抽出4张扑克，要小孩用“+”、“-”、“* ”、“ /”和括号组成一个合法的表达式，并使表达式的值为24点。这种游戏就是所谓的“24点游戏”。
//     请你编程求出对于给出的任意4个正整数a、b、c、d，请你编程求出这4个整数能组成多少个值为24的不同表达式。
//     输入格式
//     输入文件名：input.txt
//     输入文件共一行，为4个正整数a、b、c、d。（0<=a,b,c,d<=100 ）
//     输出格式
//     输出文件名：output.txt
//     输出文件为由a、b、c、d组成的值为24表达式个数，如没有，输出0

//     思路：
//         1. 简单深搜
//         2. 考虑不同位次的情况， 遍历
//         3. 注意结合律的优先顺序
// */

#include<bits/stdc++.h> 
using namespace std;
const double check=1e-6;//实数计算误差
int ans,v[5],pm[5],f[5],g[5];
map<int,int> mp;
double num(double x,double y,int z){//计算
    switch(z){//z表示运算符：0加，1减，2乘，3除
        case 0:return x+y; break;
        case 1:return x-y; break;
        case 2:return x*y; break;
        case 3:return x/y; break;
    }
}
double Abs(double p){//实数绝对值
    return (p<0?-p:p);
}
int useful(int a,int b){//能不能加括号
//括号前面是减号、除号，加上括号要变号
    if(a%2==1) return 1;
    if(!a) return (b>1?1:0);
    else return (b<2?1:0);
}
void mplus(int a1,int a2,int a3,int a4,int a5,int a6,int a7){//map+状压去重
    int x=(a1|a2<<3|a3<<6|a4<<9|a5<<12|a6<<15|a7<<18);
    if(++mp[x]==1)ans++;
}
int find(int x){//x是第几个
    for(int i=1;i<=4;i++)
        if(f[i]==x)return i;
}
void count(int a,int b,int c,int d){//暴力计算
    for(int i=0;i<=3;i++)//i,j,k枚举符号
    for(int j=0;j<=3;j++)
    for(int k=0;k<=3;k++){
/*      5种添括号
        (1,2,3,4)
        ((1,2),(3,4))
        (1,(2,3,4))
        ((1,(2,3)),4)
        (1,(2,(3,4)))*/
        int u1=useful(k,j), u2=useful(j,i);
        if( Abs((num( num( num(a,b,i) ,c,j),d,k)  -24 ))<check)
            mplus(pm[find(a)],pm[find(b)],(i+4),pm[find(c)],(j+4),pm[find(d)],(k+4));
        if(u1==1&& Abs(num( num(a,b,i),num(c,d,j) , k)   -24 )<check)
            mplus(pm[find(a)],pm[find(b)],(i+4),pm[find(c)],pm[find(d)],(j+4),(k+4));
        if(u1==1&& Abs(num(a,num( num(b,c,i),d,j),k)     -24 )<check)
            mplus(pm[find(a)],pm[find(b)],pm[find(c)],(i+4),pm[find(d)],(j+4),(k+4));
        if(u2==1&& Abs(num(num(a, num(b,c,i) ,j),d,k)    -24 )<check)
            mplus(pm[find(a)],pm[find(b)],pm[find(c)],(i+4),(j+4),pm[find(d)],(k+4));
        if(u1==1&&u2==1&& Abs(num(a, num(b,num(c,d,i),j),k)-24 )<check)
            mplus(pm[find(a)],pm[find(b)],pm[find(c)],pm[find(d)],(i+4),(j+4),(k+4));
    }
}
void dfs(int x){//dfs求排列
    if(x>4){
        count(g[1],g[2],g[3],g[4]);
        return;
    }
    for(int i=1;i<=4;i++)
        if(v[i]==0)
            v[i]=1,g[x]=f[i],dfs(x+1),v[i]=0;
}
int main(){
    for(int i=1;i<=4;i++)scanf("%d",&f[i]);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            pm[i]=pm[i]+(f[i]<f[j]?1:0);//排第几，用于状压判重（最大0）
    dfs(1);
    printf("%d\n",ans);
}

/*
    膜拜楼上大佬
*/

// #include <bits/stdc++.h>
// using namespace std;

// /*
//     题目描述
//     为了培养小孩的计算能力，大人们经常给小孩玩这样的游戏：从1付扑克牌中任意抽出4张扑克，要小孩用“+”、“-”、“* ”、“ /”和括号组成一个合法的表达式，并使表达式的值为24点。这种游戏就是所谓的“24点游戏”。
//     请你编程求出对于给出的任意4个正整数a、b、c、d，请你编程求出这4个整数能组成多少个值为24的不同表达式。
//     输入格式
//     输入文件名：input.txt
//     输入文件共一行，为4个正整数a、b、c、d。（0<=a,b,c,d<=100 ）
//     输出格式
//     输出文件名：output.txt
//     输出文件为由a、b、c、d组成的值为24表达式个数，如没有，输出0

//     思路：
//         1. 简单深搜
//         2. 考虑不同位次的情况， 遍历
//         3. 注意结合律的优先顺序
// */

// int a, b, c, d, ans = 0;
// char _exp[4] = {'+', '-', '*', '/'};
// void dfs(int x, int y, int z);
// bool via[1000];
// int main(){
//     scanf("%d%d%d%d", &a, &b, &c, &d); // 输入数据
//     dfs(0, 0, 0); // 深搜
//     printf("%d\n", ans); // 输出答案
//     return 0;
// }

// // 抽象运算符
// double _add(int a, int b){ return a + b; }
// double _sub(int a, int b){ return a - b; }
// double _mul(int a, int b){ return a * b; }
// double _div(int a, int b){ return a * 1.0 / (b / 1.0); }

// int solve(string expre);

// // 深搜
// void dfs(int x, int y, int z){
//     if(via[x * 100 + y * 10 + z]) return;
//     else via[x * 100 + y * 10 + z] = true;

//     // double p1 = x == 0 ? _add(a, b) : (x == 1 ? _sub(a, b) : (x == 2 ? _mul(a, b) : _div(a, b)));
//     // printf("%d %c %d %c %d %c %d\n", a, _exp[x], b, _exp[y], c, _exp[z], d);

//     // string expression = to_string(a) + _exp[x] + to_string(b) + _exp[y] + to_string(c) + _exp[z] + to_string(d);
//     // cout << expression << endl;

//     // Four arithmetic expressions in variable "expression", solve it

//     string expression = to_string(a) + _exp[x] + to_string(b) + _exp[y] + to_string(c) + _exp[z] + to_string(d);
//     cout << expression;
//     int ans = solve(expression);
//     cout << " = " << ans << endl;
//     if(ans == 24) ++ ans;

//     if(x + 1 < 4) dfs(x + 1, y, z);
//     if(y + 1 < 4) dfs(x, y + 1, z);
//     if(z + 1 < 4) dfs(x, y, z + 1);
// }

// int cal(char ch, int data1, int data2){
//     switch (ch) {
//         case '+': return data1 + data2;
//         case '-': return data1 - data2;
//         case '*': return data1 * data2;
//         case '/': return data2 == 0 ? 0 : data1 / data2;
//         default: return data1 + data2;
//     }
// }

// int solve(string str){
//     int pos = -1;
//     if ((pos = str.find('+', 0)) != -1  
//                 || (pos = str.find('-', 0)) != -1 
//                 || (pos = str.find('*', 0)) != -1 
//                 || (pos = str.find('/', 0)) != -1){
//         string str1 = str.substr(0, pos);
//         string str2 = str.substr(pos + 1);
//         return cal(str[pos], solve(str1), solve(str2));
//     }
//     return atoi(str.c_str());
// }