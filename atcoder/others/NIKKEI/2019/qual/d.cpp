#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n-1+m), b(n-1+m);
    REP(i, n-1+m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    vector<vector<int>> graph(n), rg(n);
    vector<int> h(n, 0);
    REP(i, n-1+m){
        graph[a[i]].pb(b[i]);
        rg[b[i]].pb(a[i]);
        h[b[i]]++;
    }

    stack<int> st;
    REP(i, n){
        if(h[i] == 0) st.push(i);
    }

    vector<int> topo;
    while(st.size()){
        int i = st.top(); st.pop();
        topo.push_back(i);
        for(auto &j : graph[i]){
            h[j]--;
            if(h[j] == 0) st.push(j);
        }
    }
    map<int, int> mp;
    int cnt = 0;
    for(int i: topo) {
        //cout << i + 1 << endl;
        mp[i] = cnt;
        cnt++;
    }

    vector<int> ans(n);
    reverse(all(topo));
    for(int i: topo) {
        int num = -1, index = -1;
        for(auto &j : rg[i]){
            if(num < mp[j]){
                num = mp[j];
                index = j;
            }
            //cout << i+1 << " " << j+1 << " " << mp[j] << endl;
        }
        //cout << i+1 << " " << index+1 << endl;
        ans[i] = index+1;
    }
    REP(i, n) cout << ans[i] << endl;
}