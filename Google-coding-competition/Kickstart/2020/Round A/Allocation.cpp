//Allocation.cpp
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 1e5 + 5;
const int sz = (1 << 20);

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        int n, b;
        cin >> n >> b;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n, less<>());
        int ans = 0;
        for (int i = 0; i < n && b >= a[i]; ++i) {
            ++ans;
            b -= a[i];
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
