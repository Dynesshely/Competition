#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int max_bonus = -1, total = 0;
    char max_name[25] = {0};
    for (int i = 0; i < n; ++i) {
        char name[25], cadre, western;
        int avg, class_score, papers;
        scanf("%s %d %d %c %c %d", name, &avg, &class_score, &cadre, &western, &papers);
        int bonus = 0;
        if (avg > 80 && papers >= 1) bonus += 8000;
        if (avg > 85 && class_score > 80) bonus += 4000;
        if (avg > 90) bonus += 2000;
        if (avg > 85 && western == 'Y') bonus += 1000;
        if (class_score > 80 && cadre == 'Y') bonus += 850;
        total += bonus;
        if (bonus > max_bonus) {
            max_bonus = bonus;
            int j = 0;
            while (name[j]) { max_name[j] = name[j]; ++j; }
            max_name[j] = '\0';
        }
    }
    printf("%s\n%d\n%d\n", max_name, max_bonus, total);
    return 0;
}
