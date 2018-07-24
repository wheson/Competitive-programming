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
int k;
const int wafer1 = 200;
const int wafer2 = 300;
/**********************************************/
bool checkInside(int x1, int y1, int x2, int y2, int r){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r*r;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> k;
    int cnt1 = 0, cnt2 = 0;
    for(int y = 0; y <= wafer1; y += k){
        for(int x = 0; x <= wafer1; x += k){
            bool flag = checkInside(wafer1/2, wafer1/2, x, y, wafer1/2);
            flag = flag && checkInside(wafer1/2, wafer1/2, x+k, y, wafer1/2);
            flag = flag && checkInside(wafer1/2, wafer1/2, x, y+k, wafer1/2);
            flag = flag && checkInside(wafer1/2, wafer1/2, x+k, y+k, wafer1/2);

            if(flag) cnt1++;
        }
    }


    for(int y = 0; y <= wafer2; y += k){
        for(int x = 0; x <= wafer2; x += k){
            bool flag = checkInside(wafer2/2, wafer2/2, x, y, wafer2/2);
            flag = flag && checkInside(wafer2/2, wafer2/2, x+k, y, wafer2/2);
            flag = flag && checkInside(wafer2/2, wafer2/2, x, y+k, wafer2/2);
            flag = flag && checkInside(wafer2/2, wafer2/2, x+k, y+k, wafer2/2);

            if(flag) cnt2++;
        }
    }

    cout << cnt1 << " " << cnt2 << endl;
}
