#include <bits/stdc++.h>
using namespace std;

int n;

void input() { (void)scanf("%d", &n); }

void process() {
    double walk = n / 1.2;
    double bike = 27 + 23 + n / 3.0;
    if (bike < walk)
        printf("Bike\n");
    else if (walk < bike)
        printf("Walk\n");
    else
        printf("All\n");
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
