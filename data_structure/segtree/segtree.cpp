#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*template <class T>
struct pr{
	T a,b;
	friend pr operator+(pr c,pr d){ return pr<T>(c.a+d.a,c.b-d.b);}
	friend ostream &operator<<(ostream &os,pr <T> t){os<<t.a<<' '<<t.b;return os;}
	pr(T a,T b):a(a),b(b){};
};*/

template <class T>
class segtree{
	private:
	vector<T> data;
	int n;
	const T UNDEF;
	T binary_operation(T a,T b){
		return a+b;
	}

	T _query(int a, int b, int k, int l, int r){
		if (r <= a || b <= l) return UNDEF;
		if (a <= l && r <= b) return data[k];
		else{
			T left = _query(a, b, 2 * k + 1, l, (l + r) / 2);
			T right = _query(a, b, 2 * k + 2, (l + r) / 2, r);
			return binary_operation(left,right);
        }
    }
	public:
	segtree(int n, T UNDEF) : UNDEF(UNDEF){
		this->n = 1;
		while (this->n < n) this->n *= 2;
		data = vector<T>(this->n * 2, UNDEF);
	}

	segtree(vector <T> data,T UNDEF):data(data),n(data.size()),UNDEF(UNDEF){}

    void update(int k, T a){
        k += n - 1;
        data[k] = a;
        while (k > 0){
            k = (k - 1) / 2;
            data[k] = binary_operation(data[2 * k + 1],data[2 * k + 2]);
        }
    }

    // [a, b)
    T query(int a, int b) { return _query(a, b, 0, 0, n); }

    void update_max(int k, T a){
        if (a > query(k, k + 1)) update(k, a);
    }
};


int main(){
	segtree <int> rq(100,0);
	rq.update(0,1);
	rq.update(1,2);
	rq.update(2,4);
	rq.update(3,5);

	cerr<<rq.query(0,4)<<endl;

	/*pr<int> a(0,0);
	cout<<a<<endl;
	segtree < pr<int> > rpqq(100,pr<int>(0,0));
	rq.update(0,pr<int>(1,1));
	rq.update(1,pr<int>(2,1));
	rq.update(2,pr<int>(4,1));
	rq.update(3,pr<int>(5,1));

	cerr<<rq.query(0,4)<<endl;*/

	return 0;
}