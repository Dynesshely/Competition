#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
//	string my_str;
//	printf("������Ŀ�괰�ڱ��⣺");
//	scanf("%s", &my_str);
//	LPCSTR target = my_str.c_str();
  HWND h = FindWindow(NULL, "C:\\Users\\23699\\OneDrive\\Development\\Cpp\\Memory\\untest.exe") ;//��ȡ���ھ��
  DWORD processid;
  GetWindowThreadProcessId(h,&processid);//��ȡ����id
  cout << "����IDΪ��" << processid << endl;
  HANDLE Hprocess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,processid);
  if(Hprocess == 0){
  	printf("�򿪽���ʧ�ܣ�\n");
	} else {
    printf("�򿪽��̳ɹ���\n");
    int n; LPVOID address;
    printf("Ҫ�޸ĵ��ڴ��ַ: ");
    cin >> address;
    printf("�޸�Ϊ��");
    scanf("%d",&n);
    DWORD life;
    life=(DWORD)n;
    DWORD a=WriteProcessMemory(Hprocess,(LPVOID)(address),&life,4,0);//ע�����
    if(a==0)
    printf("�޸�ʧ�ܣ�");
    else
    printf("�޸ĳɹ���");
  }
  return 0;
}
