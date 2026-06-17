#include <bits/stdc++.h>
using namespace std;
int main() {
    char buf[512];
    fgets(buf, sizeof(buf), stdin);
    int M, N, P;
    sscanf(buf, "%d%d%d", &M, &N, &P);
    char name[21][260];
    map<string, int> id;
    for (int i = 1; i <= M; ++i) {
        fgets(buf, sizeof(buf), stdin);
        int len = strlen(buf);
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
            buf[--len] = '\0';
        strcpy(name[i], buf);
        id[name[i]] = i;
    }
    vector<vector<string>> stmts(M + 1);
    for (int i = 0; i < P; ++i) {
        fgets(buf, sizeof(buf), stdin);
        int len = strlen(buf);
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
            buf[--len] = '\0';
        string line(buf);
        size_t colon = line.find(':');
        if (colon == string::npos) continue;
        string speaker = line.substr(0, colon);
        if (!id.count(speaker)) continue;
        string text = line.substr(colon + 2);
        stmts[id[speaker]].push_back(text);
    }
    const vector<string> days = {
        "Monday","Tuesday","Wednesday","Thursday",
        "Friday","Saturday","Sunday"};
    int found = 0;
    for (int crim = 1; crim <= M; ++crim) {
        for (int day = 0; day < 7; ++day) {
            int forced_liar = 0, forced_truth = 0;
            bool invalid = false;
            for (int p = 1; p <= M && !invalid; ++p) {
                bool all_true = true, all_false = true;
                bool has_stmt = false;
                for (const string &s : stmts[p]) {
                    bool is_true = false;
                    bool recognized = true;
                    if (s == "I am guilty.")
                        is_true = (p == crim);
                    else if (s == "I am not guilty.")
                        is_true = (p != crim);
                    else if (s.find("Today is ") == 0) {
                        string d = s.substr(9);
                        if (!d.empty() && d.back() == '.')
                            d.pop_back();
                        int td = -1;
                        for (int j = 0; j < 7; ++j)
                            if (d == days[j]) { td = j; break; }
                        if (td == -1) recognized = false;
                        else is_true = (td == day);
                    } else if (s.find(" is guilty.") != string::npos) {
                        size_t pos = s.find(" is guilty.");
                        string nm = s.substr(0, pos);
                        recognized = id.count(nm);
                        if (recognized) is_true = (id[nm] == crim);
                    } else if (s.find(" is not guilty.") != string::npos) {
                        size_t pos = s.find(" is not guilty.");
                        string nm = s.substr(0, pos);
                        recognized = id.count(nm);
                        if (recognized) is_true = (id[nm] != crim);
                    } else {
                        recognized = false;
                    }
                    if (!recognized) continue;
                    has_stmt = true;
                    if (!is_true) all_true = false;
                    if (is_true) all_false = false;
                }
                if (!has_stmt) continue;
                if (!all_true && !all_false) { invalid = true; break; }
                if (all_false) forced_liar++;
                if (all_true) forced_truth++;
            }
            if (!invalid && forced_liar <= N && forced_truth <= M - N) {
                if (found == 0 || found == crim)
                    found = crim;
                else {
                    printf("Cannot Determine\n");
                    return 0;
                }
            }
        }
    }
    if (found == 0) printf("Impossible\n");
    else printf("%s\n", name[found]);
    return 0;
}
