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

int atoi(string s){
    int ret = 0;
    REP(i, s.size()){
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int ans = INF;
    REP(i, s.size()-2){
        ans = min(abs(atoi(s.substr(i, 3)) - 753), ans);
    }
    cout << ans << endl;
}