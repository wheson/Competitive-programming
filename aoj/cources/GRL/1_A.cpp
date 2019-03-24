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

// 単一始点最短経路(ダイクストラ法)
// 時間計算量はO((V+E)logV)
// 使用例:
// Dijkstra<int> dij(N);
// dij.AddEdge(f, t, c);  <- fからtのコストcの辺を追加
// dij.Run(s);            <- s始点での最短経路長
// dij.cost[t]            <- Run()で求めた始点からtへの最短経路長を取得
// dij.HasPath(t)         <- Run()で求めた始点からtへのパスは存在するか
// dij.GetShortestPath(t) <- Run()で求めた始点からtへのパスを取得
template <typename T>
struct Edge
{
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
using Edges = vector<Edge<T>>;
template <typename T>
using AdjList = vector<Edges<T>>;

template <typename T>
class Dijkstra
{
  private:
    T INF = numeric_limits<T>::max() / 10;
    int V;
    AdjList<T> adj;
    vector<int> prever;

  public:
    Dijkstra(int n) : V(n + 1), adj(V), prever(vector<int>(V, -1)), cost(V, INF) {}
    vector<T> cost;
    void AddEdge(int f, int t, int c)
    {
        adj[f].push_back(Edge<T>(t, c));
    }
    bool HasPath(int t)
    {
        return cost[t] != INF;
    }
    vector<int> GetShortestPath(int t)
    {
        vector<int> path;
        for (; t != -1; t = prever[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
    void Run(int f)
    {
        cost.assign(V, INF);
        prever.assign(V, -1);

        using Pi = pair<T, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;

        cost[f] = 0;
        pq.push(Pi(cost[f], f));

        while (!pq.empty())
        {
            Pi currentEdge = pq.top();
            pq.pop();
            if (cost[currentEdge.second] < currentEdge.first) continue;

            for (Edge<T> tmp : adj[currentEdge.second])
            {
                T sumCost = currentEdge.first + tmp.cost;
                if (cost[tmp.to] > sumCost)
                {
                    cost[tmp.to] = sumCost;
                    prever[tmp.to] = currentEdge.second;
                    pq.push(Pi(cost[tmp.to], tmp.to));
                }
            }
        }
    }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int v, e, r;
    cin >> v >> e >> r;
    Dijkstra<LL> dij(v);
    REP(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        dij.AddEdge(s, t, d);
    }
    dij.Run(r);
    REP(i, v)
    {
        cout << (dij.HasPath(i) ? to_string(dij.cost[i]) : "INF") << endl;
    }
}