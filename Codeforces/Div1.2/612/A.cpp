//A.cpp
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
        int k;
        string s;
        cin >> k >> s;
 
        int ans = 0, la = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'A') {
                if (la != -1)
                    ans = max(ans, i - la - 1);
                la = i;
            }
        }
        if (la != -1)
            ans = max(ans, int(s.length()) - la - 1);
        cout << ans << endl;
    }
}