#include <bits/stdc++.h>

//macro
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, n, m) for(int i = m; i < n; ++i)
#define LL long long

using namespace std;

typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;

int main(){
	int n;
	int a[1001];

	cin >> n;
	int max = 0, min = 1000;
	REP(i, n){
	int x; 
	cin >> x;

	if(max < x){ max = x;}
	if(min > x){ min = x;}

	}

	cout << max - min << endl;

	return 0;
}
