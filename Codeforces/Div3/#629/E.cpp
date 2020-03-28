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
 
int fa[N][22], dpt[N], n;
vector<int> g[N];
 
void init() {
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
}
 
int lca(int a, int b) {
    if (dpt[a] < dpt[b]) {
        swap(a, b);
    }
    for (int i = 20; i >= 0; --i) {
        while (dpt[a] - (1 << i) >= dpt[b])
            a = fa[a][i];
    }
    for (int i = 20; i >= 0; --i) {
        while (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    if (a == b)
        return a;
    return fa[a][0];
}
 
void dfs(int u = 1, int pre = 0) {
    fa[u][0] = pre;
    dpt[u] = dpt[pre] + 1;
    for (int &v : g[u]) {
        if (v == pre) continue;
        dfs(v, u);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif
 
    int q;
    cin >> n >> q;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs();
    init();
    vector<int> v;
    int k;
    while (q--) {
        cin >> k;
        v.resize(k);
        int mi = 1;
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
            if (dpt[v[i]] > dpt[mi]) mi = v[i];
        }
 
        int f = 1;
        for (int i = 0; i < k; ++i) {
            if (dpt[v[i]] - dpt[lca(mi, v[i])] > 1) {
                f = 0; break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}