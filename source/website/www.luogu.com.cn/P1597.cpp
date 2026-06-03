#include <bits/stdc++.h>
using namespace std;

char s[260];
int val[3];

void input() {
scanf("%s", s);
}

void process() {
int len = strlen(s);
for (int i = 0; i < len; i++) {
if (s[i] >= 'a' && s[i] <= 'c') {
int t = s[i] - 'a';
i += 3;
char v = s[i];
if (v >= '0' && v <= '9')
val[t] = v - '0';
else
val[t] = val[v - 'a'];
}
}
}

void output() {
printf("%d %d %d\n", val[0], val[1], val[2]);
}

int main() {
input();
process();
output();
return 0;
}
