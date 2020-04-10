//E.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

namespace data_struct {
    class segment_tree {
#define nd node[now]
#define ndl node[now << 1]
#define ndr node[now << 1 | 1]
#define mid ((nd.l + nd.r) >> 1)
    public:
        struct segment_node {
            int l, r, val;
        };

        int nn;
        vector <segment_node> node;

        void pushup(int now) {
            nd.val = ndl.val + ndr.val;
        }

        void build(int s, int t, int now = 1) {
            nd.l = s, nd.r = t;
            if (s == t) {
                nd.val = 0;
                return;
            }
            build(s, (s + t) >> 1, now << 1);
            build(((s + t) >> 1) + 1, t, now << 1 | 1);
            pushup(now);
        }

        void update(int s, int t, int x, int now = 1) {
            if (s <= nd.l && t >= nd.r) {
                ++nd.val;
                return;
            }
            if (s <= mid)
                update(s, t, x, now << 1);
            if (t > mid)
                update(s, t, x, now << 1 | 1);
            pushup(now);
        }

        int query(int s, int t, int now = 1) {
            if (s <= nd.l && t >= nd.r) {
                return nd.val;
            }
            int ret = 0;
            if (s <= mid)
                ret += query(s, t, now << 1);
            if (t > mid)
                ret += query(s, t, now << 1 | 1);
            return ret;
        }

        explicit segment_tree(int nnn) {
            nn = nnn;
            node.resize(nn << 2 | 3);
            build(0, nn);
        }
    };
}
using namespace data_struct;

int a[N];

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    cin >> a[1];
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    for (int i = n; i > 0; --i) {
        a[i] -= a[1];
    }
    segment_tree tree(n);
    tree.update(0, 0, 1);
    for (int i = k; i <= n; ++i) {
        int l = lower_bound(a + 1, a + n + 1, a[i] - d) - a - 1;
        if (tree.query(l, i - k))
            tree.update(i, i, 1);
    }

    if (tree.query(n, n)) puts("YES");
    else puts("NO");
    return 0;
}