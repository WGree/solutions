//E.cpp
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
const int N = 2e5 + 5;
const int sz = (1 << 20);

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
    freopen("../0out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    a[n] = 10;
    a[n - 1] = 180;
    if (n > 1)
        a[n - 2] = 2610;
    for (int i = n - 3; i > 0; --i) {
        a[i] = (20 * a[i + 1] - 100 * a[i + 2] % mod + mod) % mod;
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}