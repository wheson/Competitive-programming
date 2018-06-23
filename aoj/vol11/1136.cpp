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

vector<P> kaiten(vector<P> line){
    vector<P> ret;
    REP(i, line.size()) ret.pb(P(-line[i].second, line[i].first));
    return ret;
}

bool f(vector<P> l0, vector<P> li){
    if(l0.size() != li.size()) return false;

    bool flag = false;
    
    REP(i, l0.size()) l0[l0.size()-i-1].first -= l0[0].first, l0[l0.size()-i-1].second -= l0[0].second;
    vector<P> l1;
    l1.pb(P(0, 0));
    FOR(i, 1, li.size()) l1.pb(P(li[i].first - li[0].first, li[i].second - li[0].second));
    
    REP(i, l0.size()){
        if(l0[i].first != l1[i].first || l0[i].second != l1[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }
    
    l1 = kaiten(l1);
    REP(i, l0.size()){
        if(l0[i].first != l1[i].first || l0[i].second != l1[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    l1 = kaiten(l1);
    REP(i, l0.size()){
        if(l0[i].first != l1[i].first || l0[i].second != l1[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    l1 = kaiten(l1);
    REP(i, l0.size()){
        if(l0[i].first != l1[i].first || l0[i].second != l1[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }
    
    reverse(all(li));
    vector<P> l2;
    l2.pb(P(0, 0));
    FOR(i, 1, li.size()) l2.pb(P(li[i].first - li[0].first, li[i].second - li[0].second));

    REP(i, l0.size()){
        if(l0[i].first != l2[i].first || l0[i].second != l2[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    l2 = kaiten(l2);
    REP(i, l0.size()){
        if(l0[i].first != l2[i].first || l0[i].second != l2[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    l2 = kaiten(l2);
    REP(i, l0.size()){
        if(l0[i].first != l2[i].first || l0[i].second != l2[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    l2 = kaiten(l2);
    REP(i, l0.size()){
        if(l0[i].first != l2[i].first || l0[i].second != l2[i].second) break;
        if(i >= l0.size()-1) flag = true;
    }

    return flag;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        vector<vector<P>> lines(n+1);
        REP(i, n+1){
            int m; cin >> m;
            REP(j, m){
                P p; cin >> p.first >> p.second;
                lines[i].pb(P(p.first, p.second));
            }
        }
        
        FOR(i, 1, n+1){
            if(f(lines[0], lines[i])) cout << i << endl;
        }
        cout << "+++++" << endl;
    }
}
