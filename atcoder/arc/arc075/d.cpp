#include <bits/stdc++.h>
#define int long long

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
int n, a, b;
vector<int> h;
/**********************************************/

bool solve(int mid){
    vector<int> cur_h = h;
    REP(i, n){
        cur_h[i] -= mid*b;
    }
    int cnt = 0;
    REP(i, n){
        if(cur_h[i] > 0){
            cnt += (cur_h[i] % a != 0 ? cur_h[i] / a + 1 : cur_h[i] / a);
        }
    }
    return cnt <= mid;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    h.resize(n);
    REP(i, n) cin >> h[i];

    sort(all(h));
    
    int cnt = h[0] / b;
    a -= b;
    int ok = 1e9, ng = -1;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
