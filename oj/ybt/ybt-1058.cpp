#include <bits/stdc++.h>
using namespace std;
float a, b, c, d, x1, x2;
int main(){
    scanf("%f %f %f", &a, &b, &c);
    d = b * b - 4 * a * c;
    if(d > 0.0){
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("x1=%0.5f;x2=%0.5f\n", min(x1, x2), max(x1, x2));
    }else if(d == 0.0){
        x1 = -b / (2 * a);
        printf("x1=x2=%0.5f\n", x1);
    }else if(d < 0.0) printf("No answer!\n");
    return 0;
}
