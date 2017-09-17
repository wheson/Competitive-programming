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
	int r, g, b;
	cin >> r >> g >> b;

	if(r*100+ g * 10 + b % 4 == 0){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;

	return 0;
}
