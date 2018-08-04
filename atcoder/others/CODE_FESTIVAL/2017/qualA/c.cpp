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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];

    map<char, int> mp;
    REP(i, h) REP(j, w) mp[s[i][j]]++;
    vector<int> a;
    for(auto x : mp) a.pb(x.second);
    sort(all(a), greater<int>());
    
    // abczcba
    // defzfed
    // ghiwihg
    // defzfed
    // abczcba

    if(h >= 2 && w >= 2){
        if(h % 2 == 0 && w % 2 == 0){
            for(auto x : a) if(x % 4 != 0){cout << "No" << endl; return 0;}
        }else if(h % 2 == 0 || w % 2 == 0){
            REP(i, (h/2) * (w/2)){
                if(a[0] < 4){cout << "No" << endl; return 0;}
                a[0] -= 4;
                sort(all(a), greater<int>());
            }
            for(auto x : a) if(x % 2 != 0){cout << "No" << endl; return 0;}
        }else{
            REP(i, (h/2) * (w/2)){
                if(a[0] < 4){cout << "No" << endl; return 0;}
                a[0] -= 4;
                sort(all(a), greater<int>());
            }
            REP(i, h/2){
                if(a[0] < 2){cout << "No" << endl; return 0;}
                a[0] -= 2;
                sort(all(a), greater<int>());
            }
            REP(i, w/2){
                if(a[0] < 2){cout << "No" << endl; return 0;}
                a[0] -= 2;
                sort(all(a), greater<int>());
            }
        }
    }else{
        REP(i, max(w, h)/2){
            if(a[0] < 2){cout << "No" << endl; return 0;}
            a[0] -= 2;
            sort(all(a), greater<int>());
        }
    }
    cout << "Yes" << endl;
}
