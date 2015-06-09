#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int V,K;
const int MAX_V=4000;
vector <int> G[MAX_V],rG[MAX_V],vs;
bool used[MAX_V];
int cmp[MAX_V];
vector <int> UG[MAX_V];

void add_edge(int from, int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v){
	used[v] = true;
	for(int i = 0; i < G[v].size(); ++i){
		if( !used[ G[v][i] ] )  dfs( G[v][i] );
	}
	vs.push_back(v);
}

void rdfs(int v, int k){
	used[v] = true;
	cmp[v] = k;

	for(int i = 0; i < rG[v].size(); ++i){
		if( !used[ rG[v][i] ] ) rdfs( rG[v][i], k );
	}
}

int scc(){
	vs.clear();

	memset(used, 0, sizeof(used));
	for(int v = 0; v < V; ++v){
		if( !used[v] ) dfs(v);
	}

	memset(used, 0, sizeof(used));
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; --i){
		if( !used[ vs[i] ] ) rdfs(vs[i], k++);
	}
	return k;
}

void scc_contract(){
	K=scc();
	for(int i=0;i<V;i++){
		for(int j=0;j<G[i].size();j++){
			int u=G[i][j];
			if(cmp[i]==cmp[u]) continue;
			UG[cmp[i]].push_back(cmp[u]);
		}
	}

	for(int i=0;i<K;i++){
		UG[i].erase(unique(UG[i].begin(),UG[i].end()),UG[i].end());
	}
}

int main(){

	return 0;
}