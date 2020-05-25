//d.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int n;
int v[N];

void update(int key, int val) {
    while (key <= n) {
        v[key] += val;
        key += -key & key;
    }
}

int query(int cnt) {
    int now = 0;
    for (int i = 20; i >= 0; --i) {
        int x = now | (1 << i);
        if (x <= n && v[x] < cnt) {
            cnt -= v[x];
            now = x;
        }
    }
    return now + 1;
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        update(t, 1);
    }
    while (q--) {
        int x;
        cin >> x;
        if (x > 0) update(x, 1);
        else {
            x = query(-x);
            update(x, -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}