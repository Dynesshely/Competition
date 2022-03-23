#include <stdio.h>
char*s="#include <stdio.h>%cchar*s=%c%s%c;%cmain(){printf(s,10,34,s,34,10,10);}%c";
main(){printf(s,10,34,s,34,10,10);}