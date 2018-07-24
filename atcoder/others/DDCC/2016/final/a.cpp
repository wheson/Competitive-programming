#include <bits/stdc++.h>
//#define int long long

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

/*************** using variables ***************/
int r, c;
/**********************************************/
bool checkInside(int x2, int y2, int r){
    return (0 - x2) * (0 - x2) + (0 - y2) * (0 - y2) <= r*r;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    int ans = 0;
    
    int x = floor((double)r/c) + 1;
    for(int h = -x; h <= x; h++){
        for(int w = -x; w <= x; w++){
            if(checkInside(w*c, h*c, r) && checkInside(w*c, h*c+c, r) &&
                checkInside(w*c+c, h*c, r) && checkInside(w*c+c, h*c+c, r)){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
