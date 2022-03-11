#include <bits/stdc++.h>
using namespace std;

/*
    Bessie's birthday is coming up, and she wishes to celebrate for the next D (1 <= D <= 100,000; 70% of testdata has 1 <= D <= 500) days. Cows have short attention spans so Bessie wants to provide toys to entertain them. She has calculated that she will require T_i (1 <= T_i <= 50) toys on day i.
    Bessie's kindergarten provides many services to its aspiring bovine programmers, including a toy shop which sells toys for Tc (1 <= Tc <= 60) dollars. Bessie wishes to save money by reusing toys, but Farmer John is worried about transmitting diseases and requires toys to be disinfected before use. (The toy shop disinfects the toys when it sells them.)
    The two disinfectant services near the farm provide handy complete services. The first one charges C1 dollars and requires N1 nights to complete; the second charges C2 dollars and requires N2 nights to complete (1 <= N1 <= D; 1 <= N2 <= D; 1 <= C1 <= 60; 1 <= C2 <= 60). Bessie takes the toys to the disinfecters after the party and can pay and pick them back up the next morning if one night service is rendered, or on later mornings if more nights are required for disinfecting.
    Being an educated cow, Bessie has already learned the value of saving her money. Help her find the cheapest way she can provide toys for her party.
*/

int D, N1, N2, C1, C2, Tc, T[100100];
int main(){
    scanf("%d %d %d %d %d %d", &D, &N1, &N2, &C1, &C2, &Tc);
    for(int i = 1; i <= D; ++ i)
        scanf("%d", &T[i]);
    
    return 0;
}
