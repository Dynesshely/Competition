#include <bits/stdc++.h>
#include <sys/stat.h>
using namespace std;
string getTime()
{
  time_t timep;
  time (&timep); //获取time_t类型的当前时间
  char tmp[64];
  strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );//对日期和时间进行格式化
  return tmp;
}

int main(){
	string input, tar, src, location;
	long long replaceTimes = 0;
	cout << getTime() << "\tFile locationi (C:\\)tokens.txt : "; cin >> location;
	cout << getTime() << "\tTo been the replaced token: "; cin >> tar;
	cout << getTime() << "\tTo replace replaced tokens: "; cin >> src;
	cout << getTime() << "\tReading from file tokens.txt ... " << endl;
	clock_t start_read = clock();
	string file = location + "tokens.txt";
	freopen(file.c_str(), "r", stdin);
	getline(cin, input);
	clock_t end_read = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	cout << getTime() << "\tReading finished !" << endl;
	cout << getTime() << "\tReplacing ... " << endl;
	clock_t start_replace = clock();
	for(int i=0;i<input.length();++i){
		if(input[i] == tar[0] && input[i-1] == ' ' && input[i + tar.length()] == ' '){
			bool pass = true;
			for(int j=0;j<tar.length();++j){
				if(tar[j] != input[i + j]){
					pass = false;
					break;
				}
			}
			if(pass){
				input = input.replace(i, tar.length(), src);
				replaceTimes ++;
			}
		}
	}
	clock_t end_replace = clock();
	cout << getTime() << "\tReplaced token for " << replaceTimes << " position" << endl;
	double readingTimes = ((double) end_read - start_read) / CLOCKS_PER_SEC;
	double replacingTimes = ((double) end_replace - start_replace) / CLOCKS_PER_SEC;
	cout << getTime() << "\tReading takes " << readingTimes << " sec" << endl;
	cout << getTime() << "\tReplacing takes " << replacingTimes << " sec" << endl;
	cout << getTime() << "\tShould write data into token_replaced.txt ? (y/n) : ";
	char tmp;
	cin >> tmp;
	bool write = (tmp == 'y' ? true : false);
	if(write){
		string file = location + "tokens_replaced.txt";
		if (access( file.c_str(), F_OK ) == 0){
			remove(file.c_str());
	  }
		freopen(file.c_str(), "w", stdout);
		cout << input << endl;
		freopen("CON", "r", stdin);
		freopen("CON", "w", stdout);
		cout << getTime() << "\tWrite finished!" << endl;
	}
	cout << getTime() << "\tAll had been done !" << endl;
	return 0;
}
