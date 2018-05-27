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
int h, w, n;
vector<int> a, b;
map<P, int> mp;
int ans[10];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w >> n;
    a.resize(n);
    b.resize(n);
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) a[i]--, b[i]--;

    REP(i, n){
        if(a[i] < h-2 && b[i] < w-2) mp[P(a[i], b[i])]++;

        if(a[i]-2 < h-2 && b[i] < w-2 && a[i] - 2 >= 0) mp[P(a[i] - 2, b[i])]++;
        if(a[i]-1 < h-2 && b[i] < w-2 && a[i] - 1 >= 0) mp[P(a[i] - 1, b[i])]++;
        if(a[i] < h-2 && b[i]-2 < w-2 && b[i] - 2 >= 0) mp[P(a[i], b[i] - 2)]++;
        if(a[i] < h-2 && b[i]-1 < w-2 && b[i] - 1 >= 0) mp[P(a[i], b[i] - 1)]++;
        if(a[i]-2 < h-2 && b[i]-2 < w-2 && a[i] - 2 >= 0 && b[i] - 2 >= 0) mp[P(a[i] - 2, b[i] - 2)]++;
        if(a[i]-2 < h-2 && b[i]-1 < w-2 && a[i] - 2 >= 0 && b[i] - 1 >= 0) mp[P(a[i] - 2, b[i] - 1)]++;
        if(a[i]-1 < h-2 && b[i]-2 < w-2 && a[i] - 1 >= 0 && b[i] - 2 >= 0) mp[P(a[i] - 1, b[i] - 2)]++;
        if(a[i]-1 < h-2 && b[i]-1 < w-2 && a[i] - 1 >= 0 && b[i] - 1 >= 0) mp[P(a[i] - 1, b[i] - 1)]++;
    }

    ans[0] = (h-2) * (w-2);
    for(auto x: mp){
        ans[x.second]++;
    }
    FOR(i, 1, 10) ans[0] -= ans[i];
    REP(i, 10) cout << ans[i] << endl;
}
