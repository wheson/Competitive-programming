#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int a, b, c, d, e;
set<int> st;
vector<int> vec;
/**********************************************/

signed main(){
    cin >> a >> b >> c >> d >> e;
    st.insert(e+d+c);
    st.insert(e+d+b);
    st.insert(e+d+a);
    st.insert(e+c+b);
    st.insert(e+c+a);
    st.insert(e+b+a);
    st.insert(d+c+b);
    st.insert(d+c+a);
    st.insert(d+b+a);
    st.insert(c+b+a);
    for(auto &s : st){
        vec.pb(s);
    }

    sort(all(vec), std::greater<int>());
    cout << vec[2] << endl;
}
