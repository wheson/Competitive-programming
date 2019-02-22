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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    deque<int> ans;
    vector<bool> closed(n);
    ans.push_back(0);
    ans.push_back(adj[0][0]);
    closed[0] = true, closed[adj[0][0]] = true;

    while(true){
        bool flag1 = true, flag2 = true;
        for(auto child : adj[ans.front()]){
            if(!closed[child]) flag1 = false;
        }
        for(auto child : adj[ans.back()]){
            if(!closed[child]) flag2 = false;
        }
        if(flag1 && flag2) break;

        if(!flag1){
            for(auto child : adj[ans.front()]) {
                if (!closed[child]) {
                    ans.push_front(child);
                    closed[child] = true;
                    break;
                }
            }
        }
        if(!flag2){
            for(auto child : adj[ans.back()]) {
                if (!closed[child]) {
                    ans.push_back(child);
                    closed[child] = true;
                    break;
                }
            }
        }
    }
    int num = ans.size();
    cout << num << endl;
    REP(i, num){
        cout << ans.front() + 1 << " \n"[i == num-1];
        ans.pop_front();
    }
}