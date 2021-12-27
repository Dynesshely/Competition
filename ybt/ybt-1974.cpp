#include <bits/stdc++.h>
using namespace std;
bool isLeap(int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
void getYMD(string date, int dts[]){
	dts[0] = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
  dts[1] = (date[4] != '0' ? (date[4] - '0') * 10 : 0) + (date[5] - '0');
	dts[2] = (date[6] != '0' ? (date[6] - '0') * 10 : 0) + (date[7] - '0');
}
const int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool existDate(string date){
	int yy = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	int mm = (date[4] - '0') * 10 + (date[5] - '0');
	int dd = (date[6] - '0') * 10 + (date[7] - '0');
	return mm > 0 && mm <= 12 && days_month[mm - 1] + (mm == 2 && isLeap(yy) ? 1 : 0) >= dd && dd > 0;
}
string createHuiwen(string year){
	string huiwen;
	for(int i = 0; i < 4; ++i){
		huiwen += year[i];
	}
	for(int i = 3; i >= 0; --i){
		huiwen += year[i];
	}
	return huiwen;
}
int dateCompare(string dateP, string dateO){
	// 0 - 相等 1 - 大于 2 - 小于 
	int P[3], O[3]; getYMD(dateP, P); getYMD(dateO, O);
	int py = P[0], pm = P[1], pd = P[2], oy = O[0], om = O[1], od = O[2];
	if(existDate(dateP) && existDate(dateO)){
		if(py == oy){
			if(pm > om){
				return 1;
			}else if(pm < om){
				return 2;
			}else{
				if(pd > od){
					return 1;
				}else if(pd < od){
					return 2;
				}else{
					return 0;
				}
			}
		}else if(py > oy){
			return 1;
		}else{
			return 0;
		}
	}else{
		return -1;
	}
}
int main(){
	string date1, date2;
	long long sum = 0;
	cin >> date1 >> date2;
	int startS[3], endS[3]; getYMD(date1, startS); getYMD(date2, endS);
	int startYear = startS[0], startMM = startS[1], startDD = startS[2],
			endYear = endS[0], endMM = endS[1], endDD = endS[2];
	if(startYear != endYear){
		for(int s = startYear + 1; s < endYear; ++s){
			ostringstream os; os << s;
			string huiwen = createHuiwen(os.str());
			if(existDate(huiwen)){
				sum ++;
			}
		}
		ostringstream os1, os2;
		os1 << startYear; os2 << endYear;
		string l = createHuiwen(os1.str()), r = createHuiwen(os2.str());
		int left = dateCompare(l, date1), right = dateCompare(r, date2);
		if(left == 1 || left == 0){
			sum ++;
		}
		if(right == 2 || right == 0){
			sum ++;
		}
		cout << sum << endl;
	}else{
		string huiwen = createHuiwen(date1);
		int stateleft = dateCompare(huiwen, date1), stateright = dateCompare(huiwen, date2);
		if((stateleft == 1 || stateleft == 0) && (stateright == 2 || stateleft == 0)){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//bool isLeap(int year){
//	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
//}
//int nextday(int now){
//	now_y = now / 10000;
//	now_m = (now - now_y * 10000) / 1000;
//	now_d = (now - now_y * 10000);
//}
//string date1, date2;
//int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int date1_y, date1_m, date1_d, date2_y, date2_m, date2_d;
//void initDate(){
//	date1_y = (date1[0] - '0') * 1000 + (date1[1] - '0') * 100 + (date1[2] - '0') * 10 + (date1[3] - '0');
//	date1_m = (date1[4] - '0') * 10 + (date1[5] - '0');
//	date1_d = (date1[6] - '0') * 10 + (date1[7] - '0');
//	date2_y = (date2[0] - '0') * 1000 + (date2[1] - '0') * 100 + (date2[2] - '0') * 10 + (date2[3] - '0');
//	date2_m = (date2[4] - '0') * 10 + (date2[5] - '0');
//	date2_d = (date2[6] - '0') * 10 + (date2[7] - '0');
//}
//int main(){
//	cin >> date1 >> date2;
//	initDate();
//	//第一个日期当年剩余天数 
//	int d1mleftday = days_month[date1_m - 1] + (isLeap(date1_y) ? 1 : 0) - date1_d, d1yleftmonth = 12 - date1_m;
//	int d1leftdays = d1mleftday + (isLeap(date1_y) ? 1 : 0);
//	for(int i = date1_m; i < 12; ++i){
//		d1leftdays += days_month[i];
//	}
//	//第二个日期当年已有天数
//	int d2hadday = date2_d + (isLeap(date2_y) ? 1 : 0);
//	for(int i = 0; i < date2_m - 1; ++i){
//		d2hadday += days_month[i];
//	}
//	int deltaYear = date2_y - date1_y - 1;
//	int allDays = d1leftdays + d2hadday;
//	if (deltaYear == -1) {
//		allDays -= 365 - 1 + (isLeap(date1_y) ? 1 : 0);
//	}
//	for(int i = 0; i < deltaYear && i != -1; ++i){
//		allDays += 365 + (isLeap(date1_y + i) ? 1 : 0);
//	}
//	cout << d1leftdays << endl << d2hadday << endl << deltaYear << endl << allDays << endl;
//	for(int i = 0; i < allDays; ++i){
//		
//	}
//	return 0;
//}
