#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    LL d;
    cin >> n >> d;

    int cnt2 = 0, cnt3 = 0, cnt5 = 0;
    while(d % 2 == 0) d /= 2, cnt2++;
    while(d % 3 == 0) d /= 3, cnt3++;
    while(d % 5 == 0) d /= 5, cnt5++;

    if(d != 1){
        cout << 0 << endl;
        return 0;
    }

    double dp[105][cnt2 + 5][cnt3 + 5][cnt5 + 5];
    dp[0][0][0][0] = 1;

    REP(i, n){
        REP(j, cnt2+1){
            REP(k, cnt3+1){
                REP(l, cnt5+1){
                    dp[i+1][j][k][l] += dp[i][j][k][l] / 6; // 1
                    dp[i+1][min(j+1, cnt2)][k][l] += dp[i][j][k][l] / 6; // 2
                    dp[i+1][j][min(k+1, cnt3)][l] += dp[i][j][k][l] / 6; // 3
                    dp[i+1][min(j+2, cnt2)][k][l] += dp[i][j][k][l] / 6; // 2*2
                    dp[i+1][j][k][min(l+1, cnt5)] += dp[i][j][k][l] / 6; // 5
                    dp[i+1][min(j+1, cnt2)][min(k+1, cnt3)][l] += dp[i][j][k][l] / 6; // 2*3
                }
            }
        }
    }

    printf("%.9f\n", dp[n][cnt2][cnt3][cnt5]);
}