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

vector<int> sum1(100005, 0), sum2(100005, 0);

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(3*n);
    REP(i, 3*n) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
   
    int sum = 0;
    REP(i, n) sum += a[i], pq1.push(a[i]);
    sum1[0] = sum;

    REP(i, n){
        pq1.push(a[i+n]);
        sum += a[i+n];
        sum -= pq1.top();
        pq1.pop();
        sum1[i+1] = sum;
    }

    sum = 0;
    REP(i, n) sum += a[3*n-i-1], pq2.push(a[3*n-i-1]);
    sum2[n] = sum; 
    REP(i, n){
        pq2.push(a[2*n-i-1]);
        sum += a[2*n-i-1];
        sum -= pq2.top();
        pq2.pop();
        sum2[n-i-1] = sum;
    }

    int ans = -INFL;
    REP(i, n+1) ans = max(ans, sum1[i] - sum2[i]);

    cout << ans << endl;
}
