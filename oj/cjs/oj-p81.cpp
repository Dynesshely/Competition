#include <bits/stdc++.h>
using namespace std;
int n, na, nb, ia = 0, ib = 0, i, sa = 0, sb = 0;
int main(){
	scanf("%d %d %d", &n, &na, &nb);
	int lpa[na], lpb[nb];
	for(i = 0; i < na; ++ i) scanf("%d", &lpa[i]);
	for(i = 0; i < nb; ++ i) scanf("%d", &lpb[i]);
	for(i = 0; i < n; ++ i){
		if(lpa[ia] != lpb[ib]){
			if(lpa[ia] == 0){
				switch(lpb[ib]){
					case 1: sb ++; break;
					case 2: sa ++; break;
					case 3: sa ++; break;
					case 4: sb ++; break;
				}
			}
			if(lpa[ia] == 1){
				switch(lpb[ib]){
					case 0: sa ++; break;
					case 2: sb ++; break;
					case 3: sa ++; break;
					case 4: sb ++; break;
				}
			}
			if(lpa[ia] == 2){
				switch(lpb[ib]){
					case 0: sb ++; break;
					case 1: sa ++; break;
					case 3: sb ++; break;
					case 4: sa ++; break;
				}
			}
			if(lpa[ia] == 3){
				switch(lpb[ib]){
					case 0: sb ++; break;
					case 1: sb ++; break;
					case 2: sa ++; break;
					case 4: sa ++; break;
				}
			}
			if(lpa[ia] == 4){
				switch(lpb[ib]){
					case 0: sa ++; break;
					case 1: sa ++; break;
					case 2: sb ++; break;
					case 3: sb ++; break;
				}
			}
		}
		ia = ia == na - 1 ? 0 : ia + 1;
		ib = ib == nb - 1 ? 0 : ib + 1;
	}
	printf("%d %d\n", sa, sb);
	return 0;
}
