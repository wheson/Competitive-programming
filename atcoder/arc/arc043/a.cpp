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
int n, a, b;
vector<double> s;
double p = 1, q;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    s.resize(n);
    REP(i, n) cin >> s[i];
    sort(all(s));
    // (s[n-1] - s[0])*p == b
    if(s[n-1] - s[0] > 0) p = (double)b/(s[n-1] - s[0]);
    else { cout << -1 << endl; return 0; }
    REP(i, n) s[i] *= p;
    double sum, ave;
    REP(i, n) sum += s[i];
    ave = sum/n;
    // a = ave + q;
    q = a - ave;
    
    REP(i, n) s[i] += q;
   
/*
    REP(i, n) cout << s[i] << " ";
    cout << endl;
*/
    printf("%.9f %.9f\n", p, q);
}
