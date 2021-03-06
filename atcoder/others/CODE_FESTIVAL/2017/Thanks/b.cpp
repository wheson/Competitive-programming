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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    string org = s;
    int n = s.size();
    REP(i, n-1){
        string rs = s;
        reverse(all(rs));
        if(s == rs){
            cout << i << endl;
            return 0;
        }
        string adds = org.substr(0, i+1);
        reverse(all(adds));
        s = org + adds;
    }
    cout << n-1 << endl;
}
