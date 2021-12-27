#include <bits/stdc++.h>
using namespace std;
int main(){
	string in;
	while(true){
		char tmp = getchar();
		if(tmp == 'E'){
			break;
		}else if(tmp != ' ' && tmp != '\n'){
			in += tmp;
		}
	}
	
	int huahua = 0, enemy = 0, k = 11;
	if(in.length() == 0){
		printf("0:0\n");
	}else{
		for(int i = 0; i < in.length(); ++i){
			switch(in[i]){
				case 'W':
					huahua++;
					break;
				case 'L':
					enemy++;
					break;
			}
//			if(((huahua == k || enemy == k) && (huahua <= k - 2 || enemy <= k - 2)) || ((huahua > k || enemy > k) && abs(huahua - enemy) == 2)){
//				printf("%d:%d\n", huahua, enemy);
//				huahua = 0;
//				enemy = 0;	
//			}
			if((huahua >= k || enemy >= k) && abs(huahua - enemy) >= 2){
				printf("%d:%d\n", huahua, enemy);
				huahua = 0;
				enemy = 0;
			}
		}
		printf("%d:%d\n", huahua, enemy);
		huahua = 0;
		enemy = 0;
	}
	
	printf("\n");
	k = 21;
	
	if(in.length() == 0){
		printf("0:0\n");
	}else{
		for(int i = 0; i < in.length(); ++i){
			switch(in[i]){
				case 'W':
					huahua++;
					break;
				case 'L':
					enemy++;
					break;
			}
//			if(((huahua == k || enemy == k) && (huahua <= k - 2 || enemy <= k - 2)) || ((huahua > k || enemy > k) && abs(huahua - enemy) == 2)){
//				printf("%d:%d\n", huahua, enemy);
//				huahua = 0;
//				enemy = 0;	
//			}
			if((huahua >= k || enemy >= k) && abs(huahua - enemy) >= 2){
				printf("%d:%d\n", huahua, enemy);
				huahua = 0;
				enemy = 0;
			}
		}
		printf("%d:%d\n", huahua, enemy);
		huahua = 0;
		enemy = 0;
	}
	return 0;
}
