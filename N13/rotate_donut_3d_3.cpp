#include <bits/stdc++.h>
using namespace std;
float A = 0, B = 0, i, j, z[1760];
long long sleepT = 30000;
int k; char b[1760];
const float hjf = 6.28, jzen = 0.07, izen = 0.02, Azen = 0.00004, Bzen = 0.00002;
int main(){
	printf("Input your target speed (greater then slower) : ");
	scanf("%lld", &sleepT);
    for(;;){
        memset(b,32,1760); memset(z,0,7040);
        for(j=0; j < hjf; j += jzen) {
            for(i=0; i < hjf; i += izen) {
            	float c, d, e, f, g, h, D, l, m, n, t;
            	int x, y, o, N;
                c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A), h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i), m = cos(B), n = sin(B), t = c * h * g - f * e;
                x = 40 + 30 * D * (l * h * m - t * n), y= 12 + 15 * D * (l * h * n + t * m);
                o = x + 80 * y, N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += Azen;
            B += Bzen;
        }
        usleep(sleepT);
        system("cls");
        cout<<"Copyright @ Catrol, 2021"<<endl<<"3D Rotate Round Donut"<<endl;
    }
    return 0;
}