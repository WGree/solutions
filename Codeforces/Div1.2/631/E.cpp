//E.cpp
#include <bits/stdc++.h>
using namespace std;

const int sz = (1 << 20);

int h, g;
int a[sz << 1], hit[sz << 1];
vector<int> ans;
#define l (u << 1)
#define r l + 1

bool del(int u) {
    int uu = u;
    hit[u] = hit[u >> 1] + 1;
    while (a[u]) {
        if (a[l] > a[r]) u = l;
        else u = r;
        hit[u] = hit[u >> 1] + 1;
    }
    u >>= 1;
    if (hit[u] > g) {
        u = uu;
        while (a[u]) {
            if (a[l] > a[r]) a[u] = a[l], u = l;
            else a[u] = a[r], u = r;
        }
        return true;
    }
    return false;
}

int main() {
    cin >> q;
    while (q--) {
        cin >> h >> g;
        for (int i = 1; i < (1 << h); ++i)
            cin >> a[i];
        for (int i = 1 << h; i < (2 << h); ++i)
            a[i] = 0;
        
        ll sum = 0;
        hit[1] = 1;
        ans.clear();
        for (int i = 1; i < (1 << g); ++i) {
            while (del(i))
                ans.emplace_back(i);
            sum += a[i];
        }
        cout << sum << endl;
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}