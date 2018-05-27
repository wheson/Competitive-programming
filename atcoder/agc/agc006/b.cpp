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
int n, x;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        vector<int> a(2*n-1);
        REP(i, 2*n-1){
            a[(n+i-1)%(2*n-1)] = (x+i-1)%(2*n-1)+1;
        }

        REP(i, 2*n-1) cout << a[i] << endl;
    }
}
