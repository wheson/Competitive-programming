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
int n;
vector<int> c, cnt;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    c.resize(n);
    cnt.assign(n, 0);
    REP(i, n) cin >> c[i];

    sort(all(c));
    
    REP(i, n){
        REP(j, n) if(i != j){
            if(c[i] % c[j] == 0) cnt[i]++;
        }
    }

    double ans = 0;
    REP(i, n){
        double p = ((cnt[i]+1) / 2 + (cnt[i]+1) % 2) / (double)(cnt[i]+1);
        ans += p;
    }
    printf("%.9f\n", ans);
}
