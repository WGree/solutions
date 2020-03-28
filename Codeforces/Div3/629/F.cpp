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
const int N = 2e5 + 5;
const int sz = (1 << 20);
 
ll a[N];
ll pre[N], suf[N];
map<int, int> mp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif
 
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
        if (mp[a[i]] == k) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = INF64, lcnt = 0, rcnt = n;
    sort(a, a + n + 1);
    n = unique(a, a + n + 1) - a;
 
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + mp[a[i - 1]] * a[i - 1];
    }
    for (int i = n - 2; i > 0; --i) {
        suf[i] = suf[i + 1] + mp[a[i + 1]] * a[i + 1];
    }
    for (int i = 1; i < n; ++i) {
        ll t = k - mp[a[i]];
        rcnt -= mp[a[i]];
        ll t1 = lcnt * a[i] - pre[i];
        ll t2 = suf[i] - rcnt * a[i];
        if (lcnt >= t) ans = min(ans, t1 - (lcnt - t));
        if (rcnt >= t) ans = min(ans, t2 - (rcnt - t));
        ans = min(ans, t1 + t2 - (lcnt + rcnt - t));
        lcnt += mp[a[i]];
    }
    cout << ans << endl;
    return 0;
}