#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
#define ll long long
#define dmax(x, y) ((x) < (y)? (y): (x))
#define For(i, f, t) for (int i = f; i <= t; i++)
 
const int MaxN = 100010, Mod = (1e9) + 7, Log = 17;
 
int N, vA[MaxN], vB[MaxN];
ll d[MaxN], Ans[MaxN];
int F[MaxN][Log + 1];
int *V;
 
void mmod(ll &x)
{
	x = (x % Mod + Mod ) % Mod;
}
 
int getmax(int l, int r)
{
	int Log2 = (int)(log(r - l + 1) / log(2));
//	printf("Log2 = %d, ", Log2);
	if(V[ F[l][Log2] ] > V[ F[r - (1 << Log2) + 1][Log2] ])
		return F[l][Log2];
	return F[r - (1 << Log2) + 1][Log2];
}
 
void Solve(int l, int r)
{
	if(l > r) return;
	int pos = getmax(l, r), L1 = pos - l + 1, L2 = r - pos + 1;
//	printf("from l:%d to r:%d, get pos = %d\n", l, r, pos);
//	for(int i = 1; i <= 300000000; i++);
	if(L1 > L2) swap(L1, L2);
	d[1] += V[pos];			mmod(d[1]);
	d[L1 + 1] -= V[pos];	mmod(d[L1 + 1]);
	d[L2 + 1] -= V[pos];	mmod(d[L2 + 1]);
	d[r - l + 3] += V[pos];	mmod(d[r - l + 3]);
	Solve(l, pos - 1);
	Solve(pos + 1, r);
}
 
void Work()
{
	memset(d, 0, sizeof(d));
	For (i, 1, N) F[i][0] = i;
	For (j, 1, Log)
		For (i, 1, N)
		{
			if(i + (1 << (j-1)) <= N)
			{
				if(V[ F[i][j-1] ] > V[ F[i + (1 << (j-1))][j-1] ])
					F[i][j] = F[i][j-1];
				else F[i][j] = F[i + (1 << (j-1))][j-1];
			}
			else F[i][j] = F[i][j-1];
		}
	/*
	printf("Log:%d\n", Log2);
	For (i, 1, N)
	{
		printf("#i:%d ",i);
		For(j, 0, Log2)
		{
			printf("(%d,%d)",j,F[i][j]);
		}
		puts("");
	}
	*/
	Solve(1, N);
	For (i, 1, N) d[i] = (d[i] + d[i-1]) % Mod;
	For (i, 1, N) d[i] = (d[i] + d[i-1]) % Mod;
	For (i, 1, N) Ans[i] = (Ans[i] * d[i]) % Mod;
}
 
int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	scanf("%d", &N);
	For(i, 1, N) scanf("%d", &vA[i]), vA[i] += i;
	For(i, 1, N) scanf("%d", &vB[i]), vB[i] += i;
	For(i, 1, N) Ans[i] = 1;
	V = vA; Work();
	V = vB; Work();
	For(i, 1, N) printf("%lld ", Ans[i]); puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
