#include<bits/stdc++.h>
using namespace std;

int arr[3000][3000];
int main() {
	int n;
	cin >> n;
	cout << endl << endl;
	int num = 1;

	int row = 1, col = 1;
	arr[row][col] = num;
	while (num < n * n) {
		while (col + 1 <= n && !arr[row][col + 1])
			arr[row][++col] = ++num;
		while (row + 1 <= n && !arr[row + 1][col])
			arr[++row][col] = ++num;
		while (col - 1 >= 1 && !arr[row][col - 1])
			arr[row][--col] = ++num;
		while (row - 1 >= 1 && !arr[row - 1][col])
			arr[--row][col] = ++num;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << "\t";
		cout << endl << endl;
	}

	return 0;
}
