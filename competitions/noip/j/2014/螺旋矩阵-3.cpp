#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, row, col; // n - �߳�, row - �ڼ���, col - �ڼ��� 
	scanf("%lld %lld %lld", &n, &row, &col); // ¼������ 
	const int sum = n * n; // ���ֵ ��� 
	bool odd = n % 2; // �Ƿ�Ϊ���� 
	if(odd && row == col && row == n / 2 + 1){
		printf("%d\n", sum);
		return 0;
	} // �����߳����ĵ��Ż��㷨 
	else if(odd == 0 && col == n / 2 && row == col + 1){
		printf("%d\n", sum);
		return 0;
	} // ż���߳���������Ż��㷨 
	const long long layers = (odd ? n / 2 + 1 : n / 2); // �ܲ��� 
	long long margin[4] = {col - (odd ? 0 : 1), row - (odd ? 0 : 1), n - col + (odd ? 1 : 0), n - row + (odd ? 1 : 0)}; // row,col ��߾� 
	long long lay, kept, rmed;
	sort(margin, margin + 4); // ��߾����� 
	bool onBorder = margin[0] || (col != 0 && row != 0);
	lay = (onBorder ? layers - margin[0] + (odd ? 1 : 0) : layers); // row,col ���ڲ����������������� 
	kept = (onBorder ? 2 * lay + (odd ? -1 : 0) : n); // ������߳� 
	rmed = sum - kept * kept; // �Ƴ����Ŀ� 
	// printf("lay: %d, kept: %d, rmed: %d", lay, kept, rmed); // �������
	long long ncol = col - (layers - lay), nrow = row - (layers - row), pilled = layers - lay;
	long long x = pilled + 1, y = x, mode = 0;
	for(long long i = rmed + 1; i <= sum; ++i){
		if(x == col && y == row){ printf("%lld\n", i); return 0; }
		switch(mode){
			case 0:
				if(x < n - pilled){ x++;
				}else{ mode = 1; y++; }
				break;
			case 1:
				if(y < n - pilled){ y++;
				}else{ mode = 2; x--; }
				break;
			case 2:
				if(x > pilled){ x--;
				}else{ mode = 3; y--; }
				break;
			case 3:
				if(y > pilled){ y--;
				}else{ mode = 0; x++; }
				break;
		}
	}
	return 0;
}
