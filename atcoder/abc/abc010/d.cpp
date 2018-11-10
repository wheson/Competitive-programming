#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int) 1e9;
const LL INFL = (LL) 1e18;
const int MOD = (int) 1e9 + 7;

template<typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<typename T>
using Edges = vector<Edge<T>>;
template<typename T>
using AdjList = vector<Edges<T>>;

template<typename T>
class Dinic {
private:
    int V;  // 頂点数
    vector<T> minCost;
    vector<int> iter;
    AdjList<T> graph;
    const T INF = numeric_limits<T>::max() / 10;

    bool Bfs(int s, int t);

    T Dfs(int idx, const int t, T flow);

public:
    explicit Dinic(int n);

    void AddEdge(int from, int to, T cost);

    T Run(int s, int t);
};

template<typename T>
Dinic<T>::Dinic(int n) : V(n), graph(n) {}

template<typename T>
void Dinic<T>::AddEdge(int from, int to, T cost) {
    graph[from].push_back(Edge<T>(static_cast<int>(graph[to].size()), to, cost));
    graph[to].push_back(
            Edge<T>(static_cast<int>(graph[from].size() - 1), from, 0));
}

template<typename T>
bool Dinic<T>::Bfs(int s, int t) {
    minCost.assign(graph.size(), -1);
    queue<int> que;
    minCost[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (auto &e : graph[p]) {
            if (e.cost > 0 && minCost[e.to] < 0) {
                minCost[e.to] = minCost[p] + 1;
                que.push(e.to);
            }
        }
    }
    return (minCost[t] != -1);
}

template<typename T>
T Dinic<T>::Dfs(int idx, const int t, T flow) {
    if (idx == t) return flow;
    for (int &i = iter[idx]; i < graph[idx].size(); ++i) {
        Edge<T> &e = graph[idx][i];
        if (e.cost > 0 && minCost[idx] < minCost[e.to]) {
            T d = Dfs(e.to, t, min(flow, e.cost));
            if (d > 0) {
                e.cost -= d;
                graph[e.to][e.from].cost += d;
                return d;
            }
        }
    }
    return 0;
}

template<typename T>
T Dinic<T>::Run(int s, int t) {
    T flow = 0;
    while (Bfs(s, t)) {
        iter.assign(graph.size(), 0);
        T f = 0;
        while ((f = Dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, g, e;
    cin >> n >> g >> e;
    vector<int> p(g);
    REP(i, g) cin >> p[i];

    Dinic<int> dinic(n + 1);

    REP(i, e) {
        int a, b;
        cin >> a >> b;

        if (b != 0) dinic.AddEdge(a, b, 1);
        if (a != 0) dinic.AddEdge(b, a, 1);
    }

    REP(i, g) {
        dinic.AddEdge(p[i], n, 1);
    }
    cout << dinic.Run(0, n) << endl;
}