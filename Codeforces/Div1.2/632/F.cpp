//F.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i * 2; j <= n; j += i)
            a[j] = i;
    }
    sort(a.begin(), a.end());
    for (int i = 2; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}