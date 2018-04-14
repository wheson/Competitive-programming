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
int q;
vector<LL> a, b;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> q;
    a.resize(q);
    b.resize(q);
    REP(i, q){
        cin >> a[i] >> b[i];
    }
    REP(i, q){
        if(a[i] == b[i]){
            cout << 2 * a[i] - 2 << endl;
        }else if(a[i] + 1 == b[i]){
            cout << 2 * a[i] - 2 << endl;
        }else{
            LL ok = 0, ng = (LL)1e9+1;
            while(abs(ok - ng) > 1){
                LL mid = (ok + ng) / 2;
                if(mid*mid < a[i]*b[i]){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            if(ok * (ok+1) >= a[i] * b[i]){
                cout << 2*ok - 2 << endl;
            }else{
                cout << 2*ok - 1 << endl;
            }
        }
    }
}
