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
 
/*************** using variables ***************/
int n, m, t;
vector<int> A;
/**********************************************/
 
typedef struct Edge{
    long long cost;
    int to;
    Edge(int t, long long c){
        cost = c;
        to = t;
    }
    bool const operator<(Edge e) const {
        return cost < e.cost;
    }
    bool const operator>(Edge e) const {
        return cost > e.cost;
    }
}Edge;

class Dijkstra{
    public:
        Dijkstra(int n, bool dir);
        int array_size_of_cost;
        int vertex_num; // 頂点数
        vector<long long> cost;
        vector<long long> route_history;
        void add_edge(int f, int t, long long c);
        bool has_path(int t); // tに至るパスはあるか
        void run(int f);
    private:
        bool is_non_dir = true; // 無向グラフ: true, 有向グラフ: false
        vector<vector<Edge>> adj; // adj[始点][動的配列で始点から伸びる枝]
};

Dijkstra::Dijkstra(int n, bool dir){
    is_non_dir = dir; 
    array_size_of_cost = n + 1;
    vertex_num = n;
    adj.resize(array_size_of_cost);
}

void Dijkstra::add_edge(int f, int t, long long c){
    adj[f].push_back(Edge(t, c));
    if(is_non_dir) adj[t].push_back(Edge(f, c));
}

bool Dijkstra::has_path(int t){
    return cost[t] != INF;
}

void Dijkstra::run(int first_node){
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    cost.resize(array_size_of_cost);
    fill(cost.begin(), cost.end(), INF);

    cost[first_node] = 0;
    pq.push(Edge(first_node, 0L));

    while(!pq.empty()){
        Edge current_node = pq.top();
        pq.pop();

        if(cost[current_node.to] < current_node.cost) continue;

        for(int i = 0; i < adj[current_node.to].size(); i++){
            Edge tmp = adj[current_node.to][i];

            long long sum_cost = current_node.cost + tmp.cost;
            if(cost[tmp.to] > sum_cost){
                cost[tmp.to] = sum_cost;
                pq.push(Edge(tmp.to, cost[tmp.to]));
            }
        }
    }
}

int main(){
    LL n, m, t;
    cin >> n >> m >> t;
    REP(i, n){LL x; cin >> x; A.pb(x);}
    Dijkstra dijkstra(n, false);
    Dijkstra reverse_dijkstra(n, false);
    
    REP(i, m){
        LL a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dijkstra.add_edge(a, b, c);
        reverse_dijkstra.add_edge(b, a, c);
    }
 
    dijkstra.run(0);
    reverse_dijkstra.run(0);
    LL ans = 0;
    
    REP(i, n){
        if(dijkstra.has_path(i) && reverse_dijkstra.has_path(i)){
            ans = max(A[i] * (t - dijkstra.cost[i] - reverse_dijkstra.cost[i]), ans);
        }
    }
    
    cout << ans << endl;
    
}
