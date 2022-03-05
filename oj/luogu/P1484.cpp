#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,k;
long long num[500001],ans;//记录权利
int left[500001],right[500001];//记录左右坑 
bool book[500001];//记录遍历过与否
struct node
{
	int id;
	long long w;//w是权利 id是序号 
	bool operator <(node b) const
    {
        return w < b.w;
    }
 } t;//t用来过渡 
priority_queue<node>q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t.w);
		num[i]=t.w;
		t.id=i;
		left[i]=i-1;
		right[i]=i+1;
		q.push(t);
	}
	left[n+1]=n;
	right[0]=1;//补全r，l数组
	for(int i=1;i<=k;i++)
	{
		while(book[q.top().id])//如果遍历过则删除 ,注意！一定要用while删除，因为1不知道有几个遍历过。2可能有多次根顶遍历过。 
			q.pop();
		t=q.top();//取出堆顶元素 
		q.pop();
		if(t.w<0)//如果堆顶元素小于0则跳出 
			break;
		ans+=t.w;
		int c=t.id;
		num[c]=num[left[c]]+num[right[c]]-num[c];
		t.w=num[c];//设置新节点，意为若不选x节点选择x节点左右两节点的权利增加量 ，即提供反悔选项。 
		book[left[c]]=book[right[c]]=1;//删除左右的坑
		left[c]=left[left[c]];
		right[c]=right[right[c]];
		right[left[c]]=c;
		left[right[c]]=c;//更新左右坑的左右坑 
		q.push(t);
	}
	printf("%lld",ans);
	return 0;
} 