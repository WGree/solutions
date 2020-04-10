//Bundling.cpp
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
const int N = 1e6 + 5;
const int sz = (1 << 20);

namespace String {
    const int csize = 26;

    int ans, k;

    class trie {
        int ch[N][csize];
        int cnt[N];
        int numv;

    public:
        void init() {
            while (numv) {
                memset(ch[numv], 0, sizeof(ch[numv]));
                cnt[numv] = 0;
                --numv;
            }
            memset(ch[numv], 0, sizeof(ch[numv]));
            cnt[numv] = 0;
        }

        void insert(string &s) {
            int u = 0;
            for (char &c : s) {
                if (!ch[u][c - 'A'])
                    ch[u][c - 'A'] = ++numv;
                u = ch[u][c - 'A'];
                ++cnt[u];
            }
        }

        int count() {
            int ret = 0;
            for (int i = 1; i <= numv; ++i) {
                ret += cnt[i] / k;
            }
            return ret;
        }
    };
}
using namespace String;

trie tree;

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
        int n;
        string s;
        cin >> n >> k;
        tree.init();
        for (int i = 0; i < n; ++i) {
            cin >> s;
            tree.insert(s);
        }

        printf("Case #%d: %d\n", T, tree.count());
    }
    return 0;
}
