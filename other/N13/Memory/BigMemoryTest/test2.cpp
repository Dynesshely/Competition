#include "stdc++.h"
#include <windows.h>
using namespace std;

const long long G_1 = 268435456;
inline long long SizeG(long long n) { return G_1 * n; }

int main() {
    srand(time(0));
    srand(rand() % G_1);
    long long tar = SizeG(3);
    int* arr = new int[tar];
    if (arr) {
        printf("Memory Allocated at: %x\n", arr);
        printf("Sizeof arr: %lld\n", sizeof(arr));
        freopen("test2.out", "w", stdout);
        memset(arr, rand() % 100, tar);
        int printed = 0;
        for (long long i = 1; i < tar; i += 1024) {
            int tmp = rand() % (rand() % G_1 + 1);
            arr[i] = tmp;
            arr[i - 1] = arr[i] - (rand() % 10);
            printf("%lld\t", i);
            if (printed == 9) printf("\n"), printed = 0;
            else ++printed;
        }
        freopen("CON", "w", stdout);
        int num = 0; printf("Input rand index num: ");
        scanf("%d", &num);
        for (int i = 1; i <= num; ++i) {
            int index = rand() % (rand() % G_1);
            printf("%d:\t%d\n", index, arr[index]);
        }
        system("pause");
    }
    else printf("Not Enough Memory!\n");
    delete[] arr;
    return 0;
}