#include<iostream>
#include<cstring>
using namespace std;
int fx[8] = {1,1,2,2,-1,-1,-2,-2};
int fy[8] = {2,-2,1,-1,2,-2,1,-1};
int ans,t,n,m,sx,sy;
bool visited[101][101];
void dfs(int x,int y,int tot)
{
	if(tot == n*m) ans++;//�����յ㷽����+1
	for(int i = 0; i < 8; ++i)
	{
		int xx = x+fx[i];
		int yy = y+fy[i];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && visited[xx][yy] == false)
		{
			visited[xx][yy] = true;
			dfs(xx,yy,tot+1);
			visited[xx][yy] = false;
		}
	 } 
	  
}
int main()
{
	cin >> t;
	while(t--)
	{
		memset(visited,false,sizeof(visited));//��ʼ�����еĵ㶼û���߹� 
		ans = 0;//ÿ��������ݿ�ʼ֮ǰ���Ҫ��ʼ�� 
		cin >> n >> m >> sx >> sy;//n��m�У�(x,y)Ϊ�����ʼλ��
		visited[sx][sy] = true; 
		dfs(sx,sy,1);
		cout << ans << endl; 
	}
	return 0;
}
