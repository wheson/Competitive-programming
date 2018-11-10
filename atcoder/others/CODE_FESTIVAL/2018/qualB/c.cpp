#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int) 1e9;
const LL INFL = (LL) 1e18;
const int MOD = (int) 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    int num = 4;
    REP(i, n) {
        REP(j, n) {
            if (i % 2 == 0) {
                if (j >= num && (j - num) % 5 == 0) graph[i][j]++;
            } else {
                if (j >= num && (j - num) % 5 == 0) graph[i][j]++;
            }
        }
        if (i % 2 == 0) num = (num + 5 - 3) % 5;
        else num = (num + 5 + 2) % 5;
    }

    REP(i, n) REP(j, n) {
            if (graph[i][j] == 0) {
                bool flag = false;
                if (i > 0 && graph[i - 1][j] >= 1) flag = true;
                if (i < n - 1 && graph[i + 1][j] >= 1) flag = true;
                if (j > 0 && graph[i][j - 1] >= 1) flag = true;
                if (j < n - 1 && graph[i][j + 1] >= 1) flag = true;

                if (!flag) graph[i][j]++;
            }
        }

    int sum = 0;
    REP(i, n) {
        REP(j, n) {
            if (graph[i][j] >= 1) sum++;
            cout << (graph[i][j] >= 1 ? 'X' : '.');
        }
        cout << endl;
    }
}