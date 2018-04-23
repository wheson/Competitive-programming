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
int n;
vector<int> a;
vector<int> charge; // charge[N] := NからN+1に行くのにかかる金額
int sum = 0;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a.assign(n+2, 0);
    charge.assign(n+2, 0);
    FOR(i, 1, n+1) cin >> a[i];

    REP(i, n+1){
        charge[i] = abs(a[i] - a[i+1]);
        sum += charge[i];
    }
    FOR(i, 0, n){
        cout << sum - charge[i] - charge[i+1] + abs(a[i] - a[i+2]) << endl;
    }

}
