#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    int maxV = 0, maxW = 0;
    for(int i = 0; i < N; i++){
        cin >> v[i] >> w[i];
        maxV = max(maxV, v[i]);
        maxW = max(maxW, w[i]);
    }

    int dataset;
    if(N <= 30) dataset = 1;
    else if(maxW <= 1000) dataset = 2;
    else dataset = 3;

    if(dataset == 1){
        vector<pair<LL, LL>> half1, half2;
        LL ans = 0;
        for(int mask = 0; mask < (1 << (N/2)); mask++){
            LL sumV = 0, sumW = 0;
            for(int i = 0; i < N/2; i++){
                if(mask & (1 << i)){
                    sumV += v[i];
                    sumW += w[i];
                }
            }
            half1.push_back(make_pair(sumV, sumW));
        }
        sort(all(half1), [](pair<LL, LL> a, pair<LL, LL> b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        vector<pair<LL, LL>> kouho;
        LL minW = INFL;
        for(int i = 0; i < half1.size(); i++){
            if(minW < half1[i].second) continue;
            kouho.push_back(make_pair(half1[i].second, half1[i].first));
            minW = half1[i].second;
        }

        sort(all(kouho));

        for(int mask = 0; mask < (1 << (N/2 + N%2)); mask++){
            LL sumV = 0, sumW = 0;
            for(int i = 0; i < N/2 + N%2; i++){
                if(mask & (1 << i)){
                    sumV += v[N/2 + i];
                    sumW += w[N/2 + i];
                }
            }
            if(sumW > W) continue;

            ans = max(ans, sumV + (*(upper_bound(all(kouho), make_pair(W - sumW, INFL)) - 1)).second);
        }
        cout << ans << endl;
    }else if(dataset == 2) {
        vector<vector<LL>> dp(N + 1, vector<LL>(W + 500, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                if (j >= w[i]) {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        cout << dp[N][W] << endl;
    }else{
        vector<vector<LL>> dp(N + 1, vector<LL>(1000 * N + 500, INFL));
        dp[0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= 1000 * N; j++) {
                if (j >= v[i]) {
                    dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        LL ans = 0;
        for(LL i = 0; i < 1000 * N + 500; i++){
            if(dp[N][i] <= W) ans = max(ans, i);
        }
        cout << ans << endl;
    }
}