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

bool f(string a, string b){
    if(a.size() > b.size()) return true;
    else if(a.size() < b.size()) return false;
    else {
        REP(i, a.size()){
            if(a[i] == b[i]) continue;

            if((int)(a[i] - '0') > (int)(b[i] - '0')) return true;
            else return false;
        }
    }
    return true;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int hon[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    bool use[9] = {false};

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    REP(i, m) cin >> a[i];
    REP(i, m) use[a[i]-1] = true;

    string dp[10005];
    bool ok[10005] = {false};
    dp[0] = ""; ok[0] = true;
    REP(i, n+1){
        REP(j, 9) if(use[j]){
            if(i-hon[j] >= 0 && ok[i-hon[j]]){
                char cur = (char)('0' + j+1);
                string curstr = cur + dp[i-hon[j]];
                if(f(curstr, dp[i])){
                    dp[i] = curstr;
                    ok[i] = true;
                }
            }
        }
    }
    cout << dp[n] << endl;
}