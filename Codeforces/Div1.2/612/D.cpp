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

const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const ull mod2 = 998244353;//1610612741;
const int N = 1e3 + 5;
const int sz = (1 << 14);

int c[2005], cnt[2005];
vector<int> g[2005];

void dfs(int u, vector<pii> &tmp) {
    for (int v : g[u]) {
        dfs(v, tmp);
        cnt[u] += cnt[v];
    }
    if (c[u] > cnt[u]) {
        cout << "NO" << endl;
        exit(0);
    }
    cnt[u]++;
    pii t = {c[u], 0};
    auto p = lower_bound(tmp.begin(), tmp.end(), t);
    for (auto q = p; q < tmp.end(); ++q) ++q->first;
    tmp.insert(p, {c[u], u});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int n, rt;
    cin >> n;
    for (int i = 1, p, t; i <= n; ++i) {
        cin >> p >> t;
        if (p == 0) rt = i;
        else g[p].emplace_back(i);
        c[i] = t;
    }

    vector<pii> v;
    dfs(rt, v);

    cout << "YES" << endl;
    for (pii &i : v) c[i.second] = i.first + 1;
    for (int i = 1; i <= n; ++i) cout << c[i] << ' ';
    cout << endl;
}