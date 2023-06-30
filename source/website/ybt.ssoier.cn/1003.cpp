#include <iostream>
#include <cstdio>
//支援priintf函数 
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	printf("%8d %8d %8d",a,b,c);
	//printf输出格式控制符"%8d"用于控制每个字符都占8个字符宽度 
	return 0;
}
