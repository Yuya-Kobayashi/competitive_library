/* attention to typo and overflow */
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <functional>
#define dump(x) cerr<< #x << " = " << x <<endl

using namespace std;
const int INF=1<<25;
void io(){ cin.tie(0);ios::sync_with_stdio(false);}
/*printf("%.9Lf\n",cf);*/
const int MOD=1000000007;

class UnionFind{
private:
	vector<int> data;
	int _groups;
public:
	int n;
	UnionFind(int n) : data(n, -1), _groups(n), n(n) { }

	void unite(int x, int y){
		x = root(x), y = root(y);
		if (x != y){
			--_groups;
			if (data[x] > data[y])
				swap(x, y);
			data[x] += data[y];
			data[y] = x;
		}
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	int groups() const { return _groups; }
};

const int MAXV=1000;
#define pi pair<int,pair<int,int> >
priority_queue <pi,vector <pi>,greater<pi> > pq;
vector <int> g[MAXV];

int kruskal(int n){
	if(n==1) return 0;
	UnionFind UF(n);
	int sum=0;
	while(1){
		pi e=pq.top();
		pq.pop();
		int from=e.second.first;
		int to=e.second.second;
		if(!UF.same(from,to)){
			sum+=e.first;
			UF.unite(from,to);
			g[from].push_back(to);
			g[to].push_back(from);
		}
		if(UF.groups()==1) break;
	}
	return sum;
}

/*template <int V>
class prim{
private:
	struct edge{int to,cost;};
	vector <edge> g[V];
	int mincost[V];
	bool used[V];
public:
	add_edge()
	prim():g(g){

	};
};*/

int main(){
	io();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,cost;
		cin>>a>>b>>cost;
		pq.push(make_pair(cost,make_pair(a,b)));
	}
	cerr<<kruskal(n)<<endl;
	for(int i=0;i<n;i++){
		cerr<<'#'<<i<<' ';
		for(int j=0;j<g[i].size();j++){
			cerr<<g[i][j]<<' ';
		}
		cerr<<endl;
	}

	return 0;
}