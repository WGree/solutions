//B.cpp
#include <bits/stdc++.h>
 
#define endl '\n'
using namespace std;
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
mt19937 mrand(random_device{}());
 
inline int rnd(int x) { return mrand() % x; }
 
const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 5e5 + 5;
const int sz = (1 << 20);
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif
 
    int q;
    cin >> q;
    while (q--) {
        int n, k, i1 = 2, i2;
        cin >> n >> k;
        while (k) {
            if (k <= (i1 - 1)) break;
            k -= i1 - 1;
            ++i1;
        }
        i2 = k;
        for (int i = n; i > 0; --i) {
            if (i == i1 || i == i2)
                cout << 'b';
            else
                cout << 'a';
        }
        cout << endl;
    }
    return 0;
}