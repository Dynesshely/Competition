#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  vector<pair<string, string>> rules;
  string a, b;
  while (cin >> a >> b) rules.push_back({a, b});

  unordered_map<string, int> fa, fb;
  queue<pair<string, bool>> q;
  q.push({A, true});
  q.push({B, false});
  fa[A] = 0;
  fb[B] = 0;

  while (!q.empty()) {
    auto [s, is_fwd] = q.front();
    q.pop();
    int step = is_fwd ? fa[s] : fb[s];
    if (step >= 10) continue;

    auto& cur_rules = rules;
    for (auto& [from, to] : cur_rules) {
      string pat = is_fwd ? from : to;
      string rep = is_fwd ? to : from;
      size_t pos = 0;
      while ((pos = s.find(pat, pos)) != string::npos) {
        string ns = s.substr(0, pos) + rep + s.substr(pos + pat.size());
        if (ns.size() > 200) {
          ++pos;
          continue;
        }
        auto& mp = is_fwd ? fa : fb;
        auto& other = is_fwd ? fb : fa;
        if (other.count(ns)) {
          cout << step + 1 + other[ns] << endl;
          return 0;
        } else if (!mp.count(ns)) {
          mp[ns] = step + 1;
          q.push({ns, is_fwd});
        }
        ++pos;
      }
    }
  }
  cout << "NO ANSWER!" << endl;
  return 0;
}
