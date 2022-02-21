#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    bool flag;
    int color;
    pair<int ,int>temp;
    int value;
    int hei;
}arr[120][120];
int x[5]={0,1,0,-1};
int y[5]={1,0,-1,0};
 
int main()
{
    int m,n;
    int fuyi=-1;            //判断是不是可以达到。
    queue <node>que;
	scanf("%d %d",&m,&n);
    if(m==1)
    {
        cout<<0<<endl;
        goto xxx;
    }
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<120;i++)
        for(int j=0;j<120;j++)
        {
            arr[i][j].temp.first=i;
            arr[i][j].temp.second=j;
            arr[i][j].flag=false;
            arr[i][j].value=~(1<<31);
        }
    arr[1][1].value=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        scanf("%d",&arr[a][b].color);
        arr[a][b].flag=true;
    }
    que.push(arr[1][1]);
    while(!que.empty())
    {
        node temp=que.front();
        que.pop();
        arr[temp.temp.first][temp.temp.second].hei=100;
        for(int i=0;i<4;i++)
        {
            int thex=temp.temp.first;
            int they=temp.temp.second;
            int thex1=thex+x[i];
            int they1=they+y[i];
            if(thex1<=m&&thex1>=1&&they1>=1&&they1<=m&&arr[thex1][they1].hei!=100)      //加入的时候判定一下hei是不是等于负一。
            {
                if(temp.flag==true)
                {
                    if(thex1==m&&they1==m)fuyi=100;     //其中的逻辑问题吗
                    if(arr[thex1][they1].flag==false)
                    {
                        if(temp.value+2<arr[thex1][they1].value)
                        {
                            arr[thex1][they1].value=temp.value+2;
                            arr[thex1][they1].color=arr[thex][they].color;
                            que.push(arr[thex1][they1]);
                        }
                    }
                    else if(arr[thex1][they1].color==arr[thex][they].color)
                    {//颜色相等。
                        if( temp.value<arr[thex1][they1].value )      //这里。
                        {
                            arr[thex1][they1].value=temp.value;
                            que.push(arr[thex1][they1]);
                        }
                    }
                    else//颜色不等。
                    {
                        if(temp.value+1<arr[thex1][they1].value)
                        {
                            arr[thex1][they1].value=temp.value+1;
                            que.push(arr[thex1][they1]);
                        }
                    }
                }
                else     //说明是当前的位置是施魔法得来的。
                {
                    if(thex1==m&&they1==m&&arr[thex1][they1].flag==true)fuyi=100;
                    if(arr[thex1][they1].flag==false)
                    {
                    }
                    else if(arr[thex1][they1].color==arr[thex][they].color) //对啊。魔法而来。
                    {
                        if( temp.value<arr[thex1][they1].value )      //这里。
                        {
                            arr[thex1][they1].value=temp.value;
                            que.push(arr[thex1][they1]);
                        }
                    }
                    else
                    {
                        if(temp.value+1<arr[thex1][they1].value)
                        {
                            arr[thex1][they1].value=temp.value+1;
                            que.push(arr[thex1][they1]);
                        }
                    }
                }
            }
        }
    }
    if(fuyi!=100)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<arr[m][m].value<<endl;
    }
    xxx:;
    return 0;
}


