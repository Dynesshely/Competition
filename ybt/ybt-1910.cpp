#include <bits/stdc++.h>
using namespace std;
bool isChar(char a){
	return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}
bool isNum(char n){
	return n >= '0' && n <= '9';
}
int main(){
	string efx;
	getline(cin, efx);
	int equ = 0, ccc = 0;
	bool operators[1001] = {};
	for(int i = 0; i < efx.length(); ++i){
		if((isChar(efx[i]) || isNum(efx[i])) == false){
			operators[i] = 1;
			if(efx[i] == '=') equ = i;
		}
		if(isChar(efx[i])){
			ccc = i;
		}
	}
	int nums[1001], chars[1001];
	int start = 0, end = 0, charsCount = 0, numsCount = 0;
	for(int i = 0; i < efx.length(); ++i){
		if(isChar(efx[i])){
			for(int j = i; j >= start; -- j){
				if(operators[j] || j == 0){
					string tmp = (efx[j] == '-' ? "-" : "");
					for(int k = j; k < i; ++ k){
						if(isNum(efx[k])){
							tmp += efx[k];
						}
					}
					int tmpp = atoi(tmp.c_str());
					chars[charsCount] = i < equ ? tmpp * -1 : tmpp;
					//cout << chars[charsCount] << endl;
					++ charsCount;
					break;
				}
			}
			start = i;
		}else if((operators[i] && (i - 1 >= 0 ? ! isChar(efx[i - 1]) : true)) || (i == efx.length() - 1 && ! isChar(efx[i]))){
			for(int j = i - (i == efx.length() - 1 ? 0 : 1); j >= start; -- j){
				if(operators[j] || j == 0){
					string tmp = (efx[j] == '-' ? "-" : "");
					for(int k = j + (j == 0 ? 0 : 1); k < i + (i == efx.length() - 1 ? 1 : 0); ++ k){
						tmp += efx[k];
					}
					int tmpp = atoi(tmp.c_str());
					nums[numsCount] = i > equ ? tmpp * -1 : tmpp;
					//cout << nums[numsCount] << endl;
					++ numsCount;
					break;
				}
			}
			start = i;
		}
	}
	int numSum = 0, charSum = 0;
	for(int i = 0; i < numsCount; ++i){
		numSum += nums[i];
//		cout << nums[i] << " ";
	}
//	cout << endl;
	for(int i = 0; i < charsCount; ++i){
		charSum += chars[i];
//		cout << chars[i] << " ";
	}
//	cout << endl;
//	cout << numSum << endl << charSum << endl;
	double res = (numSum * 1.0) / (charSum * 1.0);
	printf("%c=%0.3f\n", efx[ccc], res);
	return 0;
}
