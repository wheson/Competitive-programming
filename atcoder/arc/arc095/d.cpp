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
/**********************************************/

LL combination(LL n, LL k)
{
  if(k < 0 || n < k) return (0);
  LL ret = 1;
  for(LL i = 1; i <= k; ++i) {
    ret *= n--;
    ret /= i;
  }
  return (ret);
}
class AbsDist
{
public:
  AbsDist(double ref) :_ref(ref){};
  bool operator() (int l, int r) const {
    return abs((double)l - _ref) < abs((double)r - _ref);
  }
private:
  double _ref;
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    sort(all(a));


    int max_num = a.back();
    a.pop_back();
    
    sort(all(a), AbsDist{(double)max_num/2.0});
    
    cout << max_num << " " << a[0] << endl;
}
