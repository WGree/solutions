//C.cpp
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
    string s, a, b;
    while (q--) {
        int n;
        cin >> n >> s;
        a.resize(n);
        b.resize(n);
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '2') {
                if (!f)
                    a[i] = b[i] = '1';
                else
                    a[i] = '2', b[i] = '0';
            } else if (s[i] == '0')
                a[i] = b[i] = '0';
            else if (!f) {
                b[i] = '1', a[i] = '0';
                f = 1;
            } else
                a[i] = '1', b[i] = '0';
        }
        cout << a << endl << b << endl;
    }
    return 0;
}