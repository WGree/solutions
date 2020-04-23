//Pascal Walk.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int TT;
    cin >> TT;
    for (int cas = 1; cas <= TT; ++cas) {
        int n;
        cin >> n;
        printf("Case #%d:\n", cas);
        if (n <= 30) {
            for (int i = 1; i <= n; ++i) {
                printf("%d 1\n", i);
            }
        } else {
            int t = n - 30, cc = 30, j = 1, i;
            for (i = 1; i <= 30; ++i) {
                if (t >> (i - 1) & 1) {
                    if (j != i) {
                        while (j < i)
                            printf("%d %d\n", i, j++);
                    } else {
                        while (j > 1)
                            printf("%d %d\n", i, j--);
                    }
                } else --cc;
                printf("%d %d\n", i, j);
                if (j == i) ++j;
            }
            while (cc--) {
                printf("%d %d\n", i++,j);
                if (j == i - 1) ++j;
            }
        }
    }
    return 0;
}