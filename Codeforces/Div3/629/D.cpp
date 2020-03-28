//D.cpp
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
const int N = 5e5 + 5;
const int sz = (1 << 20);

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a[n] = a[0];
        int f = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] != a[i]) {
                f = 0; break;
            }
        }
        if (f) {
            cout << 1 << endl;
            while (n--) cout << "1 ";
            cout << endl;
            continue;
        }

        f = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] == a[i]) {
                f = i; break;
            }
        }
        if (!f && (n & 1)) {
            cout << 3 << endl;
            for (int i = 0; i < n - 1; ++i) cout << i % 2 + 1 << ' ';
            cout << 3 << endl;
            continue;
        }
        cout << 2 << endl;
        if (n % 2 == 0) {
            for (int i = 0; i < n; ++i) cout << i % 2 + 1 << ' ';
        } else {
            for (int i = 0; i < f; ++i) cout << i % 2 + 1 << ' ';
            for (int i = f; i < n; ++i) cout << 2 - i % 2 << ' ';
        }
        cout << endl;
    }
    return 0;
}