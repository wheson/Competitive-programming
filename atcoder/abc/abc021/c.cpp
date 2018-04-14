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
#include <bitset>
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n, a, b, m;
LL ans = 1;
/**********************************************/
struct Edge{
    long long cost;
    int to;
    Edge(int t, long long c){
        cost = c;
        to = t;
    }
    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

class Dijkstra{
    private:
        bool is_dir = false; // 無向グラフ: false, 有向グラフ: true
        long long INFl = (long long)1e15;
        int array_size_of_cost;
        vector<vector<Edge>> adj; // adj[始点][動的配列で始点から伸びる枝]

    public:
        Dijkstra(int n, bool dir);
        vector<long long> cost;
        vector<int> prever;
        void add_edge(int f, int t, long long c);
        bool has_path(int t); // tに至るパスはあるか
        vector<int> get_shortest_path(int t);
        void run(int f);
};

Dijkstra::Dijkstra(int n, bool dir):
    is_dir(dir), 
    array_size_of_cost(n + 1),
    adj(vector<vector<Edge>>(array_size_of_cost)),
    cost(vector<long long>(array_size_of_cost)),
    prever(vector<int>(array_size_of_cost, -1))
{
    fill(cost.begin(), cost.end(), INFl);
}

void Dijkstra::add_edge(int f, int t, long long c){
    adj[f].push_back(Edge(t, c));
    if(!is_dir) adj[t].push_back(Edge(f, c));
}

bool Dijkstra::has_path(int t){
    return cost[t] != INFl;
}

vector<int> Dijkstra::get_shortest_path(int t){
    vector<int> path;
    for(; t != -1; t = prever[t]) path.push_back(t);

    reverse(path.begin(), path.end());
    return path;
}

void Dijkstra::run(int first_state){
    using State = Edge; 
    priority_queue<State, vector<State>, greater<State>> pq;

    cost[first_state] = 0;
    pq.push(Edge(first_state, 0LL));

    while(!pq.empty()){
        State current_state = pq.top();
        pq.pop();

        if(cost[current_state.to] < current_state.cost) continue;

        for(int i = 0; i < adj[current_state.to].size(); i++){
            State tmp = adj[current_state.to][i];

            long long sum_cost = current_state.cost + tmp.cost;
            if(cost[tmp.to] > sum_cost){
                cost[tmp.to] = sum_cost;
                prever[tmp.to] = current_state.to;
                pq.push(Edge(tmp.to, cost[tmp.to]));
            }
        }
    }
}

bool has_path[105][105];
LL dp[105];

signed main(){
    cin >> n >> a >> b >> m;
    Dijkstra dijkstra(n, false);
    
    REP(i, n){
        dp[i] = 0;
    }
    REP(i, m){
        int x, y;
        cin >> x >> y;
        has_path[x][y] = true;
        has_path[y][x] = true;
        dijkstra.add_edge(x, y, 1);
    }

    dijkstra.run(a);

    deque<int> que;
    que.push_back(a);
    int cur_dis = 0;
    dp[a] = 1;
    while(!que.empty()){
        int num = que.size();
        REP(i, num){
            int cur = que.front();
            que.pop_front();
            for(int i = 1; i <= n; i++){
                if(has_path[cur][i] && dijkstra.cost[i] == cur_dis+1){
                    bool flag = true;
                    for(auto x: que){
                        if(x == i) flag = false;
                    }
                    if(flag){
                        que.push_back(i);
                    }
                    dp[i] = dp[i] + dp[cur] % MOD;
                }
            }
        }
        cur_dis++;
    }
    
    cout << dp[b] << endl;
}
