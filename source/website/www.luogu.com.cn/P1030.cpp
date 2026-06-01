#include <iostream>
#include <string>
using namespace std;

void build(string in, string post) {
  if (in.empty()) return;
  char root = post.back();
  cout << root;
  int k = in.find(root);
  build(in.substr(0, k), post.substr(0, k));
  build(in.substr(k + 1), post.substr(k, post.size() - k - 1));
}

int main() {
  string in, post;
  cin >> in >> post;
  build(in, post);
  cout << endl;
  return 0;
}
