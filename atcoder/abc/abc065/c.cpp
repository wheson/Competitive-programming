#include <cctype>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define LL long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define MAX_NUM 1000000007
int main(){
	LL n, m;
	cin >> n >> m;

	if(abs(n - m) > 1){
		cout << 0 << endl;
		return 0;
	}
	LL inu = 1;
	LL saru = 1;
	LL ans;
	REP(i, n){
		inu = (inu * (i + 1)) % MAX_NUM; 
	}
	REP(i, m){
		saru = (saru * (i + 1)) % MAX_NUM;
	}
//	cout << inu << " " << saru << endl;
	if(abs(n - m) == 1){
		ans = inu * saru % MAX_NUM;
	}else{
		ans = inu * saru % MAX_NUM;
		ans = ans * 2 % MAX_NUM;
	}
	cout << ans << endl;
}
