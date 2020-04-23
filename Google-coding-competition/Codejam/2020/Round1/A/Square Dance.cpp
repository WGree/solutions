//Square Dance.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int x, y;
int u[N], d[N], l[N], r[N], v[N], vis[N];

inline int po(int a, int b){
    return a * y + b + 1;
}

double calc(int t) {
    vector<int> tp;
    if (u[t]) tp.emplace_back(v[u[t]]);
    if (d[t]) tp.emplace_back(v[d[t]]);
    if (l[t]) tp.emplace_back(v[l[t]]);
    if (r[t]) tp.emplace_back(v[r[t]]);
    double ss = 0;
    for (int k : tp) ss += k;
    if (tp.empty()) return 0.0;
    return ss / tp.size();
}

inline void init(int t) {
    if (i) u[t] = t - y;
    else u[t] = 0;
    if (i + 1 < x) d[t] = t+ y;
    else d[t] = 0;
    if (j) l[t] = t-1;
    else l[t] = 0;
    if (j + 1 < y) r[t] = t + 1;
    else r[t] = 0;
    vis[t] = INF32;
}

int main() {
    int TT;
    cin >> TT;
    for (int cas = 1; cas <= TT; ++cas) {
        int cc = 2;
        ll sum = 0;
        cin >> x >> y;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int t = po(i, j);
                init(t);
                cin >> v[po(i, j)];
                sum += v[po(i, j)];
            }
        }
        ll ans = sum;
        queue<int> Q;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int t = po(i, j);
                if (calc(t) > v[t]) {
                    vis[t] = 0;
                    sum -= v[t];
                    Q.emplace(t);
                }
            }
        }
        while (++cc) {
            if (Q.empty()) break;
            ans += sum;
            queue<int> q;
            while (!Q.empty()) {
                int t = Q.front();
                Q.pop();
                if (u[t]) d[u[t]] = d[t], q.emplace(u[t]);
                if (d[t]) u[d[t]] = u[t], q.emplace(d[t]);
                if (l[t]) r[l[t]] = r[t], q.emplace(l[t]);
                if (r[t]) l[r[t]] = l[t], q.emplace(r[t]);
            }
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                if (vis[t] <= cc) continue;
                if (calc(t) > v[t]) {
                    vis[t] = cc;
                    sum -= v[t];
                    Q.emplace(t);
                }
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}