#include <cstdio>
#include <cstring>
#include <cctype>

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

char s[100];
int pos, len, MOD, a_val;
bool parse_err;

int mod_pow(int a, int b) {
    long long r = 1, base = a;
    while (b) {
        if (b & 1) r = r * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return (int)r;
}

void skip() {
    while (pos < len && s[pos] == ' ') ++pos;
}

int expr();
int term();
int factor();
int primary();

int expr() {
    int val = term();
    if (parse_err) return 0;
    while (pos < len) {
        skip();
        if (pos >= len) break;
        if (s[pos] == '+') { ++pos; int r = term(); val = (val + r) % MOD; }
        else if (s[pos] == '-') { ++pos; int r = term(); val = (val - r + MOD) % MOD; }
        else break;
    }
    return val;
}

int term() {
    int val = factor();
    if (parse_err) return 0;
    while (pos < len) {
        skip();
        if (pos >= len) break;
        if (s[pos] == '*') { ++pos; int r = factor(); val = (long long)val * r % MOD; }
        else break;
    }
    return val;
}

int factor() {
    int val = primary();
    if (parse_err) return 0;
    while (pos < len) {
        skip();
        if (pos >= len) break;
        if (s[pos] == '^') { ++pos; int r = primary(); val = mod_pow(val, r); }
        else break;
    }
    return val;
}

int primary() {
    skip();
    if (pos >= len) { parse_err = true; return 0; }
    if (s[pos] == '(') {
        ++pos;
        int val = expr();
        skip();
        if (pos >= len || s[pos] != ')') { parse_err = true; return 0; }
        ++pos;
        return val;
    }
    if (s[pos] == 'a') { ++pos; return a_val; }
    if (s[pos] == '+') { ++pos; return primary(); }
    if (s[pos] == '-') { ++pos; return (MOD - primary()) % MOD; }
    if (isdigit(s[pos])) {
        int val = 0;
        while (pos < len && isdigit(s[pos])) {
            val = val * 10 + (s[pos] - '0');
            ++pos;
        }
        return val % MOD;
    }
    parse_err = true;
    return 0;
}

// Returns true if evaluation succeeds
bool eval(const char* expr_str, int a, int mod, int& result) {
    strcpy(s, expr_str);
    pos = 0; len = strlen(s);
    MOD = mod;
    a_val = a % MOD;
    parse_err = false;
    result = expr();
    skip();
    if (pos != len) parse_err = true;
    return !parse_err;
}

int main() {
    char ref[100];
    fgets(ref, sizeof(ref), stdin);
    int rlen = strlen(ref);
    while (rlen > 0 && (ref[rlen-1] == '\n' || ref[rlen-1] == '\r')) ref[--rlen] = '\0';

    char tmp[20];
    fgets(tmp, sizeof(tmp), stdin);
    int n = 0;
    for (int i = 0; tmp[i] >= '0' && tmp[i] <= '9'; ++i)
        n = n * 10 + (tmp[i] - '0');

    // Evaluate reference at multiple points with multiple mods
    int ref_vals[10];
    int a_vals[] = {1, 2, 3, 5, 7};
    int mods[] = {MOD1, MOD2};
    int na = 5, nm = 2;
    int vidx = 0;
    for (int mi = 0; mi < nm; ++mi)
        for (int ai = 0; ai < na; ++ai)
            eval(ref, a_vals[ai], mods[mi], ref_vals[vidx++]);

    for (int i = 0; i < n; ++i) {
        char opt[100];
        fgets(opt, sizeof(opt), stdin);
        int olen = strlen(opt);
        while (olen > 0 && (opt[olen-1] == '\n' || opt[olen-1] == '\r')) opt[--olen] = '\0';

        bool match = true;
        vidx = 0;
        for (int mi = 0; mi < nm && match; ++mi) {
            for (int ai = 0; ai < na && match; ++ai) {
                int val;
                if (!eval(opt, a_vals[ai], mods[mi], val)) { match = false; break; }
                if (val != ref_vals[vidx]) { match = false; break; }
                ++vidx;
            }
        }
        if (match) putchar('A' + i);
    }
    putchar('\n');
    return 0;
}
