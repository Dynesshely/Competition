#include<bits/stdc++.h>
#define reg register
#define ll long long
#define maxn 200010
#define IT std::set<int>::iterator
#define getchar() (_S==_T&&(_T=(_S=_B)+fread(_B,1,1<<15,stdin),_S==_T)?EOF:*_S++)
char _B[1<<15],*_S=_B,*_T=_B;
int read() {
	reg int s=0,f=1; reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=s*10+ch-'0',ch=getchar());
	return s*f;
}
int n,Q,k,c[maxn],v[maxn],pre[maxn][15],cnt[maxn],t[25],A[15];
ll ans;
bool vis[maxn];
std::set<int>s[maxn];
struct st{st*ls,*rs; int l,r,cnt,pre[12]; ll sum;}T[maxn*4],*Tcnt=T,*rt;
void up(reg st*o) {
	o->sum=o->ls->sum+o->rs->sum; reg int cnt=o->cnt=0,l=0,r=0;
	for(;l<o->ls->cnt&&r<o->rs->cnt;t[cnt++]=o->ls->pre[l]>o->rs->pre[r]?o->ls->pre[l++]:o->rs->pre[r++]);
	for(;l<o->ls->cnt;t[cnt++]=o->ls->pre[l++]); for(;r<o->rs->cnt;t[cnt++]=o->rs->pre[r++]);
	for(reg int i=t[cnt]=0;i<cnt&&o->cnt<=10;++i) t[i]!=t[i+1]?o->pre[o->cnt++]=t[i]:0;
}
void build(reg st*&o,reg int l,reg int r) {
	(o=++Tcnt)->l=l,o->r=r;
	if(l==r) {
		o->sum=v[l];
		for(reg int i=o->cnt=0;i<cnt[l];o->pre[o->cnt++]=pre[l][i++]);
	}
	else {reg int mid=l+r>>1; build(o->ls,l,mid),build(o->rs,mid+1,r),up(o);}
}
void add(reg st*o,reg int a) {
	if(o->l==o->r) {
		o->sum=v[a];
		for(reg int i=o->cnt=0;i<cnt[a];o->pre[o->cnt++]=pre[a][i++]);
	}
	else o->ls->r>=a?add(o->ls,a):add(o->rs,a),up(o);
}
bool query(reg st*o,reg int a) {
	if(o->l>=a) {
		reg int cnt1=0,cnt2=0,l=0,r=0;
		for(;l<cnt[n+1]&&r<o->cnt&&o->pre[r]>=a;t[cnt1++]=A[l]>o->pre[r]?A[l++]:o->pre[r++]);
		for(;l<cnt[n+1];t[cnt1++]=A[l++]); for(;r<o->cnt&&o->pre[r]>=a;t[cnt1++]=o->pre[r++]);
		for(reg int i=t[cnt1]=0;i<cnt1;++i) if(t[i]!=t[i+1]) {
			t[cnt2++]=t[i]; if(cnt2>k) return o->l!=o->r&&query(o->ls,a)?query(o->rs,a):0,0;
		}
		for(reg int i=cnt[n+1]=0;i<cnt2;A[cnt[n+1]++]=t[i++]);
		return ans+=o->sum,1;
	}
	else return o->rs->l<=a||query(o->ls,a)?query(o->rs,a):0;
}
bool cmp(reg int a,reg int b) {return v[a]>v[b];}
int main() {
		freopen("gem.in","r",stdin);
		freopen("gem.out","w",stdout);
	n=read(),Q=read();
	for(reg int i=1;i<=n;++i) s[i].insert(0);
	for(reg int i=1;i<=n;++i) {
		c[i]=read(),v[i]=read(); reg IT it=s[c[i]].insert(i).first; *--it?pre[i][cnt[i]++]=*it:0;
		for(reg int j=0;j<cnt[*it]&&cnt[i]<=10;pre[i][cnt[i]++]=pre[*it][j],++j);
	}
	build(rt,1,n);
	for(reg int op,x;Q--;) {
		op=read(),x=read(),k=read();
		if(op==1) {
			v[x]=read(); if(c[x]==k) {add(rt,x); continue;}
			reg IT it1=s[c[x]].lower_bound(x),it2=it1; ++it1,s[c[x]].erase(it2),it2=it1,--it2; 
			for(reg int i=0;it1!=s[c[x]].end()&&i<=10;add(rt,*it1++),++it2,++i) {
				!(cnt[*it1]=i)&&*it2?pre[*it1][cnt[*it1]++]=*it2:0;
				for(reg int j=i?i-1:0;j<cnt[*it2]&&cnt[*it1]<=10;pre[*it1][cnt[*it1]++]=pre[*it2][j++]);
			}
			it1=s[c[x]=k].insert(x).first,it2=it1,cnt[*it1]=0,*--it2?pre[*it1][cnt[*it1]++]=*it2:0;
			for(reg int i=0;i<cnt[*it2]&&cnt[*it1]<=10;pre[*it1][cnt[*it1]++]=pre[*it2][i++]);
			for(reg int i=0;add(rt,*it1),++it2,++it1!=s[c[x]].end()&&i<=10;pre[*it1][i++]=x)
				for(reg int j=(cnt[*it1]=i+1)-1;j<cnt[*it2]&&cnt[*it1]<=10;pre[*it1][cnt[*it1]++]=pre[*it2][j++]);
		}
		else {
			cnt[n+1]=ans=0,query(rt,x);
			for(reg int i=0,t=cnt[n+1];i<t;++i) if(!vis[c[A[i]]])
				vis[c[A[i]]]=1,A[cnt[n+1]++]=*(s[c[A[i]]].upper_bound(A[i]));
			std::sort(A,A+cnt[n+1],cmp);
			for(reg int i=0;i<cnt[n+1];++i) !vis[c[A[i]]]?ans-=v[A[i]]:vis[c[A[i]]]=0;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
