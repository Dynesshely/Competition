#include <cstdio>
#include <algorithm>
using namespace std;

int order[405];      // scheduling order (m*n operations)
int mach[25][25];    // mach[i][step] = machine for workpiece i's step
int tme[25][25];     // tme[i][step] = time for workpiece i's step
int step_cnt[25];    // how many steps done for each workpiece
int last_end[25];    // when last operation of workpiece ended
int mac_avail[25][10000]; // machine schedule (sparse timeline, track occupied slots)

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m * n; ++i) scanf("%d", &order[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &mach[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &tme[i][j]);

    for (int idx = 0; idx < m * n; ++idx) {
        int wp = order[idx];
        ++step_cnt[wp];
        int step = step_cnt[wp];
        int mc = mach[wp][step];
        int dur = tme[wp][step];

        // Find earliest start time on machine mc
        // After previous operation ends AND machine has a gap of duration 'dur'
        int start = last_end[wp];
        while (true) {
            bool ok = true;
            for (int t = start; t < start + dur; ++t)
                if (mac_avail[mc][t]) { ok = false; break; }
            if (ok) break;
            ++start;
        }
        // Mark the time slot
        for (int t = start; t < start + dur; ++t)
            mac_avail[mc][t] = 1;
        last_end[wp] = start + dur;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (last_end[i] > ans) ans = last_end[i];
    printf("%d\n", ans);
    return 0;
}
