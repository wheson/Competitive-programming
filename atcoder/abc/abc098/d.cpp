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
vector<int> a;
/**********************************************/

// 2^20 = 10^6
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    int sum = 0; int xsum = 0;
    int ans = 0;

    for(int l = 0, r = 0; r < n; l++){
        while(1){
            if(r >= n) break;
            if(sum + a[r] != (xsum xor a[r])) break;
            sum += a[r]; xsum = (xsum xor a[r]);
            ans += r-l+1;
            r++;
        }
        sum -= a[l]; xsum = (xsum xor a[l]);
    }
    cout << ans << endl;
}
