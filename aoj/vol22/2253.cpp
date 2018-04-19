#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 1, -1};
int dx[]={1, -1, 0, 0, 1, -1};

//#define int long long

/*************** using variables ***************/
int t, n;
vector<int> x, y;
int graph[1000][1000];
bool close_graph[1000][1000];
/**********************************************/

void bfs(){
    deque<P> que;
    que.clear();
    que.push_back(P(y.back()+500, x.back()+500));
    int cnt = 1;
    while(!que.empty()){
        if(cnt > t) break;
        int qsize = que.size();
        REP(j, qsize){
            P cur = que.front();
            que.pop_front();
            REP(i, 6){
                if(!close_graph[cur.first + dy[i]][cur.second + dx[i]]){
                    que.push_back(P(cur.first + dy[i], cur.second + dx[i]));
                    close_graph[cur.first + dy[i]][cur.second + dx[i]] = true;
                    graph[cur.first + dy[i]][cur.second + dx[i]] = cnt;
                }
            }
        }
        cnt++;
    }
    int ans = 0;
    REP(i, 1000) REP(j, 1000) if(graph[i][j] != INF){
        //cout << i -31 << " " << j-31 << " " << graph[i][j] << endl;
        ans++;
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(cin >> t >> n, t != 0 || n != 0){
        x.resize(n+1);
        y.resize(n+1);
        REP(i, 1000) REP(j, 1000) close_graph[i][j] = false;
        REP(i, n+1) cin >> x[i] >> y[i];
        REP(i, 1000){
            REP(j, 1000){
                graph[i][j] = INF;
            }
        }
        REP(i, n){
            close_graph[500 + y[i]][500 + x[i]] = true;
        }
        graph[500 + y.back()][500 + x.back()] = 0;
        close_graph[500 + y.back()][500 + x.back()] = true;
        bfs();
    }
}
