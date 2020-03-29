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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 1e5 + 5;
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
        int n, la = -1;
        cin >> n;
        vector<int> b(n + 1);
        for (int i = 0; i < n; ++i) {
            int k, t, f = 0;
            cin >> k;
            while (k--) {
                cin >> t;
                if (!f && !b[t])
                    b[t] = f = 1;
            }
            if (!f)
                la = i + 1;
        }
        if (la == -1) {
            cout << "OPTIMAL" << endl;
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            if (!b[i]) {
                cout << "IMPROVE" << endl
                     << la << ' ' << i << endl;
                break;
            }
        }
    }
    return 0;
}
