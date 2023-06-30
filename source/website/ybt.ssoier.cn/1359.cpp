#include <bits/stdc++.h>
#define S 10
using namespace std;
char _map[S + 2][S + 2];
void via(int x, int y){
	_map[y][x] = '1';
	if(x + 1 < S + 2 && _map[y][x + 1] == '0'){
		via(x + 1, y);
	}
	if(x - 1 >= 0 && _map[y][x - 1] == '0'){
		via(x - 1, y);
	}
	if(y + 1 < S + 2 && _map[y + 1][x] == '0'){
		via(x, y + 1);
	}
	if(y - 1 >= 0 && _map[y - 1][x] == '0'){
		via(x, y - 1);
	}
}
int main(){
	memset(_map, '0', sizeof(_map));
	for(int i = 1; i <= S; ++i){
		for(int j = 1; j <= S; ++j){
			cin >> _map[i][j];
		}
	}
	for(int i = 0; i < S + 2; ++i){
		if(_map[0][i] == '0'){
			via(i, 0);	
		}
		if(_map[S + 1][i] == '0'){
			via(i, S + 1);
		}
	}
	for(int i = 1; i < S + 1; ++i){
		if(_map[i][0] == '0'){
			via(0, i);
		}
		if(_map[i][S + 1] == '0'){
			via(S + 1, i);	
		}
	}
	int squard = 0;
	for(int i = 0; i <= S; ++i){
		for(int j = 0; j <= S; ++j){
			if(_map[i][j] == '0'){
				++ squard;
			}
		}
	}
	printf("%d\n", squard);
	return 0;
}
