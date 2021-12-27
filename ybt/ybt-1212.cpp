#include <bits/stdc++.h>
using namespace std;
int R, S, counts = 1;
char _map[30][30];
bool via[26];
void search(int row, int col, int len){
	via[_map[row][col] - 'A'] = 1;
	counts = max(counts, len);
	//printf(" - (%d, %d) - len - %d - \n", col, row, len);
	if(row > 0 && via[_map[row - 1][col] - 'A'] != 1){ //ÏòÉÏ 
		search(row - 1, col, len + 1);
	}
	if(col < S - 1 && via[_map[row][col + 1] - 'A'] != 1){ //ÏòÓÒ
		search(row, col + 1, len + 1);
	}
	if(row < R - 1 && via[_map[row + 1][col] - 'A'] != 1){ //ÏòÏÂ
		search(row + 1, col, len + 1);
	}
	if(col > 0 && via[_map[row][col - 1] - 'A'] != 1){ //Ïò×ó
		search(row, col - 1, len + 1);
	}
	via[_map[row][col] - 'A'] = 0;
}
int main(){
	cin >> R >> S;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < S; ++j){
			cin >> _map[i][j];
		}
	}
	search(0, 0, 1);
	cout << counts << endl;
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//int R, S, counts=1;
//char _map_[30][30];
//bool via[28];
//void search(int x, int y, int len){
//	if(y+1 != R-1 && via[_map_[y+1][x] - 'A'] == 0){ // ÏòÏÂ 
//		via[_map_[y+1][x] - 'A']=1;
//		counts = max(counts, len);
//		search(x, y+1, len + 1);
//		via[_map_[y+1][x] - 'A']=0;
//	}
//	if(y-1 != -1 && via[_map_[y-1][x] - 'A'] == 0){ // ÏòÉÏ 
//		via[_map_[y-1][x] - 'A']=1;
//		counts = max(counts, len);
//		search(x, y-1, len + 1);
//		via[_map_[y-1][x] - 'A']=0;
//	}
//	if(x+1 != S-1 && via[_map_[y][x+1] - 'A'] == 0){ // ÏòÓÒ 
//		via[_map_[y][x+1] - 'A']=1;
//		counts = max(counts, len);
//		search(x+1, y, len + 1);
//		via[_map_[y][x+1] - 'A']=0;
//	}
//	if(x-1 != -1 && via[_map_[y][x-1] - 'A'] == 0){ // Ïò×ó 
//		via[_map_[y][x-1] - 'A']=1;
//		counts = max(counts, len);
//		search(x-1, y, len + 1);
//		via[_map_[y][x-1] - 'A']=0;
//	}
//}
//int main(){
//	cin >> R >> S;
//	for(int i=0;i<R;++i){
//		for(int j=0;j<S;++j){
//			cin >> _map_[i][j];
//		}
//	}
//	for(int i=0;i<26;++i){
//		via[i] = 0;
//	}
//	search(0, 0, 1);
//	cout << counts << endl;
//	return 0;
//}
