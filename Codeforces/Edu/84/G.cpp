//G.cpp
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

namespace String {
    const int csize = 14;

    class ahcm {
#define nd node[u]
    public:
        struct NODE {
            int ch[csize];
            int fail, val;
        } node[N];
        int numv;
        queue<int> Q, q;

        ahcm() {
            numv = 0;
        }

        void insert(string &s, int &v) {
            int u = 0;
            for (char &c : s) {
                if (!nd.ch[c - 'a'])
                    nd.ch[c - 'a'] = ++numv;
                u = nd.ch[c - 'a'];
            }
            nd.val += v;
        }

        void build() {
            for (int &i : node[0].ch) {
                if (i)
                    Q.emplace(i);
            }
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();

                q.emplace(u);
                for (int i = 0; i < csize; ++i) {
                    if (nd.ch[i]) {
                        node[nd.ch[i]].fail = node[nd.fail].ch[i];
                        node[nd.ch[i]].val += node[node[nd.ch[i]].fail].val;
                        Q.emplace(nd.ch[i]);
                    } else
                        nd.ch[i] = node[nd.fail].ch[i];
                }
            }
        }

        pil calc(int u, string &s) {
            ll v = 0;
            for (char &c : s) {
                u = nd.ch[c - 'a'];
                v += nd.val;
            }
            return {u, v};
        }
    };
}
using namespace String;

ahcm am;
pil go[1005][18];
ll dp[1005][sz];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int n, v;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s >> v;
        am.insert(s, v);
    }
    am.build();

    cin >> s;
    int la = 0;
    vector<string> seg;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?') {
            seg.push_back(s.substr(la, i - la));
            la = i + 1;
        }
    }
    seg.push_back(s.substr(la));
//    vector<vector<pii>> go(seg.size(), vector<pii>(am.numv + 1));
    for (int i = 0; i < seg.size(); ++i) {
        for (int j = 0; j <= am.numv; ++j) {
            go[j][i] = am.calc(j, seg[i]);
        }
    }

//    vector<vector<ll>> dp(am.numv + 1, vector<ll>(sz, -INF64));
    for (int i = 0; i <= am.numv; ++i) {
        for (int j = 0; j < sz; ++j) {
            dp[i][j] = -INF64;
        }
    }
    dp[go[0][0].first][0] = go[0][0].second;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j <= am.numv; ++j) {
            if (dp[j][i] == -INF64) continue;
            for (int k = 0; k < 14; ++k) {
                if ((i >> k) & 1) continue;
                int to = am.node[j].ch[k];
                int ns = i | (1 << k);
                int count = __builtin_popcount(ns);
                if (count >= seg.size()) continue;
                int end = go[to][count].first;
                ll val = go[to][count].second + am.node[to].val;
                dp[end][ns] = max(dp[end][ns], dp[j][i] + val);
            }
        }
    }
    ll ans = -INF64;
    int cnt = seg.size() - 1;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j <= am.numv; ++j) {
            if (__builtin_popcount(i) == cnt)
                ans = max(ans, dp[j][i]);
        }
    }
    cout << ans << endl;
    return 0;
}