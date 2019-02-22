#include <bits/stdc++.h>
//#define int long long

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;
    vector<LL> a(n);
    REP(i, n) cin >> a[i];
    LL sum = 0;
    REP(i, n) sum += a[i];
    if(sum % (n * (n+1) / 2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    LL num = sum / (n * (n+1) / 2);

    vector<LL> b(n);
    REP(i, n) b[i] = a[(i+1)%n] - a[i];
    REP(i, n) b[i] = b[i] - num;

    sum = 0;
    REP(i, n){
        if(b[i] % n != 0){
            cout << "NO" << endl;
            return 0;
        }
        sum += abs(b[i] / n);
    }

    cout << (sum == num ? "YES" : "NO") << endl;
}