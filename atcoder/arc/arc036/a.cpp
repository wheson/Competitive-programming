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
int n, k;
vector<int> t;
vector<int> ruiseki;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    t.resize(n);
    ruiseki.resize(n+1);
    REP(i, n) cin >> t[i];
    
    ruiseki[0] = 0;
    REP(i, n) ruiseki[i+1] = ruiseki[i] + t[i];
    for(int i = 3; i <= n; i++){
        if(ruiseki[i] - ruiseki[i-3] < k){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
