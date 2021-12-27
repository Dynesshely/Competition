#include <stdio.h>
int main()
{
    int a,b,c;//abc分别代表6元，5元，4元的数目 
    int x,y;  //x,y分别表示剩余班费和买完最多的4元笔后剩的钱
     
    scanf("%d",&x);
    c=x/4;
    y=x%4;
    switch(y)
    {
        case 0:
            a=0;
            b=0;
            break;
        case 1:
            a=0;
            b=1;
            c--;
            break;
        case 2:
            a=1;
            b=0;
            c--;
            break;
        case 3:
            a=1;
            b=1;
            c-=2;
    }
    printf("%d %d %d\n",a,b,c);
    
    return 0;
}
