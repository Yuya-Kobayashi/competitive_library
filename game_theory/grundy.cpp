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

const int MAXS=1000;
int memo[MAXS];
vector <int> g[MAXS]; //状況xにおける局面の移動先をg[x]として表記する

int init(){
	for(int i=0;i<MAXS;i++){
		memo[i]=-1;
	}
	memo[0]=0;
}
int grundy(int x){
	if(memo[x]!=-1) return memo[x];
	set <int> bf;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(memo[u]==-1){
			memo[u]=grundy(u);
		}
		bf.push(memo[u]);
	}
	int cnt=0;
	if(bf.count(cnt)) cnt++;
	return memo[x]=cnt;
}

int main(){
	io();


	return 0;
}