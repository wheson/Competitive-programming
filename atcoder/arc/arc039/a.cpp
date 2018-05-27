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
int a, b;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    int ans = a-b;
    if((a/100)%10 != 9) ans = max(ans, a%100 + 900 - b);
    else if((a/10)%10 != 9) ans = max(ans, a%10 + 990 - b);
    else if(a%10 != 9) ans = max(ans, 999 - b);

    if((b/100)%10 != 1) ans = max(ans, a - (b%100 + 100));
    else if((b/10)%10 != 0) ans = max(ans, a - (b%10 + 100));
    else if(b%10 != 0) ans = max(ans, a - (100));
    
    cout << ans << endl;
}
