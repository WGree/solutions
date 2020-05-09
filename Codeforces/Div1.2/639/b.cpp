//b.cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;

int n, m, cnt;
int to[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char g[N][N];
bool l[N][N], r[N][N], u[N][N], d[N][N];

void bfs(int x, int y) {
    ++cnt;
    queue<pii> q;
    q.emplace(x, y);
    g[x][y] = '.';
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (auto i : to) {
            pii tt = t;
            tt.first += i[0];
            tt.second += i[1];
            if (tt.first < 1 || tt.first > n || tt.second < 1 || tt.second > m)
                continue;
            if (g[tt.first][tt.second] != '#')
                continue;
            g[tt.first][tt.second] = '.';
            q.emplace(tt);
        }
    }
}

bool check() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            l[i][j] = l[i][j - 1];
            if (g[i][j - 1] == '#')
                l[i][j] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            r[i][j] = r[i][j + 1];
            if (g[i][j + 1] == '#')
                r[i][j] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            u[i][j] = u[i - 1][j];
            if (g[i - 1][j] == '#')
                u[i][j] = true;
        }
    }
    for (int i = n; i >= 0; --i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = d[i + 1][j];
            if (g[i + 1][j] == '#')
                d[i][j] = true;
        }
    }
    bool row = false, col = false;
    for (int i = 1; i <= n; ++i) {
        if (!r[i][0])
            row = true;
    }
    for (int i = 1; i <= m; ++i) {
        if (!d[0][i])
            col = true;
    }
    if (row ^ col) {
//        cout << "empty difference WRONG" << endl;
        return true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == '.' && ((u[i][j] && d[i][j]) || (l[i][j] && r[i][j]))) {
//                cout << "black wight blacck WRONG" << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (g[i] + 1);
    }
    if (check()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == '#')
                bfs(i, j);
        }
    }
    cout << cnt << endl;
    return 0;
}