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
    cin >> n;
    string s;
    cin >> s;

    vector<int> num;
    vector<double> ice(n+1);
    REP(i, n){
        ice[i+1] = ice[i] + 1.0 / (i + 2);
    }
    int cnt = -1;
    REP(i, n){
        if(s[i] == '-') {
            cnt++;
            num.pb(0);
        }else{
            num.back()++;
        }
    }
    sort(all(num), greater<int>());
    num[0]++;
    double ans = 0;
    REP(i, num.size()){
        ans += ice[num[i]];
    }
    printf("%.9f\n", ans + cnt);
}