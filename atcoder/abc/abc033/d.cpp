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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];

    int ans1 = 0, ans2 = 0, ans3 = 0;
    REP(i, n) FOR(j, i+1, n) FOR(k, j+1, n){
        vector<double> dis(3);
        dis[0] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), 
        dis[1] = sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k])), 
        dis[2] = sqrt((x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i]));

        sort(all(dis));

        double s = (dis[0] + dis[1] + dis[2])/2;
        double S = sqrt(s * (s - dis[0]) * (s - dis[1]) * (s - dis[2]));
        double h = 2 * S / dis[2];
        double a, b = asin(h/dis[0])*360/2/M_PI, c = asin(h/dis[1])*360/2/M_PI;
        a = 180 - b - c;
        
        const double EPS = 1e-11;
        if(fabs(a - 90.0) <= EPS || fabs(b - 90.0) <= EPS || fabs(c - 90.0) <= EPS)
        {
            ans2++;
        }
        else if(90.0 - a >= EPS && 90.0 - a >= EPS && 90.0 - c >= EPS)
        {
            ans1++;
        }
        else
        {
            ans3++;
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
}