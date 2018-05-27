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
int e[6], b, l[6];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 6) cin >> e[i];
    cin >> b;
    REP(i, 6) cin >> l[i];
    
    map<int, int> mp;
    REP(i, 6) mp[e[i]]++;
    int cnt = 0;
    bool bflag = false;
    REP(i, 6) if(mp[l[i]] >= 1){cnt++; mp[l[i]]--;} else if(l[i] == b) bflag = true;
    
    if(cnt <= 2) cout << 0 << endl;
    else if(cnt <= 3) cout << 5 << endl;
    else if(cnt <= 4) cout << 4 << endl;
    else if(cnt <= 5 && bflag) cout << 2 << endl;
    else if(cnt <= 5) cout << 3 << endl;
    else cout << 1 << endl;
}
