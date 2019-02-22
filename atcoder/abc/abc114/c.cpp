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
const int MOD = (int)1e9 + 7;

int ans = 0;
int n;
void f(int num, int keta, int cnt){
    if(keta == cnt){
        if(num > n) return;

        int flag = 0;
        while(num > 0){
            if(num % 10 == 3) flag |= 1;
            if(num % 10 == 5) flag |= 2;
            if(num % 10 == 7) flag |= 4;
            num /= 10;
        }
        if(flag == 7) ans++;
        return;
    }
    f(num * 10 + 3, keta, cnt+1);
    f(num * 10 + 5, keta, cnt+1);
    f(num * 10 + 7, keta, cnt+1);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i, 9){
        f(0, i+1, 0);
    }
    cout << ans << endl;

}