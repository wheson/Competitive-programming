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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
int n, d;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> d;
    vector<int> x(n);
    REP(i, n) cin >> x[i];

    vector<int> ruiseki(n+1);
    ruiseki[0] = 0;
    REP(i, n) ruiseki[i+1] = ruiseki[i] + x[i];

    REP(i, n){
        auto itr1 = upper_bound(all(ruiseki), x[i]+d);
        itr1--;
        int fst = itr1 - ruiseki.begin() - 1;
        
        auto itr2 = upper_bound(all(ruiseki), x[fst]+d);
    }
}
