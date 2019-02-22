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
    int n;
    cin >> n;

    vector<int> ans(n);
    for(int i = 0; i < n; i += 5){
        vector<int> vec(n);
        int cnt = 0;
        for(int j = 0; j < 5 && i+j < n; j++){
            vec[i+j] = pow(10, j);
            cnt++;
        }

        printf("? ");
        REP(j, n){
            printf("%d%c", vec[j], (j != n-1 ? ' ' : '\n'));
        }

        fflush(stdout);

        LL res;
        cin >> res;

        REP(j, cnt){
            res -= 8 * pow(10, j);
        }

        for(int j = 0; j < cnt && i+j < n; j++){
            ans[i+j] = res % 10;
            res /= 10;
        }
    }

    printf("! ");
    REP(i, n){
        printf("%d%c", (ans[i] % 2 == 0 ? 0 : 1), (i != n-1 ? ' ' : '\n'));
    }
    fflush(stdout);
}