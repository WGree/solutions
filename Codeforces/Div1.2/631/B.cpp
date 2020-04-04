//B.cpp
#include <bits/stdc++.h>
using namespace std;

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
        vector<segment_node> node;

        void pushup(int now) {
            nd.val = ndl.val + ndr.val;
        };

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
                nd.val |= 1;
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
            if (s <= mid) {
                ret += query(s, t, now << 1);
            }
            if (t > mid) {
                ret += query(s, t, now << 1 | 1);
            }
            return ret;
        }

        void init(int nnn) {
            nn = nnn;
            node.resize(nn << 2 | 3);
            build(1, nn);
        }
    } tree;
}
using namespace data_struct;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        tree.init(n);
        vector<int> a(n + 5), pre(n + 5), suf(n + 5);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            tree.update(a[i], a[i], 1);
            if (tree.query(1, i) == i)
                pre[i] = 1;
        }
        tree.init(n);
        for (int i = n; i > 0; --i) {
            tree.update(a[i], a[i], 1);
            if (tree.query(1, n - i + 1) == n - i + 1)
                suf[i] = 1;
        }
        vector<pii> ans;
        for (int i = 1; i < n; ++i) {
            if (pre[i] && suf[i + 1])
                ans.emplace_back(i, n - i);
        }
        cout << ans.size() << endl;
        for (pii i : ans)
            cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}