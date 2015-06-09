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

namespace Expectation{
	class nCk{
		private:
			vector <vector <long long> > nck;
			int size;
			int modulo;
		public:
			nCk(int n,int modulo=-1):nck(vector <vector <long long>>(n+1,vector <long long>(n+1,0))),size(n+1),modulo(modulo){};
			void init(){
				nck[0][0]=1;
				for(int i=0;i<size-1;i++){
					for(int j=0;j<=i;j++){
						if(modulo!=-1){
							nck[i+1][j]=(nck[i+1][j]+nck[i][j])%modulo;
							nck[i+1][j+1]=(nck[i+1][j+1]+nck[i][j])%modulo;
						}else{
							nck[i+1][j]+=nck[i][j];
							nck[i+1][j+1]+=nck[i][j];
						}
					}
				}
			}
			long long get(int l,int r){
				return nck[l][r];
			}
	};

	class fact_nck{
	private:
		vector <long double> log_fact;
		int size;
	public:
		fact_nck(int n):log_fact(vector <long double>(n,0.0)),size(n+1){
			for(int i=2;i<size;i++){
				log_fact[i]=log_fact[i-1]+log(i);
			}
		};

		long double get(int l,int r){
			if(l<r) cerr<<"l<r"<<endl,exit(1);
			return exp(log_fact[l]-log_fact[l-r]-log_fact[r]);
		}
	};

	vector <double>  E_multiply(const vector <double> &b){ //掛け算の期待値:O(n)
		int n=b.size();
		vector <double> ret(n);
		for(int i=0;i<n;i++){
			for (int j = n-1; j >= 0; j--) {
				ret[j + 1] += ret[j] * b[i];
			}
		}

		nCk nck(n);
		nck.init();
		for(int i=0;i<n;i++){
			//ret[i] /= nck[n][i];
			ret[i]/=nck.get(n,i);
		}
		return ret;
	}
}


int main() {
	io();
	return 0;
}
