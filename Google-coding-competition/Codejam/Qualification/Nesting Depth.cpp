//Nesting Depth.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    string s;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> s;
        string ans;
        char la = '0';
        for (char c : s) {
            while (la < c) {
                ans.push_back('(');
                ++la;
            }
            while (la > c) {
                ans.push_back(')');
                --la;
            }
            ans.push_back(c);
        }
        while (la > '0') {
            ans.push_back(')');
            --la;
        }
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}