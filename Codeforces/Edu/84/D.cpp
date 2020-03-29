//D.cpp
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

int p[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> p[i];
        for (int i = 1; i <= n; ++i)
            cin >> c[i];

        int ans = INF32;
        vector<int> tmp;
        for (int i = 1; i <= n; ++i) {
            if (c[i]) {
                tmp.clear();
                int j = i;
                while (c[j]) {
                    tmp.emplace_back(c[j]);
                    c[j] = 0;
                    j = p[j];
                }
                int m = tmp.size();
                for (int k = 1; k * k <= m; ++k) {
                    if (m % k) continue;
                    for (int strt = 0; strt < k; ++strt) {
                        bool ok = true;
                        j = strt;
                        while (j < m) {
                            if (tmp[j] != tmp[(j + k) % m]) {
                                ok = false;
                                break;
                            }
                            j += k;
                        }
                        if (ok) {
                            ans = min(ans, k);
                        }
                    }
                    for (int strt = 0; strt < m / k; ++strt) {
                        bool ok = true;
                        j = strt;
                        while (j < m) {
                            if (tmp[j] != tmp[(j + m / k) % m]) {
                                ok = false;
                                break;
                            }
                            j += m / k;
                        }
                        if (ok) {
                            ans = min(ans, m / k);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}