#include <bits/stdc++.h>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define LL long long
#define pb(a) push_back(a)
#define INF 999999999
#define MAX_NUM 100005
using namespace std;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

static const LL INFTY = (1<<21);

LL M[MAX_NUM][MAX_NUM];
LL

LL prim(LL n){
	int u, minv;
	int d[MAX_NUM], p[MAX_NUM], color[MAX_NUM];

	REP(i, n){
		d[i] = INFTY;
		p[i] = -1;
		color[i] = 0;
	}

	d[0] = 0;

	while(1){
		minv = INFTY;
		u = -1;
		REP(i, n){
			if(minv > d[i] && color[i] != 2){
				u = i;
				minv = d[i];
			}
		}
		if(u == -1) break;
		color[u] = 2;
		REP(v, n){
			if(color[v] != 2 && M[u][v] != INFTY){
				if(d[v] > M[u][v]){
					d[v] = M[u][v];
					p[v] = u;
					color[v] = 1;
				}
			}
		}
	}
	LL sum = 0;
	REP(i, n){
		if(p[i] != -1) sum += M[i][p[i]];
	}

	return sum;
}

int main(){
	LL n;
	LL x[MAX_NUM], y[MAX_NUM];

	cin >> n;
	REP(i, n){
		cin >> x[i] >> y[i];
	}
	
	REP(i, n){
		REP(j, n){
			M[i][j] = min(abs(x[i] - x[j]), abs(y[i] - y[j]));
		}
	}

	cout << prim(n) << endl;
}
