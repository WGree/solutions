//E.cpp
#include <bits/stdc++.h>

//#define endl '\n'
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
//    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int r = (n + 1) / 2, nn = (r + 1) * r / 2;

    cout << "? 1 " << r << endl;
    string s;
    map<string, int> mp;
    for (int i = 0; i < nn; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        ++mp[s];
    }
    if (r > 1) {
        cout << "? 2 " << r << endl;
        nn -= r;
        for (int i = 0; i < nn; ++i) {
            cin >> s;
            sort(s.begin(), s.end());
            --mp[s];
        }
    }

    vector<string> tmp;
    for (auto &i : mp) {
        if (i.second)
            tmp.push_back(i.first);
    }
    auto cmp = [](string &a, string &b) { return a.length() < b.length(); };
    sort(tmp.begin(), tmp.end(), cmp);

    string ans(n, 0);
    vector<int> cnt(26);
    for (int i = 0; i < r; ++i) {
        vector<int> tcnt(26);
        for (char &c : tmp[i])
            ++tcnt[c - 'a'];
        for (int j = 0; j < 26; ++j) {
            if (tcnt[j] > cnt[j])
                ans[i] = j + 'a';
            cnt[j] = tcnt[j];
        }
    }

    nn = (n + 1) * n / 2;
    cout << "? 1 " << n << endl;
    vector<vector<int>> num(n + 1, vector<int>(26));
    for (int i = 0; i < nn; ++i) {
        cin >> s;
        for (char &c : s)
            ++num[s.length()][c - 'a'];
    }
    fill(cnt.begin(), cnt.end(), 0);
    r = n / 2;
    for (int i = 1; i <= r; ++i) {
        vector<int> ht;
        for (int j = 0; j < 26; ++j) {
            int p = (num[1][j] - cnt[j]) * (i + 1) - (num[i + 1][j] - num[0][j]);
            while (p--) {
                ht.emplace_back(j);
                ++cnt[j];
                num[0][j] += i;
            }
        }
        if (ans[i - 1] == ht[0] + 'a')
            ans[n - i] = ht[1] + 'a';
        else
            ans[n - i] = ht[0] + 'a';
    }

    cout << "! " << ans << endl;
    return 0;
}