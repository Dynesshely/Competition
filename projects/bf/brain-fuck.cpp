#include <bits/stdc++.h>
using namespace std;
int cursor = 0, size, cmd_cursor = 0, loopIndex = 0;
string version = "v0.1.1";
void exe(string cmd), start();
void start(){
	printf("You got into Brain Fuck compiler.\n");
	printf("This software helps you to run Brain Fuck codes.\n");
	printf("Now version : %s\n", version.c_str());
	printf("Chars & its meanings : \n");
	printf("\t >  - move cursor to next memory.\n");
	printf("\t <  - move cursor to previous memory.\n");
	printf("\t +  - increase the value of the current memory by 1.\n");
	printf("\t -  - decrease the value of the current memory by 1.\n");
	printf("\t .  - print the value of the current memory in ASCII.\n");
	printf("\t[ ] - enter a loop and break while the value of current memory is 0.\n");
}
int main(int argc, char *argv[]){
	if(argc == 1){
		start();
		printf("Set a max size of your memory(max:100000): ");
		scanf("%d", &size);
		printf("Memory settings successed, your memory is about %d size.\n", size);
		printf("Input you Brain Fuck codes in one line:\n");
		string cmd; cin >> cmd;
		exe(cmd);
	}else{
		size = 1000;
		string cmd(argv[1]);
		exe(cmd);
	}
	return 0;
}
void exe(string cmd){
	unsigned short mem[size]; // 内存
	memset(mem, 0, sizeof(mem)); // 内存清零
	int loopStart = -1; // 循环开始
	bool looping = false; // 是否在循环
	for(int i = 0; i < cmd.length(); ++ i){
		switch(cmd[i]){
			case '>': cursor ++; break; // 指针右移
			case '<': cursor --; break; // 指针左移
			case '+': // 内存值加一
				if(cursor >= 0 && cursor < size){
					mem[cursor] ++;
					if(mem[cursor] == 256) mem[cursor] = 0;
				}else return;
				break;
			case '-': // 内存值减一
				if(cursor >= 0 && cursor < size){
					mem[cursor] --;
					if(mem[cursor] == -1) mem[cursor] = 255;
				}else return;
				break;
			case '.': // 输出内存
				printf("%c", (char)mem[cursor]);
				break;
			case '[': // 开始循环
				loopStart = i;
				looping = true;
				break;
			case ']': // 结束循环
				if(mem[cursor] == 0) looping = false;
				else i = loopStart;
				break;
			case '$': // 聚合
				
				break;
		}
	}
	printf("\n");
	return;
}
