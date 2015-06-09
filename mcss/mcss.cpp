//mcss means maximum/minimum contiguous subsequence sum
//msp means maximum/minimum subarray problem
//reference from http://www.cs.cmu.edu/afs/cs/academic/class/15210-s12/www/lectures/lecture03.pdf

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

template <class T>
class mcss {
private:
	vector <T> data;
	int n;
	inline T binary_operation(T first, T second) {return max(first, second);};
	tuple <T, T, T, T> divide_conquire(T l, T r) { //return tuple = (mcss, m_prefix, m_suffix, total) [l, r)
		if (r == l + 1) {
			T ret = binary_operation(data[l], 0);
			return tuple <T, T, T, T>(ret, ret, ret, data[l]);
		}
		T mid = (l + r) / 2;
		tuple <T, T, T, T> left = divide_conquire(l, mid);
		tuple <T, T, T, T> right = divide_conquire(mid, r);
		T lmcss = get <0>(left);
		T rmcss = get <0>(right);
		T bestAcross = get <2>(left) + get <1>(right);

		//cerr << "(l,r)=(" << l << ',' << r << ')' << ' ' << "(lmcss,rmcss,bestAcross)=(" << lmcss << ',' << rmcss << ',' << bestAcross << ')' << endl;


		T mcss = binary_operation(bestAcross, binary_operation(lmcss, rmcss));
		T m_prefix = binary_operation(get <3>(left) + get <1>(right) , get <1>(left));
		T m_suffix = binary_operation(get <2>(left) + get <3>(right) , get <2>(right));
		T total = get <3>(left) + get <3>(right);

		//cerr << m_prefix << ' ' << m_suffix << endl;
		return tuple <T, T, T, T>(mcss, m_prefix, m_suffix, total);
	}
public:
	mcss(vector <T> data): data(data), n((int)data.size()) {}

	void change(int pos, T val) {data[pos] = val;};

	T divide_conquire() {return get <0>(divide_conquire(0, n));}; //O(n)

	T sweep() { //O(n) this is a simple case of dp
		T sum = 0; T summ = 0;
		for (int i = 0; i < n; i++) {
			sum = sum + data[i];
			sum = binary_operation(sum, 0); //in case of max if(sum<0) sum=0
			summ = binary_operation(sum, summ); //in case of max if(summax>sum) summax=sum
		}
		return summ;
	}
	void write(){
		for(auto it:data){
			cerr<<it<<' ';
		}
		cerr<<endl;
	}
};

int main() {
	vector <int> data = {3,4,5};
	mcss <int> mcs(data);
	cout << mcs.divide_conquire() << endl;
	cout << mcs.sweep() << endl;

	return 0;
}