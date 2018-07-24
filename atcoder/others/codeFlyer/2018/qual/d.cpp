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
int h, w;
int n, m;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w >> n >> m;
    vector<string> a(n);
    REP(i, n) cin >> a[i];

    int ruiseki[1005][1005];
    REP(i, n+1) REP(j, m+1) ruiseki[i][j] = 0;
    REP(i, n) REP(j, m){
        if(a[i][j] == '#') ruiseki[i][j] = 1;
    }

    REP(i, n) REP(j, m){
        ruiseki[i+1][j+1] += ruiseki[i][j+1] + ruiseki[i+1][j];
    }
    
    int sum = 0;
    REP(i, n) REP(j, m) if(a[i][j] == '#'){
        int ok = i, ng = n+1;
        int cnt1 = 0;
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(ruiseki[mid][j] == ruiseki[i][j]){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << i << " " << j << ": " << ok << endl;
        if(ok - i > h-n+1) cnt1 = ok - i+1;
        else if(ng == n+1) cnt1 = h-n+1;
        ok = j, ng = m+1;
        int cnt2 = 0;
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(ruiseki[i][mid] == ruiseki[i][j]){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << i << " " << j << ": " << ok << endl;
        if(ok - j > w-m+1) cnt2 = ok - j+1;
        else if(ng == m+1) cnt2 = w-m+1;
        
        sum += cnt1*cnt2;
        cout << i << " " << j << " " << cnt1*cnt2 << endl;
    }

    cout << sum << endl;
}
