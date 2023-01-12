#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
//	string my_str;
//	printf("请输入目标窗口标题：");
//	scanf("%s", &my_str);
//	LPCSTR target = my_str.c_str();
  HWND h = FindWindow(NULL, "C:\\Users\\23699\\OneDrive\\Development\\Cpp\\Memory\\untest.exe") ;//获取窗口句柄
  DWORD processid;
  GetWindowThreadProcessId(h,&processid);//获取进程id
  cout << "进程ID为：" << processid << endl;
  HANDLE Hprocess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,processid);
  if(Hprocess == 0){
  	printf("打开进程失败！\n");
	} else {
    printf("打开进程成功！\n");
    int n; LPVOID address;
    printf("要修改的内存地址: ");
    cin >> address;
    printf("修改为：");
    scanf("%d",&n);
    DWORD life;
    life=(DWORD)n;
    DWORD a=WriteProcessMemory(Hprocess,(LPVOID)(address),&life,4,0);//注意参数
    if(a==0)
    printf("修改失败！");
    else
    printf("修改成功！");
  }
  return 0;
}
