#include <bits/stdc++.h>
#define int long long

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
vector<int> a, b;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    b.resize(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    int ans = 0;
    REP(i, 29){
        vector<int> amod(n, 0), bmod(n, 0);
        REP(j, n) amod[j] = a[j] % (2 << i), bmod[j] = b[j] % (2 << i);
        sort(all(bmod));
        
        int cnt = 0;
        REP(j, n){
            if(amod[j] & (1 << i)){
                cnt += lower_bound(all(bmod), (2 << i) - amod[j]) - bmod.begin();
                cnt += bmod.end() - lower_bound(all(bmod), (3 << i) - amod[j]);
            }else{
                cnt += lower_bound(all(bmod), (2 << i) - amod[j]) - lower_bound(all(bmod), (1 << i) - amod[j]);
            }
        }
        if(cnt % 2 == 1) ans ^= (1 << i);
    }
    cout << ans << endl;
}
