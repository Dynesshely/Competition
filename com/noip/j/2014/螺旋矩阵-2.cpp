#include<bits/stdc++.h>
using namespace std;

bool arr[30001][30001];
int main() {
	int n, i, j;
	scanf("%d %d %d", &n, &i, &j);
	int num = 1, row = 1, col = 1;
	arr[row][col] = num;
	while (1) {
		if(row == i && col == j){
			printf("%d", num);
			return 0;
		}
		while (col + 1 <= n && !arr[row][col + 1]){
			arr[row][++col] = 1;
			++num;
			if(row == i && col == j){
				printf("%d", num);
				return 0;
			}
		}
		while (row + 1 <= n && !arr[row + 1][col]){
			arr[++row][col] = 1;
			++num;
			if(row == i && col == j){
				printf("%d", num);
				return 0;
			}
		}
		while (col - 1 >= 1 && !arr[row][col - 1]){
			arr[row][--col] = 1;
			++num;
			if(row == i && col == j){
				printf("%d", num);
				return 0;
			}
		}
		while (row - 1 >= 1 && !arr[row - 1][col]){
			arr[--row][col] = 1;
			++num;
			if(row == i && col == j){
				printf("%d", num);
				return 0;
			}
		}
	}
	return 0;
}
