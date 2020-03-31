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
 
const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 1e3 + 5;
const int sz = (1 << 14);
 
int dp[105][55][55][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif
 
    int n;
    cin >> n;
    int odd = (n + 1) / 2, eve = n / 2;
    int a[105] = {};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) {
            if (a[i] & 1)
                --odd;
            else
                --eve;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][odd][eve][0] = dp[0][odd][eve][1] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i + 1]) {
            int tt = a[i + 1] & 1;
            for (int j = 0; j < 52; ++j) {
                for (int k = 0; k < 52; ++k) {
                    if (dp[i][j][k][0] != INF32) {
                        if (tt) dp[i + 1][j][k][1] = min(dp[i][j][k][1], dp[i][j][k][0] + 1);
                        else dp[i + 1][j][k][0] = min(dp[i][j][k][0], dp[i][j][k][0]);
                    }
                    if (dp[i][j][k][1] != INF32) {
                        if (tt) dp[i + 1][j][k][1] = min(dp[i + 1][j][k][1], dp[i][j][k][1]);
                        else dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][1] + 1);
                    }
                }
            }
        } else {
            for (int j = 0; j < 52; ++j) {
                for (int k = 0; k < 52; ++k) {
                    if (dp[i][j][k][0] != INF32) {
                        if (k) dp[i + 1][j][k - 1][0] = min(dp[i + 1][j][k - 1][0], dp[i][j][k][0]);
                        if (j) dp[i + 1][j - 1][k][1] = min(dp[i + 1][j - 1][k][1], dp[i][j][k][0] + 1);
                    }
                    if (dp[i][j][k][1] != INF32) {
                        if (k) dp[i + 1][j][k - 1][0] = min(dp[i + 1][j][k - 1][0], dp[i][j][k][1] + 1);
                        if (j) dp[i + 1][j - 1][k][1] = min(dp[i + 1][j - 1][k][1], dp[i][j][k][1]);
                    }
                }
            }
        }
    }
    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << endl;
}