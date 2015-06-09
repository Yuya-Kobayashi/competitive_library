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
const double EPS = 1e-8;

class TrieTree { //now, this tree is specialized in string of numbers
private:
    using T = long long;
    struct node {
        T value, mx;
        const static int chsize = 10;
        node* child[chsize];
        node(): value(0), mx(0) {
            fill_n(child, chsize, nullptr);
        };
        template <class Iter>
        void update(T val, Iter now, Iter end) {
            if (now == end) {
                value += val;
                mx += val;
                return;
            }
            auto &next = child[*now - '0'];
            if (next == nullptr) next = new node();
            next->update(val, ++now, end);
            mx = max(mx, next->mx + value);
        }
    };
    node* root;
public:
    TrieTree(): root(new node()) {}
    void update(string s, int val) {
        return root->update(val, s.rbegin(), s.rend());
    }
    T get() {return root->mx;};
};


int main() {
    io();
    int t;
    cin >> t;
    TrieTree tt;
    for (int i = 0; i < t; i++) {
        string s;
        int b;
        cin >> s >> b;
        cerr << s << ' ' << b << endl;
        tt.update(s, b);
        cout << tt.get() << endl;
    }

    return 0;
}
