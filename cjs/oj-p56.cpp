#include <bits/stdc++.h>
#define MAXN 0x7fffffff
using namespace std;
map<pair<int, int>, int> _map;
int n, m, a, b, c, dijkstra(int s);
vector<int> sons;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++ i){
		scanf("%d %d %d", &a, &b, &c);
		sons[a].push_back(b); sons[b].push_back(a);
		_map.emplace(make_pair(a, b), c);
		_map.emplace(make_pair(b, a), c);
	}
	cout << dijkstra(1) << endl;
//	if(!_map.empty()){
//	    for(auto i = _map.begin(); i != _map.end(); ++ i){
//	        cout << i->first.first << " " << i->first.second << " " << i->second << endl;
//	    }
//	}
	return 0;
}
int dijkstra(int s){
	int shorter = -MAXN, nw[n] = {MAXN};
	bool via[n] = {false};
	nw[s] = 0; via[s] = true;
	for(int i = 0; i < vector[s].size(); ++ i){
		
	}
	return 0x7fffffff;
}