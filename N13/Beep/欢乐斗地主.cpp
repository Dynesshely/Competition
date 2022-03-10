#include "music.h"
using namespace std;

int main(){
    int	pai	= 400, ban = 200;
    int	ting = 128, half = 64;
    Sleep(100);
    Beep(so1, ting);
    Beep(so1, half);
    Beep(la1, ting);
    Beep(so1, ting);
    Beep(mi1, ting);
    Beep(so1, ting);
    Sleep(1500);
    Beep(do1, ting);
    Beep(do1, half);
    Beep(re1, ting);
    Beep(do1, ting);
    Beep(la, ting);
    Beep(do1, ting);
    return 0;
}

