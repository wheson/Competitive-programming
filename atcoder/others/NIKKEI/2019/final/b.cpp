#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];

    if(n > m){
        cout << "Y" << endl;
    }else if(n < m){
        cout << "X" << endl;
    }else{
        REP(i, n){
            if(a[i] < b[i]){
                cout << "X" << endl;
                return 0;
            }else if(a[i] > b[i]){
                cout << "Y" << endl;
                return 0;
            }
        }
        cout << "Same" << endl;
    }
}