#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, r, c, mode = 0, x = 1, y = 1, top = 0, buttom = 0, left = 0, right = 0;
	scanf("%d %d %d", &n, &r, &c);
	const int sum = n * n;
	if(n % 2 && r == c && r == n / 2 + 1){ printf("%d\n", sum); return 0;
	}else if(n % 2 == 0 && c == n / 2 && r == c + 1){ printf("%d\n", sum); return 0; }
	for(int i = 1; i <= sum; ++i){
		if(x == c && y == r){ printf("%d\n", i); return 0; }
		switch(mode){
			case 0:
				if(x < n - right){ x++;
				}else{ mode = 1; top++; y++; }
				break;
			case 1:
				if(y < n - buttom){ y++;
				}else{ mode = 2; right++; x--; }
				break;
			case 2:
				if(x > 1 + left){ x--;
				}else{ mode = 3; buttom++; y--; }
				break;
			case 3:
				if(y > 1 + top){ y--;
				}else{ mode = 0; left++; x++; }
				break;
		}
	}
	return 0;
}


