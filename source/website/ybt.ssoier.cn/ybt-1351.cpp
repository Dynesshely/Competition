#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> people[101];
void up(int i){
    
    
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++ i){
        int j = -1;
        while{
            scanf("%d", j);
            if(j == 0){
                break;
            }
            people[j].push_back(i);
        }
    }
    int zero[101], index = 0;
    for(int i = 1; i <= N; ++ i){
        if(people[i].size() == 0){
            zero[index++] = i;
        }
    }
    for(int i = 0; i < index; ++ i){
        up(i);
    }
    return 0;
}