#include <iostream>
#include <vector>

using namespace std;

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

int main(){

	return 0;
}