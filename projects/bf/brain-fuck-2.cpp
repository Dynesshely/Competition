#include<iostream>
#include<cstring>
const int MAXSIZE = 100000;
using namespace std;
void parse(char*, int&, int&, char*, int*);
int main(){
    char str[MAXSIZE];
    int rel[MAXSIZE];
    int pos = 0;
    int ptr = 0;
    char arr[MAXSIZE];
    memset(str, 0, sizeof(str));
    memset(arr, 0, sizeof(arr));
    memset(rel, 0, sizeof(rel));
    char flag;
    int i = 0;
    while(flag != EOF){
        flag = getchar();
        str[i++] = flag;
    }
    int l = 0, end = strlen(str);
    while (l!=end){
        while (l<end && str[l++] != '[');
        auto r = l;
        int count = 1;
        for (; r < end; r++){
            if (str[r] == '[')count++;
            if (str[r] == ']'){
                count--; if (count == 0){
                    r++; break;
                }
            }
        };
        rel[l - 1] = r-1; rel[r - 1] = l-1;
    }
    while (str[pos] != '\0'){
        parse(str, pos, ptr, arr, rel);
        pos++;
    }
 
    return 0;
}
 
void parse(char* str, int& pos, int &ptr, char *arr, int *rel){
    switch (str[pos]){
        case '>':
            ptr++; break;
        case '<':
            ptr--; break;
        case '+':
            arr[ptr]++;
            if(arr[ptr] == 256) arr[ptr] = 0;
            break;
        case '-':
            arr[ptr]--;
            if(arr[ptr] == -1) arr[ptr] = 255;
            break;
        case '.':
            putchar(arr[ptr]);
            break;
        case ',':
            arr[ptr] = getchar();
            break;
        case '[':
            if (!arr[ptr])pos = rel[pos]; break;
        case ']':
            pos = rel[pos]-1; break;
        default:
            break;
    }
}