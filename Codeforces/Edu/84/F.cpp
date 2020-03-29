//F.cpp
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

int n, m;
vector<int> l, r, x;

ll calc(int p) {
    vector<int> has(n + 2), las(n + 2);
    vector<ll> dp(n + 2);
    p = 1 << p;
    for (int i = 0; i < m; ++i) {
        if (x[i] & p) {
            ++has[l[i]];
            --has[r[i] + 1];
        } else
            las[r[i]] = max(las[r[i]], l[i]);
    }
    for (int i = 1; i <= n; ++i) {
        has[i] += has[i - 1];
    }

    int last = 0;
    ll sum = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!has[i]) {
            dp[i] = sum;
            sum = sum * 2 % mod;
        }
        ll tmp = 0;
        while (last < las[i]) {
            tmp = (tmp + dp[last++]) % mod;
        }
        sum = (sum - tmp + mod) % mod;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int k;
    cin >> n >> k >> m;
    l.resize(m);
    r = x = l;
    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i] >> x[i];

    ll ans = 1;
    for (int i = 0; i < k; ++i) {
        ans = ans * calc(i) % mod;
    }
    cout << ans << endl;
    return 0;
}