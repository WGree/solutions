//D.cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> m(n), c(k + 1);
    for (int &i: m) cin >> i;
    sort(m.begin(), m.end());
    for (int i = 1; i <= k; ++i)
        cin >> c[i];
    
    vector<list<int>> ans;
    priority_queue<pii, deque<pii>, greater<>> Q;
    Q.emplace(0, 0);
    ans.resize(1);
    while (!m.empty()) {
        int a = m.back();
        pii u = Q.top();
        Q.pop();
        if (u.first == c[a]) {
            Q.emplace(u);
            u = {1, ans.size()};
            ans.emplace_back();
        } else
            ++u.first;
        Q.emplace(u);
        ans[u.second].emplace_back(a);
        m.pop_back();
    }
    
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.size() << ' ';
        for (int &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}