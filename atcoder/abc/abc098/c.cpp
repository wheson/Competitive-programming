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
string s;
int ruiseki1[3*100000+5];
int ruiseki2[3*100000+5];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    ruiseki1[0] = 0;
    ruiseki2[0] = 0;
    REP(i, n){
        if(s[i] == 'E'){
            ruiseki1[i+1] = ruiseki1[i] + 1;
        }else{
            ruiseki1[i+1] = ruiseki1[i];
        }
    }
    REP(i, n){
        if(s[i] == 'W'){
            ruiseki2[i+1] = ruiseki2[i] + 1;
        }else{
            ruiseki2[i+1] = ruiseki2[i];
        }
    }

    int ans = INF;
    REP(i, n){
        ans = min(ans, ruiseki1[n] - ruiseki1[i+1] + ruiseki2[i]);
    }
    cout << ans << endl;
}
