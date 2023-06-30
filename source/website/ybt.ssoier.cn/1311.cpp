#include <bits/stdc++.h>
#include <thread>
using namespace std;
int n, counts = 0, threadEnded = 0, arr[100000];
void call(int start, int end){
	for(int j = start; j < end; ++j){
		for(int i = start; i < j; ++i){
			if(arr[i] > arr[j]){
				counts ++;
			}
		}
	}
	threadEnded ++;
}
int main(){
	scanf("%d", &n);
	memset(arr, 0, n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	if(n <= 100){
		call(0, n);
		printf("%d", counts);
	}else{
		thread a1([]{
			call(0, n / 5);
		}), a2([]{
			call(n / 5, 2 * n / 5);
		}), a3([]{
			call(2 * n / 5, 3 * n / 5);
		}), a4([]{
			call(3 * n / 5, 4 * n / 5);
		}), a5([]{
			call(4 * n / 5, n);
		});
		a1.join();
		a2.join();
		a3.join();
		a4.join();
		a5.join();
		while(true){
			if(threadEnded == 5){
				printf("%d", counts);
				return 0;
			}
		}
	}
	return 0;
}
