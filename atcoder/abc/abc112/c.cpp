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

    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    REP(i, n){
        cin >> x[i] >> y[i] >> h[i];
    }

    REP(i, 101){
        REP(j, 101){
            int num;
            REP(k, n){
                if(h[k] != 0){
                    num = h[k] + abs(i - x[k]) + abs(j - y[k]);
                    break;
                }
            }
            bool flag = true;
            REP(k, n){
                if(h[k] == 0 && abs(i - x[k]) + abs(j - y[k]) >= num) continue;
                if(num != h[k] + abs(i - x[k]) + abs(j - y[k])){
                    flag = false;
                }
            }
            if(flag){
                cout << i << " " << j << " " << num << endl;
                return 0;
            }
        }
    }
}
