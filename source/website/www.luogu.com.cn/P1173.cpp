#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int dx4[] = {-1, 1, 0, 0};
const int dy4[] = {0, 0, -1, 1};

const int HASH_MOD = 1000117;
const int MAXN = 100050;
const int MAXNODES = MAXN * 25;

char rB[1 << 21], *rS = rB, *rT = rB;
inline char gc() {
  return rS == rT && (rT = (rS = rB) + fread(rB, 1, 1 << 21, stdin), rS == rT) ? EOF : *rS++;
}
inline int rd() {
  char c = gc();
  while (c < 48 || c > 57) c = gc();
  int x = c & 15;
  for (c = gc(); c >= 48 && c <= 57; c = gc()) x = (x << 3) + (x << 1) + (c & 15);
  return x;
}

// Single hash table: val = -1 (flea), >0 (cricket node id), 0 (not stored)
struct HashTable {
  int head[HASH_MOD], nxt[MAXNODES], vx[MAXNODES], vy[MAXNODES], val[MAXNODES], sz;
  void clear() { memset(head, 0, sizeof(head)); sz = 0; }
  void ins(int x, int y, int id) {
    int pos = ((ll)(x - 1) * 1000000000 + y - 1) % HASH_MOD;
    ++sz; vx[sz] = x; vy[sz] = y; val[sz] = id;
    nxt[sz] = head[pos]; head[pos] = sz;
  }
  int ask(int x, int y) {
    int pos = ((ll)(x - 1) * 1000000000 + y - 1) % HASH_MOD;
    for (int k = head[pos]; k; k = nxt[k])
      if (vx[k] == x && vy[k] == y) return val[k];
    return 0;
  }
} h, col, vis_flea;

// Graph for cricket cells
int head_edge[MAXNODES], to_edge[MAXNODES * 8], nxt_edge[MAXNODES * 8], edge_cnt;
inline void add_edge(int u, int v) {
  to_edge[++edge_cnt] = v; nxt_edge[edge_cnt] = head_edge[u]; head_edge[u] = edge_cnt;
  to_edge[++edge_cnt] = u; nxt_edge[edge_cnt] = head_edge[v]; head_edge[v] = edge_cnt;
}

int n, m, c, flea_x[MAXN], flea_y[MAXN];
int node_cnt;
bool isok[MAXNODES], iscut[MAXNODES];
int pre[MAXNODES], low[MAXNODES], dfs_clock;

queue<pair<int,int>> qc, qf;
int tmpx[MAXNODES], tmpy[MAXNODES], tmpcnt;

void bfs_cricket(int sx, int sy, int cl) {
  qc.push({sx, sy});
  col.ins(sx, sy, cl);
  while (!qc.empty()) {
    int ux = qc.front().first, uy = qc.front().second;
    qc.pop();
    for (int d = 0; d < 4; ++d) {
      int nx = ux + dx4[d], ny = uy + dy4[d];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      int t = h.ask(nx, ny);
      if (t <= 0) continue;  // flea (-1) or not in set (0)
      if (col.ask(nx, ny)) continue;
      col.ins(nx, ny, cl);
      qc.push({nx, ny});
    }
  }
}

bool check_flea_group(int sx, int sy) {
  qf.push({sx, sy});
  vis_flea.ins(sx, sy, -1);
  tmpcnt = 0;
  while (!qf.empty()) {
    int ux = qf.front().first, uy = qf.front().second;
    qf.pop();
    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {
        if (dx == 0 && dy == 0) continue;
        int nx = ux + dx, ny = uy + dy;
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        int t = h.ask(nx, ny);
        if (vis_flea.ask(nx, ny)) continue;
        if (t == -1) {
          vis_flea.ins(nx, ny, -1);
          qf.push({nx, ny});
        } else if (t > 0) {
          tmpx[tmpcnt] = nx;
          tmpy[tmpcnt] = ny;
          ++tmpcnt;
        }
      }
    }
  }
  if (tmpcnt <= 1) return true;
  int first = col.ask(tmpx[0], tmpy[0]);
  if (first == 0) return true;
  for (int i = 1; i < tmpcnt; ++i) {
    if (col.ask(tmpx[i], tmpy[i]) != first) return false;
  }
  return true;
}

