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
	long long times;
	cout << getTime() << "\tTo produce token numbers: ";
	scanf("%lld", &times);
	long long tokenNum = 117, headNum = 6, backNum = 14;
	string tokens[tokenNum] = 
	{
		"hi", "hello", "you", "and", "me", "I", "love", "her", "she", "is", "pretty", "fuck", "away",
		"mom", "pop", "int", "string", "long", "short", "dick", "disk", "part", "how", "does", "do", "help",
		"did", "him", "he", "it", "was", "goot", "will", "would", "apple", "soft", "micro", "ware", "document",
		"computer", "population", "government", "butterfly", "watermelon", "azure", "oracle", "pear", "tree", "nine", "eleven", "twlve", "hungry"
		"color", "length", "shortage", "ligle", "law", "tea", "panda", "china", "boom", "gun", "ass", "its", "end",
		"start", "what", "like", "hate", "hen", "child", "children", "root", "administrator", "cloud", "hair", "earth", "jar",
		"calculator", "dictionary", "teacher", "student", "gas", "liquid", "glue", "blue", "green", "modern", "city", "mandacity", "idol",
		"stupid", "idiot", "fool", "foolish", "phone", "eye", "knee", "head", "foot", "food", "three", "javascript", "java",
		"sharp", "csharp", "in", "out", "bamboo", "tiktok", "tencent", "huawei", "harmony", "operate", "system", "boot", "blood"
	};
	string back[backNum] = {"ful", "ly", "fully", "ness", "less", "lessful", "lessfully", "ic", "ion", "ion", "ing", "ed", "s", "es"};
	string head[headNum] = {"im", "in", "un", "dis", "re", "il"};
	srand(time(0));
	string panfu;
	cout << getTime() << "\tYour file directory: ";
	cin >> panfu;
  string file = panfu + "tokens.txt";
  if (access( file.c_str(), F_OK ) == 0){
		cout << getTime() << "\tThe file is existing, we will delete it !" << endl;
		cout << getTime() << "\tDeleting ... " << endl;
		cout << getTime() << "\tDeleted !" << endl;
		remove(file.c_str());
  }
	cout << getTime() << "\tProducing ... " << endl;
	clock_t start_pro = clock();
	freopen(file.c_str(), "w", stdout);
	long long kb = 0;
	for(long long i=0;i<times;++i){
		bool hasHead = rand() % 2, hasBack = rand() % 2;
		long long headIndex = rand() % headNum, backIndex = rand() % backNum, tokenIndex = rand() % tokenNum;
		long long headLeng = head[headIndex].length(), backLeng = back[backIndex].length(), tokenLeng = tokens[tokenIndex].length();
		cout << (hasHead ? head[headIndex] : "") << tokens[tokenIndex] << (hasBack ? back[backIndex] : "") << (i == times - 1 ? "\n" : " ");
		kb += (hasHead ? headLeng : 0) + tokenLeng + (hasBack ? backLeng : 0);
	}
	clock_t end_pro = clock();
	double proTimes = ((double) end_pro - start_pro) / CLOCKS_PER_SEC;
	kb /= 1000;
	freopen("CON", "w", stdout);
	freopen("CON", "r", stdin);
	cout << getTime() << "\tProducing Finished !!! " << endl;
	cout << getTime() << "\tProduced file has a nearly size of " << kb << " KB " << endl;
	cout << getTime() << "\tProducing took time of " << proTimes << " sec " << endl;
	cout << getTime() << "\tProgram Exited !!! " << endl;
	return 0;
}
