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

int n, m, l, k, a, h;
vector<vector<P>> graph;
vector<vector<int>> dist;
vector<bool> isFreeze;

void dijkstra(int firstNode) {
    using Tup = tuple<int, int, int>;
    priority_queue<Tup, vector<Tup>, greater<Tup>> pq;

    pq.push(make_tuple(0, firstNode, m));

    while (!pq.empty()) {
        int cost, currentEdge, t;
        tie(cost, currentEdge, t) = pq.top(); pq.pop();
        if (dist[currentEdge][t] < cost) continue;

        for (auto tmp : graph[currentEdge]) {
            int nextEdge = tmp.first, time = tmp.second;
            if(isFreeze[currentEdge]){
                for(int i = 0; i <= m; i++){
                    if(t + i > m) break;
                    if(t + i - time < 0) continue;
                    if(cost + i + time < dist[nextEdge][t + i - time]){
                        dist[nextEdge][t + i - time] = cost + i + time;
                        pq.push(make_tuple(dist[nextEdge][t + i - time], nextEdge, t + i - time));
                    }
                }
            }else{
                if(t - time < 0) continue;
                if(cost + time < dist[nextEdge][t - time]){
                    dist[nextEdge][t - time] = cost + time;
                    pq.push(make_tuple(dist[nextEdge][t - time], nextEdge, t - time));
                }
            }
        }
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1){
        cin >> n >> m >> l >> k >> a >> h;
        if(n+m+l+k+a+h == 0) break;
        dist.assign(105, vector<int>(105, INF));
        graph.resize(105);
        isFreeze.assign(105, false);
        REP(i, l){
            int x;
            cin >> x;
            isFreeze[x] = true;
        }
        REP(i, k){
            int x, y, t;
            cin >> x >> y >> t;
            graph[x].pb(P(y, t));
            graph[y].pb(P(x, t));
        }
        
        dijkstra(a);
        int ans = INF;
        REP(i, m+1) ans = min(ans, dist[h][i]);
        if(ans == INF) cout << "Help!" << endl;
        else cout << ans << endl;
        REP(i, 105) graph[i].erase(all(graph[i]));
    }
}
