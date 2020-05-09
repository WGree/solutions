//d.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t1, t2;
    cout << 'a' << endl;
    cin >> t1;
    if (t1 == 0)
        return 0;
    if (t1 == 300) {
        cout << string(300, 'b') << endl;
        return 0;
    }
    string s(t1 + 1, 'a');
    cout << s << endl;
    cin >> t2;
    if (t2 == 0)
        return 0;
    if (t2 > t1) {
        cout << string(t1, 'b') << endl;
        return 0;
    }
    int n = t1 + 1;
    for (int i = 0; i < n; ++i) {
        s[i] = 'b';
        cout << s << endl;
        cin >> t1;
        if (t1 == 0)
            break;
        if (t1 < t2) t2 = t1;
        else s[i] = 'a';
    }
    return 0;
}