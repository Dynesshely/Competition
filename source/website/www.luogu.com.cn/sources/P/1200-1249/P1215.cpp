#include <bits/stdc++.h>
using namespace std;

int  capA, capB, capC;
bool via[21][21][21];

void input() { scanf("%d%d%d", &capA, &capB, &capC); }

void process() {
    queue<tuple<int, int, int>> q;
    via[0][0][capC] = true;
    q.push({0, 0, capC});
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        int pour;
        // A -> B
        pour = min(a, capB - b);
        if (pour > 0 && !via[a - pour][b + pour][c]) {
            via[a - pour][b + pour][c] = true;
            q.push({a - pour, b + pour, c});
        }
        // A -> C
        pour = min(a, capC - c);
        if (pour > 0 && !via[a - pour][b][c + pour]) {
            via[a - pour][b][c + pour] = true;
            q.push({a - pour, b, c + pour});
        }
        // B -> A
        pour = min(b, capA - a);
        if (pour > 0 && !via[a + pour][b - pour][c]) {
            via[a + pour][b - pour][c] = true;
            q.push({a + pour, b - pour, c});
        }
        // B -> C
        pour = min(b, capC - c);
        if (pour > 0 && !via[a][b - pour][c + pour]) {
            via[a][b - pour][c + pour] = true;
            q.push({a, b - pour, c + pour});
        }
        // C -> A
        pour = min(c, capA - a);
        if (pour > 0 && !via[a + pour][b][c - pour]) {
            via[a + pour][b][c - pour] = true;
            q.push({a + pour, b, c - pour});
        }
        // C -> B
        pour = min(c, capB - b);
        if (pour > 0 && !via[a][b + pour][c - pour]) {
            via[a][b + pour][c - pour] = true;
            q.push({a, b + pour, c - pour});
        }
    }
}

void output() {
    vector<int> ans;
    for (int b = 0; b <= capB; b++)
        for (int c = 0; c <= capC; c++)
            if (via[0][b][c])
                ans.push_back(c);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d%c", ans[i], i + 1 == (int)ans.size() ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
