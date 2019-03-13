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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> p(n);
    REP(i, n) cin >> p[i];

    vector<int> check(n+1, -1);

    int sum = 0;
    REP(i, n){
        if(check[p[i] - 1] > 0){
            check[p[i]] = check[p[i] - 1] + 1;
        }else{
            check[p[i]] = 1;
        }
        sum = max(check[p[i]], sum);
    }
    cout << n - sum << endl;
}