int tarjan(int u, int fa) {
  int lowu = pre[u] = ++dfs_clock, lowv, child = 0;
  for (int e = head_edge[u]; e; e = nxt_edge[e]) {
    int v = to_edge[e];
    if (v == fa) continue;
    if (!pre[v]) {
      ++child;
      lowv = tarjan(v, u);
      if (lowv >= pre[u]) iscut[u] = true;
      if (lowv < lowu) lowu = lowv;
    } else if (pre[v] < lowu) {
      lowu = pre[v];
    }
  }
  if (fa == 0 && child == 1) iscut[u] = false;
  return lowu;
}

bool check_adjacent() {
  // total empty = 2, check if they're adjacent
  int cx[2], cy[2], found = 0;
  for (int x = 1; x <= n && found < 2; ++x)
    for (int y = 1; y <= m && found < 2; ++y)
      if (h.ask(x, y) != -1) { cx[found] = x; cy[found] = y; ++found; }
  if (found < 2) return false;
  int d = (cx[0] > cx[1] ? cx[0] - cx[1] : cx[1] - cx[0])
        + (cy[0] > cy[1] ? cy[0] - cy[1] : cy[1] - cy[0]);
  return d == 1;
}

void solve() {
  n = rd(); m = rd(); c = rd();
  h.clear();

  for (int i = 0; i < c; ++i) {
    flea_x[i] = rd(); flea_y[i] = rd();
    h.ins(flea_x[i], flea_y[i], -1);
  }

  ll tot = (ll)n * m - c;
  if (tot < 2) { puts("-1"); return; }
  if (tot == 2) { puts(check_adjacent() ? "-1" : "0"); return; }

  memset(head_edge, 0, sizeof(head_edge));
  edge_cnt = node_cnt = dfs_clock = 0;
  memset(pre, 0, sizeof(pre));
  memset(iscut, 0, sizeof(iscut));
  memset(isok, 0, sizeof(isok));

  for (int i = 0; i < c; ++i) {
    int fx = flea_x[i], fy = flea_y[i];
    for (int dx = -2; dx <= 2; ++dx) {
      int nx = fx + dx;
      if (nx < 1 || nx > n) continue;
      for (int dy = -2; dy <= 2; ++dy) {
        int ny = fy + dy;
        if (ny < 1 || ny > m) continue;
        int t = h.ask(nx, ny);
        if (t == -1) continue;
        int id = t;
        if (id == 0) {
          id = ++node_cnt;
          h.ins(nx, ny, id);
          qc.push({nx, ny});
        }
        if (max(dx > 0 ? dx : -dx, dy > 0 ? dy : -dy) <= 1) isok[id] = true;
        for (int d = 0; d < 4; ++d) {
          int nnx = nx + dx4[d], nny = ny + dy4[d];
          if (nnx < 1 || nnx > n || nny < 1 || nny > m) continue;
          int nid = h.ask(nnx, nny);
          if (nid > 0) add_edge(id, nid);
        }
      }
    }
  }

  // Label cricket components
  col.clear();
  int comp_id = 0;
  queue<pair<int,int>> tmpq;
  swap(tmpq, qc);
  while (!tmpq.empty()) {
    int sx = tmpq.front().first, sy = tmpq.front().second;
    tmpq.pop();
    if (col.ask(sx, sy)) continue;
    bfs_cricket(sx, sy, ++comp_id);
  }

  // Check each 8-connected flea group
  vis_flea.clear();
  for (int i = 0; i < c; ++i) {
    if (vis_flea.ask(flea_x[i], flea_y[i])) continue;
    if (!check_flea_group(flea_x[i], flea_y[i])) { puts("0"); return; }
  }

  if (n == 1 || m == 1) { puts("1"); return; }

  // Tarjan for articulation points
  for (int i = 1; i <= node_cnt; ++i) {
    if (!pre[i]) tarjan(i, 0);
    if (isok[i] && iscut[i]) { puts("1"); return; }
  }
  puts("2");
}

int main() {
  int T = rd();
  while (T--) solve();
  return 0;
}
