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

int n, m, d;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> d;
    
    if(d == 0){
        printf("%.9f\n", (double)(m-1)/n);
    }else{
        int x = (n-1) * 2;
        x -= (d - 1) * 2;
        x *= (m - 1);
        double ans = (double)x / (n*n);
        
        printf("%.9f\n", ans);
    }

}