//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int Map[111][111],f[111][111];
//int X1[5]={0,1,-1,0,0},Y1[5]={0,0,0,1,-1};
//int X2[9]={0,2,-2,0,0,1,1,-1,-1};
//int Y2[9]={0,0,0,2,-2,1,-1,1,-1};
//int m,n,x,y,color;
// 
//void dfs(int a,int b,int c,int cost){
//    if(cost>=f[a][b])return;
//    else f[a][b]=cost;
//    for(int i=1;i<=4;i++){
//        int nx=a+X1[i],ny=b+Y1[i];
//        if(nx>=1&&ny>=1&&nx<=m&&ny<=m&&Map[nx][ny]){
//            int ccc=(c!=Map[nx][ny])?001:000;
//            dfs(nx,ny,Map[nx][ny],cost+ccc);
//        }
//    }
//    for(int i=1;i<=8;i++){
//        int nx=a+X2[i],ny=b+Y2[i];
//        if(nx>=1&&ny>=1&&nx<=m&&ny<=m&&Map[nx][ny]){
//            int ccc=(c!=Map[nx][ny])?003:002;
//            dfs(nx,ny,Map[nx][ny],cost+ccc);
//        }
//    }
//}
// 
//int main(){
//    scanf("%d%d",&m,&n);
//    for(int i=1;i<=n;i++){
//        scanf("%d%d",&x,&y);
//        scanf("%d",&color);
//        Map[x][y]=color+1;
//    }
//    for(int i=1;i<=m;i++)
//        for(int j=1;j<=m;j++)
//            f[i][j]=555555;
//    dfs(1,1,Map[1][1],0);
//    if(f[m][m]!=555555)
//        printf("%d",f[m][m]);
//    else
//        printf("-1");
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int dx[4]={0,-1,1,0};
//int dy[4]={1,0,0,-1};
//int minn[101][101],_minn=2<<30-1;
//int m,n,color[101][101],maxn=2<<30-1;
//bool pd=false;
//void dfs(int x,int y,int ans,int magic)
//{
//    if(x==m && y==m)
//    {
//        pd=true;
//        _minn=min(_minn,ans);
//        return;
//    }
//    if(ans>=_minn) return;
//    if(ans>=minn[x][y]) return;
//    minn[x][y]=ans;
//    for(int i=0;i<4;i++)
//    {
//        int xx=x+dx[i],yy=y+dy[i];
//        if(xx<1||xx>m||yy<1||yy>m) continue;
//        if(color[xx][yy]==0 && magic==0)
//        {
//            color[xx][yy]=color[x][y];
//            dfs(xx,yy,ans+2,1);
//            color[xx][yy]=0;
//        }
//        else if(color[xx][yy]>0) 
//        {
//            if(color[xx][yy]==color[x][y])dfs(xx,yy,ans,0);
//            else if(color[xx][yy]!=color[x][y])    dfs(xx,yy,ans+1,0);
//        }
//    }
//    return;
//}
//inline int read()
//{
//    int f=1,ans=0;char c;
//    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
//    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
//    return f*ans;
//}
//int main()
//{
//    m=read(),n=read();
//    for(int i=1;i<=m;i++)
//        for(int j=1;j<=m;j++) minn[i][j]=maxn;
//    for(int i=1;i<=n;i++)
//    {
//        int x=read(),y=read(),c=read();
//        color[x][y]=++c;
//    }
//    dfs(1,1,0,0);
//    if(!pd) cout<<-1;
//    else cout<<_minn+342;
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int chess[110][110]={0};
//int flag[110][110]={0};
//int dx[5]={-1,0,0,1};
//int dy[5]={0,1,-1,0};
//int m,n,total=100100;
//int dgp(int x,int y,int color,int sum){
//    if(x==m&&y==m&&sum<total){total=sum; return 0;}
//    for(int i=1;i<=4;i++){
//        int xx=x+dx[i],yy=y+dy[i];
//        if(!flag[xx][yy]&&chess[xx][yy]!=-2&&(chess[x][y]!=0||chess[xx][yy]!=0)){
//            flag[xx][yy]=1;
//            if(chess[xx][yy]==chess[x][y]||(chess[x][y]==0&&color==chess[xx][yy]))dgp(xx,yy,chess[x][y],sum);
//            else if(chess[xx][yy]==0)dgp(xx,yy,chess[x][y],sum+2);
//                else dgp(xx,yy,chess[x][y],sum+1);
//            flag[xx][yy]=0;
//        }   }
//}
//int main(){
//    int x,y,c;
//    cin>>m>>n;
//    for(int i=0;i<=m+1;i++) chess[i][0]=chess[0][i]=chess[m+1][i]=chess[i][m+1]=-2;
//    for(int i=1;i<=m;i++) 
//        for(int j=1;j<=m;j++)
//            chess[i][j]=0;
//    for(int i=1;i<=n;i++){
//        cin>>x>>y>>c; 
//        chess[x][y]=c+1;
//    }
//    flag[1][1]=1;
//    dgp(1,1,0,0);
//    if (total==100100) cout <<-1;
//    else cout<<total;
//    return 0;
//}
