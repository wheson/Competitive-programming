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
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define LL long long
#define pb(a) push_back(a)
#define INF 999999999
#define beginend(vec) (vec).begin(),(vec).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
vector<LL> sieveOfEratosthenes(int max) { LL prime; double sqrtmax = sqrt(max); vector<LL> primeVec, searchVec; FOR(i, 2, max + 1) searchVec.push_back(i); do { prime = searchVec[0]; primeVec.push_back(prime); auto itr = remove_if(beginend(searchVec), [=](LL x)->bool {return x%prime == 0; }); searchVec.erase(itr, searchVec.end()); } while (prime < sqrtmax); primeVec.reserve(primeVec.size() + searchVec.size()); primeVec.insert(primeVec.end(), beginend(searchVec)); return primeVec; }
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    
}
