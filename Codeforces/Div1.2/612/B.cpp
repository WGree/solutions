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

const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 1e3 + 5;
const int sz = (1 << 14);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ++mp[s[i]];
    }

    auto calc = [k](string &a, string &b) {
        string tmp = a;
        for (int i = 0; i < k; ++i) {
            if (a[i] == b[i])
                tmp[i] = a[i];
            else
                tmp[i] = ('S' + 'E' + 'T' - a[i] - b[i]);
        }

        return tmp;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string ss = calc(s[i], s[j]);
            ans += mp[ss];
            if (s[i] == s[j])
                ans -= 2;
        }
    }

    cout << ans / 3 << endl;
}