#include <bits/stdc++.h>
using namespace std;
bool c7(int n){
	ostringstream os; os << n;
	for(int i = 0; i < os.str().length(); ++ i) if(os.str()[i] == '7') return true;
	return false;
}
int main(){
	freopen("noip-2021-number.cpp", "w", stdout);
	printf("#include <bits/stdc++.h>\n");
	printf("using namespace std;\n");
	printf("bool c7[30000000];\n");
	printf("int main(){\n");
	printf("freopen(\"number.in\", \"r\", stdin);\n");
	printf("freopen(\"number.out\", \"w\", stdout);\n");
	printf("int T; scanf(\"%d\", &T);");
	for(int i = 1; i <= 30000000; ++ i)
		for(int j = 1; j <= i; ++ j)
			if(i % j == 0 && c7(j))
				printf("c7[%d] = 1;\n", j);
	printf("for(int i = 1; i <= T; ++ i)\n");
	printf("if(c7[i]) printf(\"-1\");\n");
	printf("else{\n");
	printf("for(int j = i; j <= T; ++ j)\n");
	printf("if(!c7[j]){printf(\"");
	cout << "%d";
	printf("\\n\", j); break;}\n");
	printf("}\n");
	printf("return 0;");
	printf("}");
	return 0;
}