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
int N, C;
vector<int> s, t, c;
int imos[200005][31];
int imos2[200005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    s.resize(N);
    t.resize(N);
    c.resize(N);
    REP(i, N) cin >> s[i] >> t[i] >> c[i];
    
    REP(j, 31) REP(i, 200005) imos[i][j] = 0;
    REP(i, 200005) imos2[i] = 0;

    REP(i, N){
        imos[s[i]*2][c[i]]++;
        imos[t[i]*2+1][c[i]]--;
    }

    REP(j, 31) REP(i, 200005){
        imos[i+1][j] += imos[i][j];
    }
    
    bool flag = false;
    REP(j, 31) REP(i, 200005){
        if(!flag && imos[i][j] == 1) {
            imos2[max(0, i-1)]++;
            flag = true;
        }else if(flag && imos[i][j] == 0){
            imos2[i]--;
            flag = false;
        }
    }

    REP(i, 200005){
        imos2[i+1] += imos2[i];
    }


    int ans = 0;
    REP(i, 200005){
        ans = max(ans, imos2[i]);
    }

    cout << ans << endl;


}
