/* attention to typo and overflow */
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
const int INF=1<<25;
void io(){ cin.tie(0);ios::sync_with_stdio(false);} //attention to use of endl
/*printf("%.9Lf\n",cf);*/
const int MOD=1000000007;

template <class T>
class minmaxRMQ{
	private:
	vector <pair<T,T> > data;
	int n;
	const T UNDEF1;
	const T UNDEF2;

	pair <T,T> minmax(pair <T,T> a , pair <T,T> b){
		return make_pair(min(a.first,b.first),max(a.second,b.second));
	}

	pair <T,T> _query(int a, int b, int k, int l, int r){
		if (r <= a || b <= l) return make_pair(UNDEF1,UNDEF2);
		if (a <= l && r <= b) return data[k];
		else{
			pair <T,T> left = _query(a, b, 2 * k + 1, l, (l + r) / 2);
			pair <T,T> right = _query(a, b, 2 * k + 2, (l + r) / 2, r);
			return minmax(left, right);
        }
    }
	public:
	minmaxRMQ(int n, T UNDEF1,T UNDEF2) : UNDEF1(UNDEF1),UNDEF2(UNDEF2){
		this->n = 1;
		while (this->n < n) this->n *= 2;
		data = vector<pair<T,T> >(this->n * 2, make_pair(UNDEF1,UNDEF2));
	}

    void update(int k, T a){
        k += n - 1;
        data[k] = make_pair(a,a);
        while (k > 0){
            k = (k - 1) / 2;
            data[k] = minmax(data[2 * k + 1], data[2 * k + 2]);
        }
    }

    // [a, b)
    pair <T,T> query(int a, int b) { return _query(a, b, 0, 0, n); }

    /*void update_max(int k, T a){
        if (a > query(k, k + 1)) update(k, a);
    }*/
};

int main(){
	io();


	return 0;
}