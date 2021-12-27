#include<bits/stdc++.h>
using namespace std;

int arr[30][30];
int main() {
	int n;
	cin >> n;

	int num = 1;

	int row = 1, col = n;
	arr[row][col] = num;
	while (num < n * n) {
		while (row + 1 <= n && !arr[row + 1][col])
			arr[++row][col] = ++num;
		while (col - 1 >= 1 && !arr[row][col - 1])
			arr[row][--col] = ++num;
		while (row - 1 >= 1 && !arr[row - 1][col])
			arr[--row][col] = ++num;
		while (col + 1 <= n && !arr[row][col + 1])
			arr[row][++col] = ++num;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";

		cout << endl;
	}

	return 0;
}
