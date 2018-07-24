#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n, c;
vector<int> l;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    l.assign(n, 0);
    REP(i, n) cin >> l[i];

    sort(all(l));

    int right = n-1, left = 0, ans = 0;
    while(1){
        if(left > right) break;
        if(l[left] + l[right] + 1 <= c){
            right--; left++;
            ans++;
        }else{
            right--;
            ans++;
        }
    }

    cout << ans << endl;
}
