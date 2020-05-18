//d.cpp
#include <bits/stdc++.h>
using namespace std;

namespace data_structure {
    template<typename val_t>
    class BIT {
        int n;

    public:
        vector<val_t> _v;
        void update(int p, val_t v) {
            while (p <= n) {
                _v[p] += v;
                p += -p & p;
            }
        }

        int kth(int k) {
            int res = 0, t = 31 - __builtin_clz(n);
            while (t >= 0) {
                if ((res | (1 << t)) <= n && _v[res | (1 << t)] < k) {
                    res |= (1 << t);
                    k -= _v[res];
                }
                --t;
            }
            return res + 1;
        }

        explicit BIT(int nn) {
            n = nn;
            _v.resize(nn + 1);
        }
    };
}

int main() {
    int n, q;
    cin >> n >> q;
    data_structure::BIT<int> bit(1e6);
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        bit.update(t, 1);
    }
    for (int i = 0, t; i < q; ++i) {
        cin >> t;
        if (t > 0)
            bit.update(t, 1);
        else {
            int k = bit.kth(-t);
            bit.update(k, -1);
        }
    }
    for (int i = 0; i <= 1e6; ++i) {
        if (bit._v[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}