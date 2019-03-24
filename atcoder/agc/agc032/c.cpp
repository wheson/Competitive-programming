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

vector<vector<int>> graph;
vector<int> zan;
void f(int cur, int pre)
{
    for(auto x: graph[cur])
    {
        if(x != pre && zan[x] > 0)
        {
            zan[x]--;
            f(x, cur);
        }
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    vector<int> inm(n, 0);
    REP(i, m)
    {
        inm[a[i]]++;
        inm[b[i]]++;
    }
    bool flag6 = false, flag = true;

    REP(i, n)
    {
        if(!flag6 && inm[i] == 6) flag6 = true;
        else if(inm[i] != 2) flag = false;
    }
    REP(i, n)
    {
        cout << i+1 << " " << inm[i] << endl;
    }

    if(!flag6 || !flag)
    {
        cout << (flag6 ? "yes": "no") << " " << (flag ? "yes": "no") << endl;
        cout << "No" << endl;
        return 0;
    }

    int index = 0;
    REP(i, n)
    {
        if(inm[i] == 6) index = i;
    }

    zan.assign(n, 1);
    zan[index] = 3;
    graph.resize(n);
    REP(i, m){
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    f(index, -1);
    REP(i, n)
    {
        cout << i+1 << " " << zan[i] << endl;
    }

    flag = true;
    REP(i, n) if(zan[i] != 0) flag = false;
    

    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}