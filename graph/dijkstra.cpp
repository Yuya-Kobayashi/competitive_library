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
#define dump(x) cerr<< #x << " = " << x <<endl

using namespace std;
const int INF=1<<25;
void io(){ cin.tie(0);ios::sync_with_stdio(false);}
/*printf("%.9Lf\n",cf);*/
const int MOD=1000000007;

#define P pair<int,int>
const int V=10000;

struct edge{int to,cost;};
vector <edge> G[V];

int d[V];

void dijkstra(int src){
	priority_queue <P,vector <P>,greater <P> > q;
	for(int i=0;i<V;i++){
		d[i]=INF;
	}
	d[src]=0;
	q.push(P(0,src));

	while(!q.empty()){
		P s=q.top();
		q.pop();
		int v=s.second;
		if(s.first>d[v]) continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}


int main(){
	io();


	return 0;
}