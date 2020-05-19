//Candies.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;

int num[N];

namespace data_structure {
    template<typename val_t>
    class segment_tree {
#define nd node[now]
#define ndl node[now << 1]
#define ndr node[now << 1 | 1]
#define mid ((nd.l + nd.r) >> 1)

        struct segment_node {
            int l, r;
            val_t val[2];

            void update(val_t x) {
                if (l % 2 == 0)
                    x = -x;
                val[0] = x;
                val[1] = x * l;
            }
        };

        int nn;
    public:
        vector<segment_node> node;

        void pushup(int now) {
            nd.val[0] = ndl.val[0] + ndr.val[0];
            nd.val[1] = ndl.val[1] + ndr.val[1];
        }

        void build(int s, int t, int now = 1) {
            nd.l = s, nd.r = t;
            if (s == t) {
                nd.update(num[s]);
                return;
            }
            build(s, (s + t) >> 1, now << 1);
            build(((s + t) >> 1) + 1, t, now << 1 | 1);
            pushup(now);
        }

        void update(int s, int t, val_t x, int now = 1) {
            if (s <= nd.l && t >= nd.r) {
                nd.update(x);
                return;
            }
            if (s <= mid) update(s, t, x, now << 1);
            if (t > mid) update(s, t, x, now << 1 | 1);
            pushup(now);
        }

        val_t query(int s, int t, int tp, int now = 1) {
            if (s <= nd.l && t >= nd.r)
                return nd.val[tp];
            val_t ret = 0;
            if (s <= mid) ret += query(s, t, tp, now << 1);
            if (t > mid) ret += query(s, t, tp, now << 1 | 1);
            return ret;
        }

        void init(int nnn) {
            nn = nnn;
            node.resize(nn << 2 | 3);
            build(1, nn);
        }
    };
}

int main() {
    int T;
    cin >> T;
    data_structure::segment_tree<ll> tree;
    for (int cas = 1; cas <= T; ++cas) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        tree.init(n);
        ll ans = 0;
        while (q--) {
            char op;
            int a, b;
            cin >> op >> a >> b;
            if (op == 'U')
                tree.update(a, a, b);
            else {
                ll t = tree.query(a, b, 1) - tree.query(a, b, 0) * (a - 1);
                if (a % 2 == 0)
                    t = -t;
                ans += t;
            }
        }

        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}