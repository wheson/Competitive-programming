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

string lcs(vector<vector<int>> &dp, int i, int j, string s, string t){
    if(i == 0 || j == 0) return "";

    string ret = "";
    if(s[i-1] == t[j-1]){
        ret = lcs(dp, i-1, j-1, s, t) + s[i-1];
    }else{
        if(dp[i-1][j] >= dp[i][j-1]) ret = lcs(dp, i-1, j, s, t);
        else ret = lcs(dp, i, j-1, s, t);
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    const int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    REP(i, n){
        REP(j, m){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << lcs(dp, n, m, s, t) << endl;
}