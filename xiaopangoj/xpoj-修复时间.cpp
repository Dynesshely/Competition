/*
	贵青杯赛事题或者训练题
*/

#include <bits/stdc++.h>
using namespace std;
int h, m, s, h1 = 0, m1 = 0, s1 = 0;
int main(){
	scanf("%d %d %d", &h, &m, &s);
	h1 = h;
	m1 += m % 60;
	h1 += m / 60;
	s1 += s % 60;
	m1 += s / 60;
	while(h1 == 24 || m1 == 60 || s1 == 60){
		if(h1 == 24) h1 = 0;
		if(m1 == 60) m1 = 0, h1 += 1;
		if(s1 == 60) s1 = 0, m1 += 1;	
	}
	printf("%d:%d:%d\n", h1, m1, s1);
	return 0;
}