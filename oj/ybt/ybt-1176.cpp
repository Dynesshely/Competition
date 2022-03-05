#include<iostream>
using namespace std;
struct date
{
	int num;
	double result;
}date[100+2];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>date[i].num>>date[i].result;
	}
	double temp1,temp2;
    //date temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(date[j].result<date[j+1].result)
			{
				temp1=date[j].result;
				temp2=date[j].num;
				date[j].result=date[j+1].result;
				date[j].num=date[j+1].num;
				date[j+1].result=temp1;
				date[j+1].num=temp2;
			}
		}
	}
	cout<<date[k-1].num<<" "<<date[k-1].result<<endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n, tar;
// struct stu{
//     long long id;
//     float s;
// }ks[110];
// bool cmp(stu a, stu b){ return a.s < b.s; }
// int main(){
//     scanf("%d %d", &n, &tar);
//     for(int i = 1; i <= n; ++ i)
//         cin >> ks[i].id >> ks[i].s;
//     sort(ks + 1, ks + 1 + n, cmp);
//     printf("%lld %g\n", ks[tar].id, ks[tar].s);
//     return 0;
// }