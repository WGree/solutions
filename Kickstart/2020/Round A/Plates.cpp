//Plates.cpp
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

int a[55][35];

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
        int n, k, p;
        cin >> n >> k >> p;

        vector<vector<int>> dp(n + 1, vector<int> (n * k + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                cin >> a[i][j];
                a[i][j] += a[i][j - 1];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int l = j; l <= p; ++l) {
                    dp[i][l] = max(dp[i][l], dp[i - 1][l - j] + a[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[i][p]);
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
