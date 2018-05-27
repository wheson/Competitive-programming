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

template <typename T>
struct Edge {
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
class Dijkstra {
    private:
        T INF = numeric_limits<T>::max() / 10;
        int V;           // 頂点数
        AdjList<T> adj;  // adj[始点][動的配列で始点から伸びる枝]
        vector<int> prever;

    public:
        Dijkstra(int n);
        vector<T> cost;
        void AddEdge(int f, int t, int c);
        bool HasPath(int t);                 // tに至るパスはあるか
        vector<int> GetShortestPath(int t);  // tへの最短路
        void Run(int f);
};

template <typename T>
Dijkstra<T>::Dijkstra(int n) : 
    V(n + 1), adj(V), prever(vector<int>(V, -1)), cost(V)
{
    fill(cost.begin(), cost.end(), INF);
}

template <typename T>
void Dijkstra<T>::AddEdge(int f, int t, int c) {
    adj[f].push_back(Edge<T>(t, c));
}

template <typename T>
bool Dijkstra<T>::HasPath(int t) {
    return cost[t] != INF;
}

template <typename T>
vector<int> Dijkstra<T>::GetShortestPath(int t) {
    vector<int> path;
    for (; t != -1; t = prever[t]) path.push_back(t);

    reverse(path.begin(), path.end());
    return path;
}

template <typename T>
void Dijkstra<T>::Run(int firstNode) {
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;

    cost[firstNode] = 0;
    pq.push(Pi(cost[firstNode], firstNode));

    while (!pq.empty()) {
        Pi currentEdge = pq.top();
        pq.pop();
        if (cost[currentEdge.second] < currentEdge.first) continue;

        for (Edge<T> tmp : adj[currentEdge.second]) {
            T sumCost = currentEdge.first + tmp.cost;
            if (cost[tmp.to] > sumCost) {
                cost[tmp.to] = sumCost;
                prever[tmp.to] = currentEdge.second;
                pq.push(Pi(cost[tmp.to], tmp.to));
            }
        }
    }
}

/*************** using variables **************/
int n, q, k;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    Dijkstra<LL> dij(n);
    REP(i, n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dij.AddEdge(a, b, c);
        dij.AddEdge(b, a, c);
    }
    cin >> q >> k;
    k--;
    dij.Run(k);
    REP(i, q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dij.cost[x] + dij.cost[y] << endl;
    }
}
