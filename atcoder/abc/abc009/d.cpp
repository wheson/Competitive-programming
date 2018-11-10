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

using MAT = vector<vector<unsigned int>>;

MAT Mul(MAT &a, MAT &b) {
    MAT c(a.size(), vector<unsigned int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                c[i][j] ^= a[i][k] & b[k][j];
            }
        }
    }
    return c;
}

MAT Pow(MAT a, int n) {
    MAT b(a.size(), vector<unsigned int>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        b[i][i] = UINT_MAX; // 0x1111..11
    }
    while (n > 0) {
        if (n & 1) b = Mul(b, a);
        a = Mul(a, a);
        n >>= 1;
    }
    return b;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, m;
    cin >> k >> m;
    MAT a(k, vector<unsigned int>(1));
    REP(i, k) cin >> a[k - i - 1][0];
    MAT c(k, vector<unsigned int>(k));
    REP(i, k) cin >> c[0][i];
    REP(i, k - 1) c[i + 1][i] = UINT_MAX;

    c = Pow(c, m - 1);
    a = Mul(c, a);

    cout << a[k - 1][0] << endl;
}