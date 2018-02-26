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

struct Edge{
    int to;
    long long cost;
    Edge(int to, long long cost) : to(to), cost(cost) {}
};

class BellmanFord{
    private:
        long long INFl = (long long)1e15;
        int array_size_of_cost;
        int node_num;
        vector<vector<Edge>> adj; // adj[始点][動的配列で始点から伸びる枝]
        vector<bool> negative; // negative[n] := nに到達するまでに負閉路があるか

    public:
        BellmanFord(int n);
        vector<long long> dist; // 最短経路
        void add_edge(int f, int t, long long c);
        void run(int f);
        bool get_negative(int n);
};

BellmanFord::BellmanFord(int n):
    array_size_of_cost(n + 1),
    node_num(n),
    adj(vector<vector<Edge>>(array_size_of_cost)),
    negative(array_size_of_cost),
    dist(vector<long long>(array_size_of_cost))
{
    fill(dist.begin(), dist.end(), INFl);
    fill(negative.begin(), negative.end(), false);
}

void BellmanFord::add_edge(int f, int t, long long c){
    adj[f].push_back(Edge(t, c));
}

void BellmanFord::run(int first_node){
    dist[first_node] = 0;
    for(int loop = 0; loop < node_num - 1; loop++){
        for(int i = 0; i < node_num; i++){
            for(const Edge& e : adj[i]){
                if(dist[i] == INFl) continue;
                if(dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                }
            }
        }
    }

    for(int loop = 0; loop < node_num; loop++){
        for(int i = 0; i < node_num; i++){
            for(const Edge& e : adj[i]){
                if(dist[i] == INFl) continue;
                if(dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                    negative[e.to] = true;
                }
                if(negative[i] == true){
                    negative[e.to] = true;
                }
            }
        }
    }
}

bool BellmanFord::get_negative(int n){
    return negative[n];
}

/*************** using variables ***************/
int n, m;
vector<LL> a, b, c;
/**********************************************/

signed main(){
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    c.resize(m);
    
    BellmanFord bel(n);
    REP(i, m){
        cin >> a[i] >> b[i] >> c[i];
        bel.add_edge(a[i]-1, b[i]-1, -c[i]);
    }

    bel.run(0);
    if(bel.get_negative(n-1)){
        cout << "inf" << endl;    
    }
    else cout << -bel.dist[n-1] << endl;
}
