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
int n;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int p_i = 0, m_i = 0;
    REP(i, n) if(a[p_i] < a[i]) p_i = i;
    REP(i, n) if(a[m_i] > a[i]) m_i = i;
    
    cout << n*2-1 << endl;
    if(abs(a[p_i]) >= abs(a[m_i])){
        REP(i, n) if(i != p_i) cout << p_i+1 << " " << i+1 << endl;
        cout << p_i+1 << " " << p_i+1 << endl;
        REP(i, n-1) cout << i+1 << " " << i+2 << endl;
    }else{
        REP(i, n) if(i != m_i) cout << m_i+1 << " " << i+1 << endl;
        cout << m_i+1 << " " << m_i+1 << endl;
        REP(i, n-1) cout << n-i << " " << n-i-1 << endl;
    }
}
