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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

vector<char> p;
char dfs(char cur, int cnt){
    if(cnt >= p.size()) return cur;

    if(cur == 'T' && p[cnt] == 'T') {
        //cout << 'T' << endl;
        return dfs('T', cnt+1);
    }
    else if(cur == 'T' && p[cnt] == 'F') {
        //cout << 'F' << endl;
        return dfs('F', cnt+1);
    }
    else if(cur == 'F' && p[cnt] == 'T') {
        //cout << 'T' << endl;
        return dfs('T', cnt+1);
    }
    else {
        //cout << 'T' << endl;
        return dfs('T', cnt+1);
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    p.resize(n);
    REP(i, n) cin >> p[i];

    cout << dfs(p[0], 1) << endl;

}