/*
	Description
	在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
	每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
	因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
	例如有3种果子，数目依次为1，2，9。可以先将1、2堆合并，新堆数目为3，耗费体力为3。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为12，耗费体力为12。所以多多总共耗费体力=3+12=15。可以证明15为最小的体力耗费值。

	Format
	Input
	两行，第一行是一个整数n(1<＝n<=2000)，表示果子的种类数。第二行包含n个整数，用空格分隔，第i个整数ai(1<＝ai<=10000)是第i种果子的数目。

	Output
	一行，这一行只包含一个整数，也就是最小的体力耗费值。输入数据保证这个值小于2^31。
*/

#include <bits/stdc++.h>
using namespace std;
int sum = 0, n;
priority_queue<int, vector<int>, greater<int> > fruits;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		int tmp;
		scanf("%d", &tmp);
		fruits.push(tmp);
	}
	int a = 0, b = 0;
	int size = fruits.size();
	while(size > 1){
		a = fruits.top();
		fruits.pop();
		b = fruits.top();
		fruits.pop();
		fruits.push(a + b);
		sum += a + b;
		--size;
	}
	printf("%d\n", sum);
	return 0;
}
