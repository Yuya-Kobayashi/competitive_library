#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge{int to,cap,rev;};

#define V 1000
#define MAXN 2000000000

vector <edge> G[V];
bool used[V];

void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

int dfs(int v,int t,int f){
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e =G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int maxflow(int s,int t){
	int flow=0;
	for(;;){
		for(int i=0;i<V;i++){
			used[i]=0;
		}
		int f=dfs(s,t,MAXN);
		if(f==0) return flow;
		flow+=f;
	}
}

int main(){


	return 0;
}