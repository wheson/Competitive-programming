#include <bits/stdc++.h>

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

//#define int long long

/*************** using variables ***************/
int n;
LL c;
vector<LL> x, v;
vector<bool> closed;

LL ans = 0;
/**********************************************/

void dfs(int cur, LL sum, bool flag){
    if(flag){
        REP(i, n){
            if(!closed[i]){
                ans = max(ans, sum + v[i] - (x[i] - cur));
                closed[i] = true;
                cout << sum << " " << v[i] << " " << x[i] - cur << endl;
                dfs(x[i], sum + v[i] - (x[i] - cur), false);
            }
        }
    }else{
        for(int i = n - 1; i >= 0; i--){
            if(!closed[i]){
                closed[i] = true;
                if(cur < x[i]){
                    ans = max(ans, sum + v[i] - (cur + c - x[i]));
                }else{
                    ans = max(ans, sum + v[i] - (cur - x[i]));
                }
            }
        }
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    x.resize(n);
    v.resize(n);
    closed.resize(n);
    REP(i, n) cin >> x[i] >> v[i];
/*
    LL dp1[100005][2], dp2[100005][2];
    LL cur = 0;
    REP(i, n){
        dp1[i+1][0] = max(dp1[i][0], dp1[i][0] + v[i]  - (x[i] - cur)); 
        cout << i+1 << " " << dp1[i+1] << endl;
        cur += x[i];
    }
    cur = 0;
    REP(i, n){
        dp2[i+1] = max(dp2[i], dp2[i] + v[n - i - 1] - (c - x[n - i - 1] - cur));
        cout << i+1 << " " << dp2[i+1] << endl;
        cur += c - x[n - i - 1];
    }

    cout << max(dp1[n], dp2[n]) << endl;
*/
    dfs(0, 0, false);
    cout << ans << endl;
}
