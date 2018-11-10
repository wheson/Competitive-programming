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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; int x, y;
    cin >> s >> x >> y;

    int dir = 2;
    vector<int> xsec, ysec;
    REP(i, s.size()){
        if(s[i] == 'F'){
            if(dir == 2) x--;
            else if(dir == 0) xsec.back()++;
            else if(dir == 1) ysec.back()++;
        }else{
            dir = (dir + 1) % 2;
            (dir == 0 ? xsec : ysec).pb(0);
        }
    }

    set<int> dp1;
    dp1.insert(0);
    REP(i, xsec.size()){
        set<int> tmp;
        for(int st : dp1){
            tmp.insert(st + xsec[i]);
            tmp.insert(st - xsec[i]);
        }
        swap(dp1, tmp);
    }

    set<int> dp2;
    dp2.insert(0);
    REP(i, ysec.size()){
        set<int> tmp;
        for(int st : dp2){
            tmp.insert(st + ysec[i]);
            tmp.insert(st - ysec[i]);
        }
        swap(dp2, tmp);
    }

    auto itr1 = dp1.lower_bound(x);
    auto itr2 = dp2.lower_bound(y);

    if(itr1 != dp1.end() && *itr1 == x && itr2 != dp2.end() && *itr2 == y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
