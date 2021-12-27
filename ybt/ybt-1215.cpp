#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n;
int go[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool vis[110][110];
string str[110];
bool pan_duan(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return false;
	}
	return true;
}
bool dfs(int x, int y) {
	vis[x][y] = true;
	if (str[x][y] == 'T') {
		return true;
	}
	for (int i = 0; i < 4; i++) {
		int tx = go[i][0] + x;
		int ty = go[i][1] + y;
		if (pan_duan(tx, ty) && !vis[tx][ty] && str[tx][ty] != '#') {
			if (dfs(tx, ty)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		int x, y, ty, tx;
		scanf("%d%d%d%d", &x, &y, &tx, &ty);
		if (str[x][y] == '#' || str[tx][ty] == '#') {
			printf("NO\n");
			continue;
		}
		str[x][y] = 'S';
		str[tx][ty] = 'T';
		if (dfs(x, y)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = false;
			}
		}
	}
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//string a[1005]; //存字符的数组  不用char输入,因为读入怕超时 
//bool v[1005][1005];//该字符是否已经走过 
//int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //上下左右四个方向的移动坐标 
//int k,n,ha,la,hb,lb; 
//bool dfs(int x,int y){
//	v[x][y] = 1;  //读入之后,要马上标志,(初始标志没初始化,所以会走回到原来位置) 
//	if(x==hb && y==lb){
//		return true;
//	}
//	for(int i=0;i<4;i++){
//		int xx = x + go[i][0];
//		int yy = y + go[i][1];
//		if( xx>=0 && x<n && y>=0 && y<n && v[xx][yy]==0 && a[xx][yy]=='.' ) {
//			if (dfs(xx, yy)) {
//				return true;
//			} 
//			// 不用回溯,因为走过走不动,以后就不走了. 
//		}
//	}
//	return false;
//}
//int main(){
////	std::ios::sync_with_stdio(false); // 加了出错,不知道为什么. 
//	freopen("cpp.in","r",stdin);
//	freopen("cpp.out","w",stdout);	 
//	scanf("%d",&k);
//	while(k--){ 
//		scanf("%d",&n); 
//		memset(v,0,sizeof(v));
//		for(int i=0;i<n;i++){
//			a[i]="";
//			cin>>a[i];
//		} 
//		scanf("%d%d%d%d",&ha,&la,&hb,&lb);
//		if(a[ha][la]=='#'||a[hb][lb]=='#'){
//			cout<<"NO"<<endl;
//			continue;
//		} 
//		if(dfs(ha,la)){
//			cout<<"YES"<<endl;
//		}else{
//			cout<<"NO"<<endl;
//		} 
//	}	
//	return 0;
//}

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//int n;
//char maps[233][233];
//bool v[233][233];
//int dx[] = {0,1,0,-1,0};
//int dy[] = {0,0,1,0,-1};
//int sx, sy, ex, ey;
//
//struct loc{
//    int x, y;
//};
//
//queue <loc> q;
//void bfs(int sx, int sy)
//{
//    q.push((loc){sx,sy});
//    v[sx][sy] = 1;
//    while(q.size())
//    {
//        loc nw = q.front();
//        q.pop();
//        if(nw.x == ex && nw.y == ey){
//            cout << "YES" << endl;
//            return;
//        }
//        for(int i = 1; i <= 4; i ++)
//        {
//            int x = nw.x + dx[i];
//            int y = nw.y + dy[i];
//            if(x > 0 && x <= n && y > 0 && y <= n && maps[x][y] != '#' && !v[x][y])
//            {
//                q.push((loc){x,y});
//                v[x][y] = 1;
//            }
//        }
//    }
//    cout << "NO" << endl;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    cin >> n;
//    for(int i = 1; i <= n; i ++)
//        for(int j = 1; j <= n; j ++){
//            cin >> maps[i][j];
//            if(maps[i][j] == 's')
//                sx = i,sy = j;
//            else if(maps[i][j] == 'e')
//                ex = i; ey = j;
//        }
//    bfs(sx,sy);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <queue>
//#define MAXN 20
//using namespace std;
//int map[MAXN][MAXN],n;
//int visit[MAXN][MAXN];
//int steparr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//struct Node{
//	int x,y,step;
//	Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}
//};
//int bfs(){
//	Node node(0,0,0);
//	queue<Node> q;
//	while(!q.empty()) q.pop();
//	q.push(node);
//	while(!q.empty()){
//		node=q.front();
//		q.pop();
//		if(node.x==n-1&&node.y==n-1)
//		return node.step;
//		visit[node.x][node.y]=1;
//		for(int i=0;i<4;i++){
//			int x=node.x+steparr[i][0];
//			int y=node.y+steparr[i][1];
//			if(x>=0&&x<n&&y>=0&&y<n&&visit[x][y]==0&&map[x][y]==0){
//				visit[x][y]=1;
//				Node next(x,y,node.step+1);
//				q.push(next);
//			}
//		}
//	}
//	return -1;
//}
//int main()
//{
// int i,j,k,m;
// char in[MAXN];
// scanf("%d",&m);
// while(m--)
// {
//  memset(map,0,sizeof(map));
//  memset(visit,0,sizeof(visit));
//  scanf("%d",&n);
//  for(i=0;i<n;i++) //第i行的循环
//  {
//   memset(in,0,sizeof(in));
//   scanf("%s",in);
//   for(j=0;j<n;j++) //第j列的循环
//   {
//    switch(in[j])
//    {
//     case 's':
//     {
//      map[i][j]=0;
//      break;
//     }
//     case '.':
//     {
//      map[i][j]=0;
//      break;
//     }
//     case '#':
//     {
//      map[i][j]=1;
//      break;
//     }
//     case 'e':
//     {
//      map[i][j]=0;
//      break;
//     }
//    }
//   }
//  }
//  if(bfs()==-1)
//   printf("NO\n");
//  else
//   printf("YES\n");
// }
// return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int maxn=21;
//string s[maxn];
//int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
//bool used[maxn][maxn];
//int m,n;
//struct node
//{
//		int x,y;
//};
//bool can(int x,int y)
//{
//		if(x<0||x>=n||y<0||y>=n) return 0;
//		if(s[x][y]=='#') return 0;//if(s[x][y]=="#") return 0;//字符用单引号
//		if(used[x][y]) return 0;
//		return 1;
//}
//string bfs()//注意函数类型
//{
//		memset(used,0,sizeof(used));
//		queue<node>q;
//		while(!q.empty()) q.pop();
//		q.push((node){0,0});
//		used[0][0]=1;
//		while(!q.empty())
//		{
//				node f=q.front();
//				q.pop();
//				if(s[f.x][f.y]=='e') return "YES";
//				for(int i=0;i<4;i++)
//				{
//						node n;
//						n.x=f.x+dx[i];
//						n.y=f.y+dy[i];
//						if(can(n.x,n.y))
//						{
//								q.push(n);
//								used[n.x][n.y]=1;
//						}
//				}
//		}
//		return "NO";
//}
//int main()
//{
//		scanf("%d",&m);
//		while(m--)
//		{
//				//memset(s,0,sizeof(s));不知道为什么不能初始化
//				scanf("%d",&n);
//				for(int i=0;i<n;i++)
//				{
//						cin>>s[i];
//				}
//				cout<<bfs()<<'\n';
//		}
//		return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int xa, ya, xb, yb, num, t;
//string ans;
//char _map[1000][30][30];
//bool via[30][30];
//bool pass = false;
//void search(int row, int col, int index){
//	if(row == yb && col == xb){
//		pass = true;
//		return;
//	}
//	via[row][col] = 1;
//	if(row > 0 && _map[index][row - 1][col] != '#' && via[row - 1][col] == 0){ //向上 
//		search(row - 1, col, index);
//	}
//	if(col < num - 1 && _map[index][row][col + 1] != '#' && via[row][col + 1] == 0){ //向右
//		search(row, col + 1, index);
//	}
//	if(row < num - 1 && _map[index][row + 1][col] != '#' && via[row + 1][col] == 0){ //向下
//		search(row + 1, col, index);
//	}
//	if(col > 0 && _map[index][row][col - 1] != '#' && via[row][col - 1] == 0){ //向左
//		search(row, col - 1, index);
//	}
//	via[row][col] = 0;
//}
//int main(){
//	cin >> t;
//	for(int i = 0; i < t; ++i){
//			cin >> num;
//			for(int j = 0; j < num; ++j){
//				for(int k = 0; k < num; ++k){
//					cin >> _map[i][j][k];
//				}
//			}
//			cin >> ya >> xa >> yb >> xb;
//			if(_map[i][ya][xa] != '#' && _map[i][yb][xb] != '#'){
//				search(ya, xa, i);
//				if(pass){
//					ans += "YES\n";
//				}else{
//					ans += "NO\n";
//				}
//			}else{
//				ans += "NO\n";
//			}
//			pass = false;
//			memset(via, 0, sizeof(via));
//	}
//	cout << ans << endl;
//	return 0;
//}
