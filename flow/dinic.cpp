/* attention to overflow */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>
#include <iomanip>

#define dump(x) cerr<< #x << " = " << x <<endl

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;

template <int V>
class Dinic{
private:
	using T=double;
	const T INF=1<<28;
	const T EPS=1e-7;
	struct edge{int to,rev;T cap;};
	vector <edge> G[V];
	int level[V];
	int iter[V];

	void bfs(int s){
		fill_n(level,V,-1);
		queue <int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();que.pop();
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap<=EPS) continue;
				if(level[e.to] <0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
		return;
	}

	T dfs(int v,int t,T f){
		if(v==t) return f;
		for(int &i=iter[v];i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap<=EPS) continue;
			if(level[v]<level[e.to]){
				T d=dfs(e.to,t,min(f,e.cap));
				if(d<=EPS) continue;
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	}

public:
	void add_edge(int from,int to,T cap){
		G[from].push_back(edge{to,(int)G[to].size(),cap});
		G[to].push_back(edge{from,(int)G[from].size()-1,0});
	}

	T max_flow(int s,int t){
		T flow=0;
		while(true){
			bfs(s);
			if(level[t]<0) return flow;
			fill_n(iter,V,0);
			T f;
			while((f=dfs(s,t,INF))>0){
				flow+=f;
			}
		}
		return 0;
	}

};


int main() {
	io();


	return 0;
}